#include <iostream>
#include <fstream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<string>
#include<ctype.h>
using namespace std;
void main()
{
	int t, n, p=0, k, f, s, j, i, c, d, b, x, pos, sum;
	int m;
	int a[200];
	ifstream fin("input.txt", ios::in);
	ofstream fout("output.txt", ios::out);
	fin >> t;
	for (k = 1; k <= t; k++)
	{
		fin >> c >> d >> b;
		p = 0;
		for (j = 0; j < d; j++)
			fin >> a[j];
		if (a[0]!=1)
		{
		x = 1;
		pos = 0 ;
		for (i = d + 1; i > pos; --i)
			a[i] = a[i - 1];
		a[pos] = x;
		++p;
		++d;
	}
		sum = 0;
		for (m = 0; m <= d; m++)
		{
			sum += a[m];
			if (sum >= b)
				break;
			if (!(((sum + 1)*c) >= a[m + 1]))
			{
				x = sum + 1;
				pos = m + 1;
				for (i = d + 1; i>pos; --i)
					a[i] = a[i - 1];
				a[pos] = x;
				++p;
				++d;
			}
		}
		fout << "Case #" << k << ": " << p << endl;
	}
}