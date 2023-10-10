#include<iostream>
#include<string>
using namespace std;
class course {
private:
	const char* type;
	const char* name;
	int value;
	int price;
	int number;
	//static int sum;
public:
	int calcu_num() {
		number++;
	}
	/*
	int calcu_sum() {
		sum++;
	}
	*/
	void show() {
		cout << type << "  " << name << "  " << value<<"  " << price << "  " << number << endl;
	}
	int get_price() {
		return price;
	}
	int get_value() {
		return value;
	}
	int get_number() {
		return number;
	}
	const char * get_type() {
		return type;
	}
	const char * get_name() {
		return name;
	}
	void modify_price(int price1) {
		price = price1;
	}
	void modify_value(int value1) {
		value = value1;
	}
	void modify_number(int number1) {
		number = number1;
	}
	void modify_type(const char* type1) {
		type = type1;
	}
	void modify_name(const char* name1) {
		name = name1;
	}
	course() {
		value = 0;
		price = 0;
		number = 0;
		//sum = 0;
		type = NULL;
		name = NULL;
	}
	course(const char type1[20], const char name1[20], int value1,int price1) {
		//sum = 0;
		type = type1;
		name = name1;
		value = value1;
		number = 0;
		price = price1;
	}
	~course() {
		delete type;
		delete name;
	}
};
course course_array[5] = {
	course("学科基础","英语口语",4,200),
	course("学科基础","高等数学",2,200),
	course("学科基础","大学物理",1,200),
	course("学科基础","政治经济学",1,200),
	course("专业基础","程序设计",2,150)
	};
class student {
protected:
	char * name;
	char * stu_num;
	int fee;
	int value;
public:
	//初始化
	student() {
		name = NULL;
		stu_num = NULL;
		fee = 0;
		value = 0;
	}
	course array[10];//对象数组
	int clacu_fee() {
		for (int i = 0; i < 5; i++)
			fee = fee + array[i].get_price();
	}
	int clacu_value() {
		for (int i = 0; i < 5; i++) {
			value = value + array[i].get_value();
		}
	}
	void show_content() {
		cout << name << "  " << stu_num << "  " << "  "<< "  " << fee << "  " << value << endl;
		//for (int i = 0; i < 5; i++)
		//array[i].show();
	}
	void get_name(char *name1) {
		name = name1;
	}
	void get_stu_num(char *stu_num1) {
		stu_num = stu_num1;
	}
};
typedef class UGstudent :public student {
private:
	const char * tutor_name;
};
class QSstudent :public student {
private:
	const char * tutor_name[10];
};
struct studentUG {
	UGstudent* q;
	UGstudent first;
}*L;
void main() {
	cout << "请选择选课系统：" << "   " << "1.本科生选课系统：" << "    " << "2.研究生选课系统：" << endl;
	cout << "请输入数字：";
	int type;
	cin >> type;
	if (type == 1) {	
		for (int i = 0; i < 4; i++)
		{
			cout << i << "  ";
			course_array[i].show();
		}
		studentUG Node;
		L = &Node;
		Node.q = NULL;
		cout << "请输入姓名：";
		char* a = new char[10];
		cin >> a;
		Node.first.get_name(a);
		delete a;
		cout << "请输入学号：";
		char* b = new char[10];
		cin >> b;
		Node.first.get_stu_num(b);
		delete b;
		for (int i = 0; i < 5; i++) {
			int j = 0;
			cout << "请输入选择课程号：";
			cin >> j;
			Node.first.array[i].modify_price(Node.first.array[i].get_price());
			Node.first.array[i].modify_value(Node.first.array[i].get_value());
			Node.first.array[i].modify_type(Node.first.array[i].get_type());
			Node.first.array[i].modify_name(Node.first.array[i].get_name());
		}
		cout << "输入0显示已选择课程";
		int show=1;
		cin >> show;
		if (show == 0) {
			Node.first.show_content();
		}
	}
	else{

	};
}