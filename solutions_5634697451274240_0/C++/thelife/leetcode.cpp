// leetcode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Example program
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>

using namespace std;

int compute(string s, int end, char tsign)
{
	if (end<0)
		return 0;
	int p = end-1;
	char last = s[end];
	while (p>=0)
	{
		if (s[p] == last)
			p--;
		else
			break;
	}
	if (last == tsign)
		return compute(s,p,last);
	else
		return compute(s,p,last)+1;
}

int main()
{
    ifstream infile("B-small-attempt0.in");
	ofstream outfile;//("OUTPUT.txt");
	outfile.open("OUTPUT.txt");
	long long t,n;
	int arr[10];
    int count = 0;
	infile>>t;
	string s;
	for (int i=0; i<t; i++)
	{   
		infile>>s;
		cout<<s<<endl;
		outfile<<"Case #"<<i+1<<": "<<compute(s,s.length()-1,'+')<<endl;
	}
	infile.close();
	outfile.close();
	return 0;
}

