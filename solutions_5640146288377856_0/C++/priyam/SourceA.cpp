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
	int t, n, p, k, f, s, j, i, r, c;
	ifstream fin("input.txt", ios::in);
	ofstream fout("output.txt", ios::out);
	fin >> t;
	for (i = 1; i <= t; i++)
	{
		p = 0;
		fin >> r >> c >> s;
		k = c / s;
		f = c%s;
		p += k*r;
		if (f == 0)
			p += s - 1;
		else
			p += s;
		fout << "Case #" << i << ": " << p << endl;
	}
}