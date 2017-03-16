#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;
int flip(string s, int cur)
{
	if (s[s.length() - 1] == '+')
	{
		int i=s.find_last_of('-');
		if (i<0) return cur;
		s=s.substr(0,i+1);
	}
	if (s[0] == '+')
	{
		cur++;
		for (int i = 0; i < s.length();i++)
			if (s[i] == '+') s[i] = '-'; else break;
	}
	string ss = "";
	for (int i = 0; i < s.length();i++)
	if (s[i] == '-') ss = '+' + ss; else ss = '-' + ss;
	return flip(ss,cur+1);
}
int main()
{
	ifstream fin;
	fin.open("B-small-attempt0.in");
	if (fin.is_open())
	{
		ofstream fout;
		fout.open("B-small-attempt0.out");
		int T;
		fin >> T;
		string s;
		getline(fin, s);
		for (int i = 0; i < T; i++)
		{
			getline(fin,s);
			int res = flip(s,0);
				cout << "Case #" << i + 1 << ": " << res << endl;
				fout << "Case #" << i + 1 << ": " << res << endl;
		}
		fin.close();
		fout.close();
	}
	return 0;
}