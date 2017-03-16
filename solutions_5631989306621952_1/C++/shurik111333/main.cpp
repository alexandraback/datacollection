#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("in.in");
ofstream fout("out.txt");


int main(int argc, char *argv[])
{
	int t;
	fin >> t;
	vector<char> res;
	for (int q = 0; q < t; q++)
	{
		string s;
		fin >> s;
		res.clear();
		res.push_back(s[0]);
		fout << "Case #" << q + 1 << ": ";
		for (int i = 1; i < s.length(); i++)
		{
			if (s[i] >= res[0])
				res.insert(res.begin(), s[i]);
			if (s[i] < res[0])
				res.push_back(s[i]);
		}
		for (char c : res)
			fout << c;
		fout << endl;
	}
	return 0;
}
