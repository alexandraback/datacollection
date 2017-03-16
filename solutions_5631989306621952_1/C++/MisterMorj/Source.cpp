#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include <limits>
#include <set>

using namespace std;

string new_str;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string new_str = "";
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			if (new_str.length() == 0)
				new_str += s[j];
			else
				if (s[j] >= new_str[0])
					new_str = s[j] + new_str;
				else
					new_str += s[j];
		}
		cout << "Case #" << i + 1 << ": " << new_str << endl;
	}

}