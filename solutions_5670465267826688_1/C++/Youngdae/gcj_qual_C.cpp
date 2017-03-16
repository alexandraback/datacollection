#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("C-large.in");
ofstream fout("output.txt");

int table[5][5]={
	{0,0,0,0,0},
	{0,1,2,3,4},
	{0,2,-1,4,-3},
	{0,3,-4,-1,2},
	{0,4,3,-2,-1}};

int m(int a, int b)
{
	int neg=1;

	if(a<0)
	{
		a = -a;
		neg = -1;
	}

	if(b<0)
	{
		b = -b;
		neg *= -1;
	}

	return table[a][b]*neg;
}

		string str;

int main()
{
	int tt, ti;
	fin >> tt;

	for(ti=1; ti<=tt; ti++)
	{
		fout << "Case #" << ti << ": ";
		
		int l, s[10000];
		long long xx;

		fin >> l >> xx >> str;

		for(int i=0; i<l; i++)
		{
			if(str[i]=='i')
				s[i] = 2;
			else if(str[i]=='j')
				s[i] = 3;
			else if(str[i]=='k')
				s[i] = 4;
		}

		if(xx>11)
			xx = (xx%4)+8;

		int x = int(xx);

		int i, mul=1;
		bool ii=false, kk=false;

		for(i=0; i<l*x; i++)
		{
			mul = m(mul,s[i%l]);

			if(mul==2)
			{
				ii = true;
				break;
			}
		}

		for(i++; i<l*x; i++)
		{
			mul = m(mul,s[i%l]);

			if(mul==4)
			{
				kk = true;
				break;
			}
		}

		for(i++; i<l*x; i++)
			mul = m(mul,s[i%l]);

		if(ii && kk && mul==-1)
			fout << "YES" << endl;
		else
			fout << "NO" << endl;
	}

	return 0;
}