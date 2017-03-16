#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

string out1 = "", out2 = "";

void maxStr(string& str, int idx)
{
	for (int i = idx; i < str.length(); i++)
	{
		if (str[i] == '?') str[i] = '9';
	}
}

void minStr(string & str, int idx)
{
	for (int i = idx; i < str.length(); i++)
	{
		if (str[i] == '?') str[i] = '0';
	}
}

long long strToLL(string str)
{
	long long ret = 0;
	for (char c : str)
	{
		ret = ret * 10 + c - '0';
	}
	return ret;
}

long long dis(string str1, string str2)
{
	long long l1 = strToLL(str1);
	long long l2 = strToLL(str2);
	if (l1 >= l2) return l1 - l2;
	else return l2 - l1;
}

void solve(string & str1, string & str2, int idx)
{
	int len = str1.length();
	if (len == idx)
	{
		if (out1 == "" || \
			dis(str1, str2)< dis(out1, out2) || \
			dis(str1, str2) == dis(out1, out2) && out1>str1 || \
			dis(str1, str2) == dis(out1, out2) && out1 == str1 && out2>str2)
		{
			out1 = str1;
			out2 = str2;
		}
		return;
	}
	if (str1[idx] != '?' && str2[idx] != '?')
	{
		if (str1[idx] == str2[idx])
		{
			solve(str1, str2, idx + 1);
			return;
		}
		else if (str1[idx] < str2[idx])
		{
			maxStr(str1, idx + 1);
			minStr(str2, idx + 1);
			if (out1 == "" || \
				dis(str1, str2)< dis(out1, out2) || \
				dis(str1, str2) == dis(out1, out2) && out1>str1 || \
				dis(str1, str2) == dis(out1, out2) && out1 == str1 && out2>str2)
			{
				out1 = str1;
				out2 = str2;
			}
			return;
		}
		else
		{
			minStr(str1, idx + 1);
			maxStr(str2, idx + 1);
			if (out1 == "" || \
				dis(str1, str2)< dis(out1, out2) || \
				dis(str1, str2) == dis(out1, out2) && out1>str1 || \
				dis(str1, str2) == dis(out1, out2) && out1 == str1 && out2>str2)
			{
				out1 = str1;
				out2 = str2;
			}
			return;
		}
	}
	else if (str1[idx] == '?' && str2[idx] != '?')
	{
		string input1 = str1, input2 = str2;
		input1[idx] = input2[idx];
		solve(input1, input2, idx);
		if (str2[idx] != '0')
		{
			input1 = str1, input2 = str2;
			input1[idx] = input2[idx]-1;
			solve(input1, input2, idx);
		}
		if (str2[idx] != '9')
		{
			input1 = str1, input2 = str2;
			input1[idx] = input2[idx] + 1;
			solve(input1, input2, idx);
		}
	}
	else if (str1[idx] != '?' && str2[idx] == '?')
	{
		string input1 = str1, input2 = str2;
		input2[idx] = input1[idx];
		solve(input1, input2, idx);
		if (str1[idx] != '0')
		{
			input1 = str1, input2 = str2;
			input2[idx] = input1[idx] - 1;
			solve(input1, input2, idx);
		}
		if (str1[idx] != '9')
		{
			input1 = str1, input2 = str2;
			input2[idx] = input1[idx] + 1;
			solve(input1, input2, idx);
		}
	}
	else 
	{
		//0... 0...
		string input1 = str1, input2 = str2;
		input1[idx] = input2[idx] = '0';
		solve(input1, input2, idx);
		// 1... 0...
		{
			input1 = str1, input2 = str2;
			input1[idx] = '1';
			input2[idx] = '0';
			solve(input1, input2, idx);
		}
		// 0... 1...
		{
			input1 = str1, input2 = str2;
			input1[idx] = '0';
			input2[idx] = '1';
			solve(input1, input2, idx);
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cases = 1; cases <= T; cases++)
	{
		out1 = out2 = "";
		string input1, input2;
		cin >> input1 >> input2;
		solve(input1, input2, 0);
		cout << "Case #" << cases << ": " << out1 << " " << out2 << endl;
	}
	return 0;
}