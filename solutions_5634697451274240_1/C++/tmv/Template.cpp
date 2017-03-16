//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

static void HandleCase(const int cse)
{
	string str;
	cin >> str;

	int i;
	for (i = 0; ; ++i)
	{
		if (str[0] == '+')
		{
			size_t pos = str.find_first_of('-');
			if (pos == -1)
				break;
			for (int j = 0; j < pos; ++j)
				str[j] = '-';
		}
		else
		{
			size_t pos = str.find_last_of('-');
			string newStr(str);
			for (int j = 0; j <= pos; ++j)
				newStr[pos - j] = (str[j] == '+') ? '-' : '+';
			str = newStr;
		}
	}

	cout << "Case #" << cse << ": " << i << endl;
}


int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
		HandleCase(i + 1);

	return 0;
}


