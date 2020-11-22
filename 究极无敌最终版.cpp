#include<iostream>
#include<string>
#include<fstream>
#include<iomanip> 
#include <windows.h>
using namespace std;
static int count1 = 0;//静态全局变量负责读取
class Information_industry//信息产业类 
{
private:
	string place;//a
	int year;//b
	int linephone_user;//c
	int mobilephone_user;//d
	int internet_user;//e
	int investment;//f
	int telecommunication_revenue;//g
	int service_revenue;//h
	int produce_revenue;//i
public:
	Information_industry();//无参构造函数
	Information_industry(string a, int b, int c, int d, int e, int f, int g, int h, int i);//含参构造函数
	Information_industry(const Information_industry& array);//复制构造函数
	void Input();//输入函数 
	void search1(string a, int& x, int(&y)[100], int z);//利用地区进行查找
	void search2(int b, int& x, int(&y)[100], int z);//利用年份进行查找
	void search3(int c, int& x, int(&y)[100], int z);//利用固定电话用户数进行查找
	void search4(int d, int& x, int(&y)[100], int z);//利用移动电话用户数进行查找
	void search5(int e, int& x, int(&y)[100], int z);//利用互联网用户数进行查找
	void search6(int f, int& x, int(&y)[100], int z);//利用通信固定资产投入进行查找
	void search7(int g, int& x, int(&y)[100], int z);//利用通信业收入进行查找
	void search8(int h, int& x, int(&y)[100], int z);//利用信息服务收入进行查找
	void search9(int i, int& x, int(&y)[100], int z);//利用信息产品收入进行查找
	void decrease1();//利用地区删除
	void decrease2();//利用年份删除
	void decrease3();//利用固定电话用户数删除 
	void decrease4();//利用移动电话用户数删除
	void decrease5();//利用互联网用户数删除
	void decrease6();//利用通信固定资产投入删除
	void decrease7();//利用通信业收入删除
	void decrease8();//利用信息服务收入删除
	void decrease9();//利用信息产品收入删除
	void change1(string a);
	void change2(int b);//利用年份进行修改
	void change3(int c);//利用固定电话用户数进行修改
	void change4(int d);//利用移动电话用户数进行修改
	void change5(int e);//利用互联网用户数进行修改
	void change6(int f);//利用通信固定资产投入进行修改
	void change7(int g);//利用通信业收入进行修改
	void change8(int h);//利用信息服务收入进行修改
	void change9(int i);//利用信息产品收入进行修改
	void display();
	void save(string fname, Information_industry array[], int n);//保存文件，参数为：文件名，对象指针，记录的条数
	friend ostream& operator <<(ostream& out, Information_industry& inf); //友元重载运算符
	void show(Information_industry array[], int n);//显示类中所有数据成员
	friend void BubbleSort2(Information_industry* h, int len);//冒泡排序法对对象数组成员排序
	friend void BubbleSort3(Information_industry* h, int len);
	friend void BubbleSort4(Information_industry* h, int len);
	friend void BubbleSort5(Information_industry* h, int len);
	friend void BubbleSort6(Information_industry* h, int len);
	friend void BubbleSort7(Information_industry* h, int len);
	friend void BubbleSort8(Information_industry* h, int len);
	friend void BubbleSort9(Information_industry* h, int len);
	friend int JudgePlace(Information_industry* h, int k);
};
Information_industry::Information_industry()//不含参的构造函数 
{
	place = "未知";
	year = 0;
	linephone_user = 0;
	mobilephone_user = 0;
	internet_user = 0;
	investment = 0;
	telecommunication_revenue = 0;
	service_revenue = 0;
	produce_revenue = 0;
}
Information_industry::Information_industry(string a, int b, int c, int d, int e, int f, int g, int h, int i)//含参构造函数 
{
	place = a;
	year = b;
	linephone_user = c;
	mobilephone_user = d;
	internet_user = e;
	investment = f;
	telecommunication_revenue = g;
	service_revenue = h;
	produce_revenue = i;
}
Information_industry::Information_industry(const Information_industry& array)//复制构造函数 
{
	place = array.place;
	year = array.year;
	linephone_user = array.linephone_user;
	mobilephone_user = array.mobilephone_user;
	internet_user = array.internet_user;
	investment = array.investment;
	telecommunication_revenue = array.telecommunication_revenue;
	service_revenue = array.service_revenue;
	produce_revenue = array.produce_revenue;
}
void Information_industry::Input()//输入函数 
{
	cout << "请输入地区(全国34个省、直辖市、自治区和港澳台):" << endl;
	cin >> place;
	cout << "请输入年份:" << endl;
	cin >> year;
	cout << "请输入固定电话用户数:" << endl;
	cin >> linephone_user;
	cout << "请输入移动电话用户数:" << endl;
	cin >> mobilephone_user;
	cout << "请输入互联网用户数:" << endl;
	cin >> internet_user;
	cout << "请输入通信固定资产投入:" << endl;
	cin >> investment;
	cout << "请输入通信业收入:" << endl;
	cin >> telecommunication_revenue;
	cout << "请输入信息服务收入:" << endl;
	cin >> service_revenue;
	cout << "请输入信息产品收入:" << endl;
	cin >> produce_revenue;
}
int JudgePlace(Information_industry array[],int k)
{
	int i = 0;
	for (i; i < k; i++)
	{
		if (array[i].place == "未知")
		{
			return i+1;
			break;
		}
	}
}
void Information_industry::display()//输出函数 
{
	cout << place << "   " << year << "  " << setw(12) << linephone_user << setw(16) << mobilephone_user << setw(18) << internet_user << setw(14) << investment << setw(16) << telecommunication_revenue << setw(15) << service_revenue << setw(16) << produce_revenue << endl;
}
void Information_industry::decrease1()
{
	place = "未知";
}
void Information_industry::decrease2()
{
	year = 0;
}
void Information_industry::decrease3()
{
	linephone_user = 0;
}
void Information_industry::decrease4()
{
	mobilephone_user = 0;
}
void Information_industry::decrease5()
{
	internet_user = 0;
}
void Information_industry::decrease6()
{
	investment = 0;
}
void Information_industry::decrease7()
{
	telecommunication_revenue = 0;
}
void Information_industry::decrease8()
{
	service_revenue = 0;
}
void Information_industry::decrease9()
{
	produce_revenue = 0;
}
void Information_industry::change1(string a)
{
	place = a;
}
void Information_industry::change2(int b)
{
	year = b;
}
void Information_industry::change3(int c)
{
	linephone_user = c;
}
void Information_industry::change4(int d)
{
	mobilephone_user = d;
}
void Information_industry::change5(int e)
{
	internet_user = e;
}
void Information_industry::change6(int f)
{
	investment = f;
}
void Information_industry::change7(int g)
{
	telecommunication_revenue = g;
}
void Information_industry::change8(int h)
{
	service_revenue = h;
}
void Information_industry::change9(int i)
{
	produce_revenue = i;
}
void Information_industry::search1(string a, int& x, int(&y)[100], int z)//a为用户输入的数据，x为记录查找的条数（x为全局变量只初始化一次），y为记录下标的数组，z为下标
{
	if (place == a)
	{
		cout << " " << place << "   " << year << "  " << setw(12) << linephone_user << setw(16) << mobilephone_user << setw(18) << internet_user << setw(14) << investment << setw(16) << telecommunication_revenue << setw(15) << service_revenue << setw(16) << produce_revenue << endl;
		y[x] = z;
		x++;//每当数据相同时，x+1
	}
}
void Information_industry::search2(int b, int& x, int(&y)[100], int z)
{
	if (year == b)
	{
		cout << " " << place << "   " << year << "  " << setw(12) << linephone_user << setw(16) << mobilephone_user << setw(18) << internet_user << setw(14) << investment << setw(16) << telecommunication_revenue << setw(15) << service_revenue << setw(16) << produce_revenue << endl;
		y[x] = z;
		x++;
	}
}
void Information_industry::search3(int c, int& x, int(&y)[100], int z)
{
	if (linephone_user == c)
	{
		cout << " " << place << "   " << year << "  " << setw(12) << linephone_user << setw(16) << mobilephone_user << setw(18) << internet_user << setw(14) << investment << setw(16) << telecommunication_revenue << setw(15) << service_revenue << setw(16) << produce_revenue << endl;
		y[x] = z;
		x++;
	}

}
void Information_industry::search4(int d, int& x, int(&y)[100], int z)
{
	if (mobilephone_user == d)
	{
		cout << " " << place << "   " << year << "  " << setw(12) << linephone_user << setw(16) << mobilephone_user << setw(18) << internet_user << setw(14) << investment << setw(16) << telecommunication_revenue << setw(15) << service_revenue << setw(16) << produce_revenue << endl;
		y[x] = z;
		x++;
	}

}
void Information_industry::search5(int e, int& x, int(&y)[100], int z)
{
	if (internet_user == e)
	{
		cout << " " << place << "   " << year << "  " << setw(12) << linephone_user << setw(16) << mobilephone_user << setw(18) << internet_user << setw(14) << investment << setw(16) << telecommunication_revenue << setw(15) << service_revenue << setw(16) << produce_revenue << endl;
		y[x] = z;
		x++;
	}

}
void Information_industry::search6(int f, int& x, int(&y)[100], int z)
{
	if (investment == f)
	{
		cout << " " << place << "   " << year << "  " << setw(12) << linephone_user << setw(16) << mobilephone_user << setw(18) << internet_user << setw(14) << investment << setw(16) << telecommunication_revenue << setw(15) << service_revenue << setw(16) << produce_revenue << endl;
		y[x] = z;
		x++;
	}

}
void Information_industry::search7(int g, int& x, int(&y)[100], int z)
{
	if (telecommunication_revenue == g)
	{
		cout << " " << place << "   " << year << "  " << setw(12) << linephone_user << setw(16) << mobilephone_user << setw(18) << internet_user << setw(14) << investment << setw(16) << telecommunication_revenue << setw(15) << service_revenue << setw(16) << produce_revenue << endl;
		y[x] = z;
		x++;
	}

}
void Information_industry::search8(int h, int& x, int(&y)[100], int z)
{
	if (service_revenue == h)
	{
		cout << " " << place << "   " << year << "  " << setw(12) << linephone_user << setw(16) << mobilephone_user << setw(18) << internet_user << setw(14) << investment << setw(16) << telecommunication_revenue << setw(15) << service_revenue << setw(16) << produce_revenue << endl;
		y[x] = z;
		x++;
	}

}
void Information_industry::search9(int i, int& x, int(&y)[100], int z)
{
	if (produce_revenue == i)
	{
		cout << " " << place << "   " << year << "  " << setw(12) << linephone_user << setw(16) << mobilephone_user << setw(18) << internet_user << setw(14) << investment << setw(16) << telecommunication_revenue << setw(15) << service_revenue << setw(16) << produce_revenue << endl;
		y[x] = z;
		x++;
	}
}
void BubbleSort2(Information_industry array[], int len)
{
	int i, j;
	Information_industry xx[2];
	if (len <= 1) return;
	//i是次数，j是具体下标
	for (i = 0; i < len - 1; ++i)
		//for(int j=0;j<len-1-i;++j)
		for (j = len - 1; j > i; j--)
			if (array[j].year > array[j - 1].year)
			{
				xx[1] = array[j - 1];
				array[j - 1] = array[j];
				array[j] = xx[1];
			}

	return;
}
void BubbleSort3(Information_industry array[], int len)
{
	int i, j;
	Information_industry xx[2];
	if (len <= 1) return;
	//i是次数，j是具体下标
	for (i = 0; i < len - 1; ++i)
		//for(int j=0;j<len-1-i;++j)
		for (j = len - 1; j > i; j--)
			if (array[j].linephone_user > array[j - 1].linephone_user)
			{
				xx[1] = array[j - 1];
				array[j - 1] = array[j];
				array[j] = xx[1];
			}

	return;
}
void BubbleSort4(Information_industry array[], int len)
{
	int i, j;
	Information_industry xx[2];
	if (len <= 1) return;
	//i是次数，j是具体下标
	for (i = 0; i < len - 1; ++i)
		//for(int j=0;j<len-1-i;++j)
		for (j = len - 1; j > i; j--)
			if (array[j].mobilephone_user > array[j - 1].mobilephone_user)
			{
				xx[1] = array[j - 1];
				array[j - 1] = array[j];
				array[j] = xx[1];
			}

	return;
}
void BubbleSort5(Information_industry array[], int len)
{
	int i, j;
	Information_industry xx[2];
	if (len <= 1) return;
	//i是次数，j是具体下标
	for (i = 0; i < len - 1; ++i)
		//for(int j=0;j<len-1-i;++j)
		for (j = len - 1; j > i; j--)
			if (array[j].internet_user > array[j - 1].internet_user)
			{
				xx[1] = array[j - 1];
				array[j - 1] = array[j];
				array[j] = xx[1];
			}

	return;
}
void BubbleSort6(Information_industry array[], int len)
{
	int i, j;
	Information_industry xx[2];
	if (len <= 1) return;
	//i是次数，j是具体下标
	for (i = 0; i < len - 1; ++i)
		//for(int j=0;j<len-1-i;++j)
		for (j = len - 1; j > i; j--)
			if (array[j].investment > array[j - 1].investment)
			{
				xx[1] = array[j - 1];
				array[j - 1] = array[j];
				array[j] = xx[1];
			}

	return;
}
void BubbleSort7(Information_industry array[], int len)
{
	int i, j;
	Information_industry xx[2];
	if (len <= 1) return;
	//i是次数，j是具体下标
	for (i = 0; i < len - 1; ++i)
		//for(int j=0;j<len-1-i;++j)
		for (j = len - 1; j > i; j--)
			if (array[j].telecommunication_revenue > array[j - 1].telecommunication_revenue)
			{
				xx[1] = array[j - 1];
				array[j - 1] = array[j];
				array[j] = xx[1];
			}

	return;
}
void BubbleSort8(Information_industry array[], int len)
{
	int i, j;
	Information_industry xx[2];
	if (len <= 1) return;
	//i是次数，j是具体下标
	for (i = 0; i < len - 1; ++i)
		//for(int j=0;j<len-1-i;++j)
		for (j = len - 1; j > i; j--)
			if (array[j].service_revenue > array[j - 1].service_revenue)
			{
				xx[1] = array[j - 1];
				array[j - 1] = array[j];
				array[j] = xx[1];
			}

	return;
}
void BubbleSort9(Information_industry array[], int len)
{
	int i, j;
	Information_industry xx[2];
	if (len <= 1) return;
	//i是次数，j是具体下标
	for (i = 0; i < len - 1; ++i)
		//for(int j=0;j<len-1-i;++j)
		for (j = len - 1; j > i; j--)
			if (array[j].produce_revenue > array[j - 1].produce_revenue)
			{
				xx[1] = array[j - 1];
				array[j - 1] = array[j];
				array[j] = xx[1];
			}

	return;
}
void menu()//功能菜单
{
	system("color b4");
	cout << "====================================" << endl;
	cout << "欢迎使用信息产业发展统计系统" << endl;
	cout << "请选择您想使用的功能" << endl;
	cout << "1.新增信息产业发展数据条目" << endl;
	cout << "2.查找/修改/删除数据" << endl;
	cout << "3.显示信息产业发展数据列表" << endl;
	cout << "4.数据统计" << endl;
	cout << "5.保存信息产业发展数据列表到文件" << endl;
	cout << "6.显示文本中数据" << endl;
	cout << "7.退出" << endl;
	cout << "====================================" << endl;
	return;
}
ostream& operator <<(ostream& out, Information_industry& inf)//重载输出运算符
{
	out << inf.place << "   " << inf.year << "  " << setw(12) << inf.linephone_user << setw(16) << inf.mobilephone_user << setw(18) << inf.internet_user << setw(14) << inf.investment << setw(16) << inf.telecommunication_revenue << setw(15) << inf.service_revenue << setw(16) << inf.produce_revenue << endl;
	return out;
}

void save(string fname, Information_industry array[], int n)//保存数据至文件中
{
	ofstream fout(fname, ios::binary | ios::out);//打开二进制文件
	if (!fout)
	{
		cout << "open binary file error\n";
		return;
	}
	fout.write((char*)array, sizeof(Information_industry) * n);
	fout.close();
}
void read(string fname, Information_industry array[], int n)//从文件中读取数据
{
	ifstream fin(fname, ios::binary | ios::in);
	if (!fin)
	{
		cout << "open binary file error\n";
		return;
	}
	fin.read((char*)array, sizeof(Information_industry) * n);
	fin.close();
}
void show(Information_industry array[], int n)
{
	for (int i = 0; i < n; i++)
		cout << " " << array[i];
}
#include"Information_industry.h"
int main()
{
	system("cls");
	int choose1, choose2, choose3, choose4, x, j;// choose1~4为用户的选择按键
	int object[100] = { 0 };//确定找到的数据所在数组的下标 
	int object2[100] = { 0 };//存储找到的唯一数据的下标
	string a;//所输入的地区
	int b, c, d, e, f, g, h, i;
	int num = 0, num1 = 0;
	Information_industry array[100];
	while (1)
	{
		int k = 0, k2 = 0;
		int y = 0;
		menu();//功能菜单  
		cout << "请输入你要选择的功能键" << endl;
		cin >> choose1;
		switch (choose1)
		{
		case 1:
			cout << "请输入新增信息产业发展数据条目数量(小于100)" << endl;
			cin >> x;
			for (j = 0; j < x; j++)
			{
				cout << "====================================" << endl;
				cout << "请输入第" << j + 1 << "行数据" << endl;
				cout << "====================================" << endl;
				array[count1+num1].Input();
				count1++;
			}
			continue;
		case 2:
			cout << "====================================" << endl;
			cout << "请选择查找方式" << endl;
			cout << "1.按地区" << endl;
			cout << "2.按年份" << endl;
			cout << "3.按指标名称" << endl;
			cout << "4.返回" << endl;
			cout << "请输入你要选择的功能键" << endl;
			cin >> choose2;
			switch (choose2)
			{
			case 1:
				cout << "请输入想查找的地区:" << endl;
				cin >> a;
				cout << "============================================================================================================================" << endl;
				cout << " 地区 | 年份 | 固定电话用户数 | 移动电话用户数 | 互联网用户数 |通信固定资产投入|  通信业收入 | 信息服务收入 | 信息产品收入 |" << endl;
				for (j = 0; j < count1; j++)
				{
					array[j].search1(a, k, object, j);
				}
				cout << "找到" << k << "条数据" << endl;
				cout << "请问是否需要后续操作:" << endl;
				cout << "1.删除数据" << endl;
				cout << "2.修改数据" << endl;
				cout << "3.返回" << endl;
				cin >> choose4;
				if (k == 1)
				{
					switch (choose4)
					{
					case 1:
						array[object[0]].decrease1();
						cout << "数据已删除" << endl;
						continue;
					case 2:
						cout << "请输入修改后数据" << endl;
						cin >> a;
						array[object[0]].change1(a);
						cout << "数据已修改" << endl;
						continue;
					case 3:
						continue;
					}
				}
				else
				{
					switch (choose4)
					{
					case 1:
						cout << "找到多条记录，请继续输入年份:" << endl;
						cin >> b;
						for (j = 0; j < k; j++)
						{
							y = object[j];
							array[y].search2(b, k2, object2, y);
						}
						array[object2[0]].decrease1();
						cout << "数据已删除" << endl;
						continue;
					case 2:
						cout << "找到多条记录，请继续输入年份:" << endl;
						cin >> b;
						for (j = 0; j < k; j++)
						{
							y = object[j];
							array[y].search2(b, k2, object2, y);
						}
						cout << "已找到唯一数据" << endl;
						cout << "请输入修改后数据" << endl;
						cin >> a;
						array[object2[0]].change1(a);
						cout << "数据已修改" << endl;
						continue;
					case 3:
						continue;
					}
				}
				continue;
			case 2:
				cout << "请输入想查找的年份:" << endl;
				cin >> b;
				cout << "============================================================================================================================" << endl;
				cout << " 地区 | 年份 | 固定电话用户数 | 移动电话用户数 | 互联网用户数 |通信固定资产投入|  通信业收入 | 信息服务收入 | 信息产品收入 |" << endl;
				for (j = 0; j < count1; j++)
				{
					array[j].search2(b, k, object, j);
				}
				cout << "找到" << k << "条数据" << endl;
				cout << "请问是否需要后续操作:" << endl;
				cout << "1.删除数据" << endl;
				cout << "2.修改数据" << endl;
				cout << "3.返回" << endl;
				cin >> choose4;
				if (k == 1)
				{
					switch (choose4)
					{
					case 1:
						array[object[0]].decrease2();
						cout << "数据已删除" << endl;
						continue;
					case 2:
						cout << "请输入修改后数据" << endl;
						cin >> b;
						array[object[0]].change2(b);
						cout << "数据已修改" << endl;
						continue;
					case 3:
						continue;
					}
				}
				else
				{
					switch (choose4)
					{
					case 1:
						cout << "找到多条记录，请继续输入地区:" << endl;
						cin >> a;
						for (j = 0; j < k; j++)
						{
							y = object[j];
							array[y].search1(a, k2, object2, y);
						}
						array[object2[0]].decrease2();
						cout << "数据已删除" << endl;
						continue;
					case 2:
						cout << "找到多条记录，请继续输入地区:" << endl;
						cin >> a;
						for (j = 0; j < k; j++)
						{
							y = object[j];
							array[y].search1(a, k2, object2, y);
						}
						cout << "已确定唯一数据" << endl;
						cout << "请输入修改后数据" << endl;
						cin >> b;
						array[object2[0]].change2(b);
						cout << "数据已修改" << endl;
						continue;
					case 3:
						continue;
					}
				}
				continue;
			case 3:
				cout << "请输入想查询的指标:" << endl;
				cout << "1.固定电话用户数" << endl;
				cout << "2.移动电话用户数" << endl;
				cout << "3.互联网用户数" << endl;
				cout << "4.通信固定资产投入" << endl;
				cout << "5.通信业收入" << endl;
				cout << "6.信息服务收入" << endl;
				cout << "7.信息产品收入" << endl;
				cout << "请输入你要选择的功能键:" << endl;
				cin >> choose3;
				switch (choose3)
				{
				case 1:
					cout << "请输入想查找的数据:" << endl;
					cin >> c;
					cout << "============================================================================================================================" << endl;
					cout << " 地区 | 年份 | 固定电话用户数 | 移动电话用户数 | 互联网用户数 |通信固定资产投入|  通信业收入 | 信息服务收入 | 信息产品收入 |" << endl;
					for (j = 0; j < count1; j++)
					{
						array[j].search3(c, k, object, j);
					}
					cout << "找到" << k << "条数据" << endl;
					cout << "请问是否需要后续操作:" << endl;
					cout << "1.删除数据" << endl;
					cout << "2.修改数据" << endl;
					cout << "3.返回" << endl;
					cin >> choose4;
					if (k == 1)
					{
						switch (choose4)
						{
						case 1:
							array[object[0]].decrease3();
							cout << "数据已删除" << endl;
							continue;
						case 2:
							cout << "请输入修改后数据" << endl;
							cin >> c;
							array[object[0]].change3(c);
							cout << "数据已修改" << endl;
							continue;
						case 3:
							continue;
						}
					}
					else
					{
						switch (choose4)
						{
						case 1:
							cout << "找到多条记录，请继续输入地区:" << endl;
							cin >> a;
							for (j = 0; j < k; j++)
							{
								y = object[j];
								array[y].search1(a, k2, object2, y);
							}
							array[object2[0]].decrease3();
							cout << "数据已删除" << endl;
							continue;
						case 2:
							cout << "找到多条记录，请继续输入地区:" << endl;
							cin >> a;
							for (j = 0; j < k; j++)
							{
								y = object[j];
								array[y].search1(a, k2, object2, y);
							}
							cout << "已确定唯一数据" << endl;
							cout << "请输入修改后数据" << endl;
							cin >> c;
							array[object2[0]].change3(c);
							cout << "数据已修改" << endl;
							continue;
						case 3:
							continue;
						}
					}
					continue;
				case 2:
					cout << "请输入想查找的数据:" << endl;
					cin >> d;
					cout << "============================================================================================================================" << endl;
					cout << " 地区 | 年份 | 固定电话用户数 | 移动电话用户数 | 互联网用户数 |通信固定资产投入|  通信业收入 | 信息服务收入 | 信息产品收入 |" << endl;
					for (j = 0; j < count1; j++)
					{
						array[j].search4(d, k, object, j);
					}
					cout << "找到" << k << "条数据" << endl;
					cout << "请问是否需要后续操作:" << endl;
					cout << "1.删除数据" << endl;
					cout << "2.修改数据" << endl;
					cout << "3.返回" << endl;
					cin >> choose4;
					if (k == 1)
					{
						switch (choose4)
						{
						case 1:
							array[object[0]].decrease4();
							cout << "数据已删除" << endl;
							continue;
						case 2:
							cout << "请输入修改后数据" << endl;
							cin >> d;
							array[object[0]].change4(d);
							cout << "数据已修改" << endl;
							continue;
						case 3:
							continue;
						}
					}
					else
					{
						switch (choose4)
						{
						case 1:
							cout << "找到多条记录，请继续输入地区:" << endl;
							cin >> a;
							for (j = 0; j < k; j++)
							{
								y = object[j];
								array[y].search1(a, k2, object2, y);
							}
							array[object2[0]].decrease4();
							cout << "数据已删除" << endl;
							continue;
						case 2:
							cout << "找到多条记录，请继续输入地区:" << endl;
							cin >> a;
							for (j = 0; j < k; j++)
							{
								y = object[j];
								array[y].search1(a, k2, object2, y);
							}
							cout << "已确定唯一数据" << endl;
							cout << "请输入修改后数据" << endl;
							cin >> d;
							array[object2[0]].change4(d);
							cout << "数据已修改" << endl;
							continue;
						case 3:
							continue;
						}
					}
					continue;
				case 3:
					cout << "请输入想查找的数据:" << endl;
					cin >> e;
					cout << "============================================================================================================================" << endl;
					cout << " 地区 | 年份 | 固定电话用户数 | 移动电话用户数 | 互联网用户数 |通信固定资产投入|  通信业收入 | 信息服务收入 | 信息产品收入 |" << endl;
					for (j = 0; j < count1; j++)
					{
						array[j].search5(e, k, object, j);
					}
					cout << "找到" << k << "条数据" << endl;
					cout << "请问是否需要后续操作:" << endl;
					cout << "1.删除数据" << endl;
					cout << "2.修改数据" << endl;
					cout << "3.返回" << endl;
					cin >> choose4;
					if (k == 1)
					{
						switch (choose4)
						{
						case 1:
							array[object[0]].decrease5();
							cout << "数据已删除" << endl;
							continue;
						case 2:
							cout << "请输入修改后数据" << endl;
							cin >> e;
							array[object[0]].change5(e);
							cout << "数据已修改" << endl;
							continue;
						case 3:
							continue;
						}
					}
					else
					{
						switch (choose4)
						{
						case 1:
							cout << "找到多条记录，请继续输入地区:" << endl;
							cin >> a;
							for (j = 0; j < k; j++)
							{
								y = object[j];
								array[y].search1(a, k2, object2, y);
							}
							array[object2[0]].decrease5();
							cout << "数据已删除" << endl;
							continue;
						case 2:
							cout << "找到多条记录，请继续输入地区:" << endl;
							cin >> a;
							for (j = 0; j < k; j++)
							{
								y = object[j];
								array[y].search1(a, k2, object2, y);
							}
							cout << "已确定唯一数据" << endl;
							cout << "请输入修改后数据" << endl;
							cin >> e;
							array[object2[0]].change5(e);
							cout << "数据已修改" << endl;
							continue;
						case 3:
							continue;
						}
					}
					continue;
				case 4:
					cout << "请输入想查找的数据:" << endl;
					cin >> f;
					cout << "============================================================================================================================" << endl;
					cout << " 地区 | 年份 | 固定电话用户数 | 移动电话用户数 | 互联网用户数 |通信固定资产投入|  通信业收入 | 信息服务收入 | 信息产品收入 |" << endl;
					for (j = 0; j < count1; j++)
					{
						array[j].search6(f, k, object, j);
					}
					cout << "找到" << k << "条数据" << endl;
					cout << "请问是否需要后续操作:" << endl;
					cout << "1.删除数据" << endl;
					cout << "2.修改数据" << endl;
					cout << "3.返回" << endl;
					cin >> choose4;
					if (k == 1)
					{
						switch (choose4)
						{
						case 1:
							array[object[0]].decrease6();
							cout << "数据已删除" << endl;
							continue;
						case 2:
							cout << "请输入修改后数据" << endl;
							cin >> f;
							array[object[0]].change6(f);
							cout << "数据已修改" << endl;
							continue;
						case 3:
							continue;
						}
					}
					else
					{
						switch (choose4)
						{
						case 1:
							cout << "找到多条记录，请继续输入地区:" << endl;
							cin >> a;
							for (j = 0; j < k; j++)
							{
								y = object[j];
								array[y].search1(a, k2, object2, y);
							}
							array[object2[0]].decrease6();
							cout << "数据已删除" << endl;
							continue;
						case 2:
							cout << "找到多条记录，请继续输入地区:" << endl;
							cin >> a;
							for (j = 0; j < k; j++)
							{
								y = object[j];
								array[y].search1(a, k2, object2, y);
							}
							cout << "已确定唯一数据" << endl;
							cout << "请输入修改后数据" << endl;
							cin >> f;
							array[object2[0]].change6(f);
							cout << "数据已修改" << endl;
							continue;
						case 3:
							continue;
						}
					}
					continue;
				case 5:
					cout << "请输入想查找的数据:" << endl;
					cin >> g;
					cout << "============================================================================================================================" << endl;
					cout << " 地区 | 年份 | 固定电话用户数 | 移动电话用户数 | 互联网用户数 |通信固定资产投入|  通信业收入 | 信息服务收入 | 信息产品收入 |" << endl;
					for (j = 0; j < count1; j++)
					{
						array[j].search7(g, k, object, j);
					}
					cout << "找到" << k << "条数据" << endl;
					cout << "请问是否需要后续操作:" << endl;
					cout << "1.删除数据" << endl;
					cout << "2.修改数据" << endl;
					cout << "3.返回" << endl;
					cin >> choose4;
					if (k == 1)
					{
						switch (choose4)
						{
						case 1:
							array[object[0]].decrease7();
							cout << "数据已删除" << endl;
							continue;
						case 2:
							cout << "请输入修改后数据" << endl;
							cin >> g;
							array[object[0]].change7(g);
							cout << "数据已修改" << endl;
							continue;
						case 3:
							continue;
						}
					}
					else
					{
						switch (choose4)
						{
						case 1:
							cout << "找到多条记录，请继续输入地区:" << endl;
							cin >> a;
							for (j = 0; j < k; j++)
							{
								y = object[j];
								array[y].search1(a, k2, object2, y);
							}
							array[object2[0]].decrease7();
							cout << "数据已删除" << endl;
							continue;
						case 2:
							cout << "找到多条记录，请继续输入地区:" << endl;
							cin >> a;
							for (j = 0; j < k; j++)
							{
								y = object[j];
								array[y].search1(a, k2, object2, y);
							}
							cout << "已确定唯一数据" << endl;
							cout << "请输入修改后数据" << endl;
							cin >> g;
							array[object2[0]].change7(g);
							cout << "数据已修改" << endl;
							continue;
						case 3:
							continue;
						}
					}
					continue;
				case 6:
					cout << "请输入想查找的数据:" << endl;
					cin >> h;
					cout << "============================================================================================================================" << endl;
					cout << " 地区 | 年份 | 固定电话用户数 | 移动电话用户数 | 互联网用户数 |通信固定资产投入|  通信业收入 | 信息服务收入 | 信息产品收入 |" << endl;
					for (j = 0; j < count1; j++)
					{
						array[j].search8(h, k, object, j);
					}
					cout << "找到" << k << "条数据" << endl;
					cout << "请问是否需要后续操作:" << endl;
					cout << "1.删除数据" << endl;
					cout << "2.修改数据" << endl;
					cout << "3.返回" << endl;
					cin >> choose4;
					if (k == 1)
					{
						switch (choose4)
						{
						case 1:
							array[object[0]].decrease8();
							cout << "数据已删除" << endl;
							continue;
						case 2:
							cout << "请输入修改后数据" << endl;
							cin >> h;
							array[object[0]].change8(h);
							cout << "数据已修改" << endl;
							continue;
						case 3:
							continue;
						}
					}
					else
					{
						switch (choose4)
						{
						case 1:
							cout << "找到多条记录，请继续输入地区:" << endl;
							cin >> a;
							for (j = 0; j < k; j++)
							{
								y = object[j];
								array[y].search1(a, k2, object2, y);
							}
							array[object2[0]].decrease8();
							cout << "数据已删除" << endl;
							continue;
						case 2:
							cout << "找到多条记录，请继续输入地区:" << endl;
							cin >> a;
							for (j = 0; j < k; j++)
							{
								y = object[j];
								array[y].search1(a, k2, object2, y);
							}
							cout << "已确定唯一数据" << endl;
							cout << "请输入修改后数据" << endl;
							cin >> h;
							array[object2[0]].change8(h);
							cout << "数据已修改" << endl;
							continue;
						case 3:
							continue;
						}
					}
					continue;
				case 7:
					cout << "请输入想查找的数据:" << endl;
					cin >> i;
					cout << "============================================================================================================================" << endl;
					cout << " 地区 | 年份 | 固定电话用户数 | 移动电话用户数 | 互联网用户数 |通信固定资产投入|  通信业收入 | 信息服务收入 | 信息产品收入 |" << endl;
					for (j = 0; j < count1; j++)
					{
						array[j].search9(i, k, object, j);
					}
					cout << "找到" << k << "条数据" << endl;
					cout << "请问是否需要后续操作:" << endl;
					cout << "1.删除数据" << endl;
					cout << "2.修改数据" << endl;
					cout << "3.返回" << endl;
					cin >> choose4;
					if (k == 1)
					{
						switch (choose4)
						{
						case 1:
							array[object[0]].decrease9();
							cout << "数据已删除" << endl;
							continue;
						case 2:
							cout << "请输入修改后数据" << endl;
							cin >> i;
							array[object[0]].change9(i);
							cout << "数据已修改" << endl;
							continue;
						case 3:
							continue;
						}
					}
					else
					{
						switch (choose4)
						{
						case 1:
							cout << "找到多条记录，请继续输入地区:" << endl;
							cin >> a;
							for (j = 0; j < k; j++)
							{
								y = object[j];
								array[y].search1(a, k2, object2, y);
							}
							array[object2[0]].decrease9();
							cout << "数据已删除" << endl;
							continue;
						case 2:
							cout << "找到多条记录，请继续输入地区:" << endl;
							cin >> a;
							for (j = 0; j < k; j++)
							{
								y = object[j];
								array[y].search1(a, k2, object2, y);
							}
							cout << "已确定唯一数据" << endl;
							cout << "请输入修改后数据" << endl;
							cin >> i;
							array[object2[0]].change9(i);
							cout << "数据已修改" << endl;
							continue;
						case 3:
							continue;
						}
					}
					continue;
				}
				continue;
			case 4:
				continue;
			}
		case 3:
			cout << "请输入想要显示的数据数量:" << endl;
			cin >> num;
			cout << "============================================================================================================================" << endl;
			cout << " 地区 | 年份 | 固定电话用户数 | 移动电话用户数 | 互联网用户数 |通信固定资产投入|  通信业收入 | 信息服务收入 | 信息产品收入 |" << endl;
			//read("d:\\inf.dat", array, num);
			show(array, num);

			continue;
		case 4:
			cout << "请选择选择生成统计报表的类型" << endl;
			cout << "1.地区" << endl;
			cout << "2.年份" << endl;
			cout << "3.固定电话用户数" << endl;
			cout << "4.移动电话用户数" << endl;
			cout << "5.互联网用户数" << endl;
			cout << "6.通信固定资产投入" << endl;
			cout << "7.通信业收入" << endl;
			cout << "8.信息服务收入" << endl;
			cout << "9.信息产品收入" << endl;
			int choose5;
			cin >> choose5;
			cout << "请输入你的选项" << endl;
			switch (choose5)
			{
			case 1://查找地区
				cout << "请输入想查找的地区:" << endl;
				cin >> a;
				cout << "============================================================================================================================" << endl;
				cout << " 地区 | 年份 | 固定电话用户数 | 移动电话用户数 | 互联网用户数 |通信固定资产投入|  通信业收入 | 信息服务收入 | 信息产品收入 |" << endl;
				for (j = 0; j < count1; j++)
				{
					array[j].search1(a, k, object, j);
				}
				continue;
			case 2:
				cout << "排序结果为:" << endl;
				cout << "============================================================================================================================" << endl;
				cout << " 地区 | 年份 | 固定电话用户数 | 移动电话用户数 | 互联网用户数 |通信固定资产投入|  通信业收入 | 信息服务收入 | 信息产品收入 |" << endl;
				BubbleSort2(array, count1);
				for (int q = 0; q < count1; q++)
				{
					array[q].display();
				}
				continue;
			case 3:
				cout << "排序结果为:" << endl;
				cout << "============================================================================================================================" << endl;
				cout << " 地区 | 年份 | 固定电话用户数 | 移动电话用户数 | 互联网用户数 |通信固定资产投入|  通信业收入 | 信息服务收入 | 信息产品收入 |" << endl;
				BubbleSort3(array, count1);
				for (int q = 0; q < count1; q++)
				{
					array[q].display();
				}
				continue;
			case 4:
				cout << "排序结果为:" << endl;
				cout << "============================================================================================================================" << endl;
				cout << " 地区 | 年份 | 固定电话用户数 | 移动电话用户数 | 互联网用户数 |通信固定资产投入|  通信业收入 | 信息服务收入 | 信息产品收入 |" << endl;
				BubbleSort4(array, count1);
				for (int q = 0; q < count1; q++)
				{
					array[q].display();
				}
				continue;
			case 5:
				cout << "排序结果为:" << endl;
				cout << "============================================================================================================================" << endl;
				cout << " 地区 | 年份 | 固定电话用户数 | 移动电话用户数 | 互联网用户数 |通信固定资产投入|  通信业收入 | 信息服务收入 | 信息产品收入 |" << endl;
				BubbleSort5(array, count1);
				for (int q = 0; q < count1; q++)
				{
					array[q].display();
				}
				continue;
			case 6:
				cout << "排序结果为:" << endl;
				cout << "============================================================================================================================" << endl;
				cout << " 地区 | 年份 | 固定电话用户数 | 移动电话用户数 | 互联网用户数 |通信固定资产投入|  通信业收入 | 信息服务收入 | 信息产品收入 |" << endl;
				BubbleSort6(array, count1);
				for (int q = 0; q < count1; q++)
				{
					array[q].display();
				}
				continue;
			case 7:
				cout << "排序结果为:" << endl;
				cout << "============================================================================================================================" << endl;
				cout << " 地区 | 年份 | 固定电话用户数 | 移动电话用户数 | 互联网用户数 |通信固定资产投入|  通信业收入 | 信息服务收入 | 信息产品收入 |" << endl;
				BubbleSort7(array, count1);
				for (int q = 0; q < count1; q++)
				{
					array[q].display();
				}
				continue;
			case 8:
				cout << "排序结果为:" << endl;
				cout << "============================================================================================================================" << endl;
				cout << " 地区 | 年份 | 固定电话用户数 | 移动电话用户数 | 互联网用户数 |通信固定资产投入|  通信业收入 | 信息服务收入 | 信息产品收入 |" << endl;
				BubbleSort8(array, count1);
				for (int q = 0; q < count1; q++)
				{
					array[q].display();
				}
				continue;
			case 9:
				cout << "排序结果为:" << endl;
				cout << "============================================================================================================================" << endl;
				cout << " 地区 | 年份 | 固定电话用户数 | 移动电话用户数 | 互联网用户数 |通信固定资产投入|  通信业收入 | 信息服务收入 | 信息产品收入 |" << endl;
				BubbleSort9(array, count1);
				for (int q = 0; q < count1; q++)
				{
					array[q].display();
				}
				continue;
			}
			continue;

		case 5:
			save("d:\\inf.dat", array, count1);
			cout << "文件保存成功" << endl;
			continue;
		case 6:
			cout << "请输入想要显示的数据数量:" << endl;
			cin >> num1;
			cout << "============================================================================================================================" << endl;
			cout << " 地区 | 年份 | 固定电话用户数 | 移动电话用户数 | 互联网用户数 |通信固定资产投入|  通信业收入 | 信息服务收入 | 信息产品收入 |" << endl;
			read("d:\\inf.dat", array, num1);
			show(array, num1);
			if (JudgePlace(array,num1))
			{
				num1 = JudgePlace(array,num1)-1;
			}
			continue;
		case 7:
			cout << "欢迎下次使用" << endl;
			exit(0);
		default:
			cout << "请输入正确的选择\n" << endl;
			continue;
		}
	}
}