//============================================================================
// Name        : Problem.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int count (string s)
{
	if (s[s.size()-1] == '+')
	{
		int l = s.size()-1;
		for (; l>= 0 && s[l] == '+'; --l);

		if (l == -1)
			return 0;
		else
			return count(s.substr(0, l+1));
	}
	else
	{
		if(s[0] == '+')
		{
			for (int i = 0; s[i] == '+' && i < s.size(); ++i)
				s[i] = '-';
			return 1 + count(s);
		}
		else
		{
			reverse(s.begin(), s.end());
			for (int i = 0; i < s.size(); ++i)
				s[i] = s[i]=='+'?'-':'+';
			return 1 + count(s);
		}
	}
}

int main()
{
	// open a file in read mode.
	ifstream infile;
//	infile.open("src/in");
	infile.open("src/B-small-attempt0.in");

	// open a file in write mode.
	ofstream outfile;
	outfile.open("src/out");

	int T;
	infile>>T;
	for (int i = 1; i <= T; ++i)
	{
		string s;
		infile>>s;
		outfile<<"Case #"<<i<<": "<<count(s)<<endl;
	}
	return 0;
}
