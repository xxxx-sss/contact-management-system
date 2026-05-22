#include <iostream>
#include <string>
const int MAX = 1000;

//菜单界面
void showMenu() {
	std::cout << "**************************" << std::endl;
	std::cout << "*****  1.添加联系人  *****" << std::endl;
	std::cout << "*****  2.显示联系人  *****" << std::endl;
	std::cout << "*****  3.删除联系人  *****" << std::endl;
	std::cout << "*****  4.查找联系人  *****" << std::endl;
	std::cout << "*****  5.修改联系人  *****" << std::endl;
	std::cout << "*****  6.清空联系人  *****" << std::endl;
	std::cout << "*****  0.退出通讯录  *****" << std::endl;
	std::cout << "**************************" << std::endl;


}
//设计联系人类
class Person {
public:
	std::string m_Name;//姓名
	int m_Sex=0;//性别 1.男 2.女
	int m_Age=0;//年龄
	std::string m_Phone;//电话
	std::string m_Add;//地址
};

//设计通讯录类
class Addressbooks {
public:
	//通讯录中保存的联系人数组
	class Person personArray[MAX];
	//通讯录中当前记录联系人个数
	int m_Size;
};

//1.添加联系人
void addPerson(Addressbooks* abs) {
	if (abs->m_Size == MAX) {
		std::cout << "通讯录已满，无法添加!" << std::endl;
		return;
	}
	else {
		//添加具体联系人

		//姓名
		std::string name;
		std::cout << "请输入姓名:" << std::endl;
		std::cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		std::cout << "请输入性别:" << std::endl;
		std::cout << "1---男" << std::endl;
		std::cout << "2---女" << std::endl;
		int sex = 0;
		while (true) {
			std::cin >> sex;
			//如果输入1或2为正确值，如果输入其他数字为错误性别，进去死循环，需重新输入
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			std::cout << "输入有误，请重新输入" << std::endl;
		}
	
		//年龄
		std::cout << "请输入年龄:" << std::endl;
		int age=0;
		while (true) {
			std::cin >> age;
			if (age >= 0 && age <= 120) {
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			else {
				std::cout << "输入有误，请重新输入" << std::endl;
			}
		}

		//电话
		std::cout << "请输入电话:" << std::endl;
		std::string phone;
		std::cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		
		//地址
		std::cout << "请输入地址:" << std::endl;
		std::string add;
		std::cin >> add;
		abs->personArray[abs->m_Size].m_Add = add;

		//更新通讯录人数
		abs->m_Size++;

		std::cout << "添加成功" << std::endl;

		system("pause");//请按任意键继续
		system("cls");//清屏操作
	}
}

//2.显示联系人
void showPerson(Addressbooks* abs) {
	//判断通讯录中人是否为0，如果为0则显示为空
	if (abs->m_Size == 0) {
		std::cout << "通讯录中没有联系人" << std::endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			std::cout << "姓名:" << abs->personArray[i].m_Name << "\t";
			std::cout << "性别:" <<(abs->personArray[i].m_Sex == 1 ? "男" : "女" )<< "\t";
			std::cout << "年龄:" << abs->personArray[i].m_Age << "\t";
			std::cout << "电话:" << abs->personArray[i].m_Phone << "\t";
			std::cout << "地址:" << abs->personArray[i].m_Add << std::endl;
		}
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在，如果存在返回它在数组中所在位置，如果不存在返回-1
int isExist(Addressbooks* abs, std::string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;//找到要删除的联系人
		}
	}
	return -1;
}

//3.删除联系人(按照姓名删除联系人)
void deletePerson(Addressbooks* abs)
{
	std::cout << "请输入要删除的联系人的名字:" << std::endl;
	std::string name;
	std::cin >> name;
	int ret = isExist(abs, name);
	//ret=-1没查到,ret!=-1找到此人
	if (ret!=-1) {
		//查到此人，进行删除操作
		for (int i = ret; i < abs->m_Size; i++)
		{
			//前移操作（将想要删除的人被后面的人覆盖）
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//更新通讯录的人数
		std::cout << "删除成功" << std::endl;
	}
	else {
		std::cout << "查无此人" << std::endl;
	}
	system("pause");
	system("cls");
 }

//4.查找联系人
void findPerson(Addressbooks* abs) {
	std::cout << "请输入你要查找的联系人的名字:" << std::endl;
	std::string name;
	std::cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {//找到联系人
		std::cout << "姓名:" << abs->personArray[ret].m_Name << "\t";
		std::cout << "性别:" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		std::cout << "年龄:" << abs->personArray[ret].m_Age << "\t";
		std::cout << "电话:" << abs->personArray[ret].m_Phone << "\t";
		std::cout << "地址:" << abs->personArray[ret].m_Add<< std::endl;

	}
	else {
		std::cout << "查无此人" << std::endl;
	}
	system("pause");
	system("cls");
}

//5.修改联系人
void modifyPerson(Addressbooks* abs) {
	std::cout << "请输入你要修改的联系人的名字:" << std::endl;
	std::string name;
	std::cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		//姓名
		std::cout << "请修改姓名:" << std::endl;
		std::string name;
		std::cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		std::cout << "请修改性别:" << std::endl;
		std::cout << "1---男" << std::endl;
		std::cout << "2---女" << std::endl;
		int sex=0;
		while (true) {
			std::cin >> sex;
			//如果输入1或2为正确值，如果输入其他数字为错误性别，进去死循环，需重新输入
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			std::cout << "输入有误，请重新输入" << std::endl;
		}
		//年龄
		std::cout << "请修改年龄:" << std::endl;
		int age=0;
		while (true) {
			std::cin >> age;
			if (age >= 0 && age <= 120) {
				abs->personArray[ret].m_Age = age;
				break;
			}
			else {
				std::cout << "输入有误，请重新输入" << std::endl;
			}
		}
		//电话
		std::cout << "请修改电话:" << std::endl;
		std::string phone;
		std::cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//地址
		std::cout << "请修改地址:" << std::endl;
		std::string add;
		std::cin >> add;
		abs->personArray[ret].m_Add = add;
	}
	else {
		std::cout << "查无此人" << std::endl;
	}
	system("pause");
	system("cls");
}

//6.清空联系人
void cleanPerson(Addressbooks* abs) {
	std::cout << "确认是否清空通讯录" << std::endl;//防止误触将通讯录清楚
	std::cout << "1-----确认" << std::endl;
	std::cout << "2---不确认" << std::endl;
	int ret = 0;
		std::cin >> ret;
		if (ret == 1) {
			abs->m_Size = 0;//将当前记录联系人数量重置为0，做逻辑清空操作
			std::cout << "通讯录已清空" << std::endl;
		}
		else if (ret == 2) {
			std::cout << "通讯录未清空" << std::endl;
		}
	system("pause");
	system("cls");
}

int main() {
	int select = 0;//用户选择的功能

	//创建通讯录类变量
	Addressbooks abs;

	//初始化通讯录当前人员个数
	abs.m_Size = 0;
	while (true) {
		//菜单调用
		showMenu();

		std::cin >> select;

		switch (select) {
		case 1://1.添加联系人
			addPerson(&abs);
			break;

		case 2://2.显示联系人
			showPerson(&abs);
			break;

		case 3://3.删除联系人
			deletePerson(&abs);
			break;

		case 4://4.查找联系人
			findPerson(&abs);
			break;

		case 5://5.修改联系人
			modifyPerson(&abs);
			break;

		case 6://6.清空联系人
			cleanPerson(&abs);
			break;

		case 0://0.退出通讯录
			std::cout << "欢迎下次使用" << std::endl;
			system("pause");
			return 0;
			break;

		default:
			break;
		}
	}
	system("pause");
	return 0;

}