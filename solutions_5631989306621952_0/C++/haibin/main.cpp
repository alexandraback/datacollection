#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

string lastword(string s)
{
	string res;
	res.push_back(s[0]);
	for (size_t i = 1; i < s.size(); i++)
	{
		if (res[0] > s[i])
		{
			res.push_back(s[i]);
		}
		else
		{
			res = s[i] + res;
		}
	}
	return res;
}
int main()
{
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");
	string s;
	int count = 1;
	fin >> count;
	count = 1;
	while (fin >> s)
	{
		fout << "Case #" << count << ": " << lastword(s) << endl;
		count++;
	}
	return 0;
}