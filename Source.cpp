#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
using namespace std;

int Count(const char* s)
{
	int k = 0;
	for (int i = 0; s[i] != '\0'; i++)
		if  ( s[i]=='+'|| s[i]=='-'|| s[i]=='=')
			k++;
	return k;
}

char* Change(char* str)
{
	size_t len = strlen(str);
	if (len < 3)
		return str;
	char* tmp = new char[len * 4 / 3 + 1];
	char* t = tmp;
	tmp[0] = '\0';
	size_t i = 0;

		while (str[i] != 0)
		{
			if (str[i] == '+' && str[i + 1] == '+' || str[i] == '-' && str[i + 1] == '-' || str[i] == '=' && str[i + 1] == '=')
			{
				strcat(t,"***");
				t += 3;
				i += 2;
			}
			else
			{
				*t++ = str[i++];
				*t = '\0';
			}
		}
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';
	strcpy(str, tmp);
	return tmp;
}



int main()	
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	char s[101];
	cout << "Введіть ваш рядок " << endl;
	cin.getline(s, 100);
	cout << "Кількісь входжень  " << endl;
	cout << Count(s) << endl;
	
	char* dest = new char[151];
	dest = Change(s);

	cout << "Modified string (param) : " << s << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;

}