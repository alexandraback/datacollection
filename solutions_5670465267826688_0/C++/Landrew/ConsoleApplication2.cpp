#include "stdafx.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stdio.h>

#include <math.h>

using namespace std;

ofstream fout("OUT111.txt");
ifstream fin("INP111.txt");

string M[10];

//FILE* pFile;
//int c;
//pFile = fopen("ou.txt","w");
//pFile=fopen ("beads.txt","r");

string mul(string a, string b)
{
	string res = "  ";
	int sign = 1;
	if (a[0] != b[0])
		sign = -1;
	if (a[1] == '1')
		res[1] = b[1];
	else if (b[1] == '1')
		res[1] = a[1];
	else if (a[1] == 'i')
	{
		switch (b[1])
		{
		  case 'i':
			  res[1] = '1';
			  sign = -1 * sign;
			  break;
		  case 'j':
			  res[1] = 'k';
			  break;
		  case 'k':
			  res[1] = 'j';
			  sign = -1 * sign;
			  break;
		}
	}
	else if (a[1] == 'j')
	{
		switch (b[1])
		{
		case 'i':
			res[1] = 'k';
			sign = -1 * sign;
			break;
		case 'j':
			res[1] = '1';
			sign = -1 * sign;
			break;
		case 'k':
			res[1] = 'i';
			break;
		}
	}
	else if (a[1] == 'k')
	{
		switch (b[1])
		{
		case 'i':
			res[1] = 'j';
			break;
		case 'j':
			res[1] = 'i';
			sign = -1 * sign;
			break;
		case 'k':
			res[1] = '1';
			sign = -1 * sign;
			break;
		}
	}

	if (sign == -1)
		res[0] = '-';
	else
		res[0] = '+';

	return res;
}

string convChar(char c)
{
	string res = "+ ";
	res[1] = c;
	return res;
}

int compperi(int n, string s)
{
	string cur = "+1";
	for (int i = 0; i < n; i++)
		cur = mul(cur, convChar(s[i]));
	M[0] = cur;
	bool found = false;
	int peri = 1;
	while (!found)
	{
		cur = mul(cur, M[0]);
		for (int i = 0; i < peri; i++)
		{
			if (M[i] == cur)
				found = true;
		}
		if (!found)
		{
			M[peri] = cur;
			peri++;
		}
	}

	return peri;
}

bool checko(int l, int x, string s)
{
	int peri = compperi(l, s);

	int ind1 = 0, ind2 = 0;
	string cur = "+1";

	bool found = false;
	while (!found)
	{
		cur = mul(cur, convChar(s[ind1]));
		if (cur == "+i")
			found = true;
		else if (ind1 < l-1)
			ind1++;
		else if (ind2 < peri-1 && ind2 < x-1)
		{
			ind1 = 0;
			ind2++;
		}
		else
			return false;
	}

	int ind3 = 0;
	found = false;
	cur = "+1";
	if (ind1 < l - 1)
	{
		ind1++;
		ind3 = -1;
	}
	else if (ind2 < x - 1)
	{
		ind1 = 0;
		ind2++;
	}
	else
		return false;

	while (!found)
	{
		cur = mul(cur, convChar(s[ind1]));
		if (cur == "+j")
			found = true;
		else if (ind1 < l - 1)
			ind1++;
		else if (ind3 < peri - 1 && ind2 < x - 1)
		{
			ind1 = 0;
			ind2++;
			ind3++;
		}
		else
			return false;
	}

	int ind4 = 0;
	found = false;
	cur = "+1";
	if (ind1 < l - 1)
	{
		ind1++;
		ind4 = -1;
	}
	else if (ind2 < x - 1)
	{
		ind1 = 0;
		ind2++;
	}
	else
		return false;

	while (!found)
	{
		cur = mul(cur, convChar(s[ind1]));
		if (cur == "+k")
			found = true;
		else if (ind1 < l - 1)
			ind1++;
		else if (ind4 < peri - 1 && ind2 < x - 1)
		{
			ind1 = 0;
			ind2++;
			ind4++;
		}
		else
			return false;
	}

	cur = "+1";
	for (int i = ind1 + 1; i < l; i++)
		cur = mul(cur, convChar(s[i]));
	int rem = x - ind2 - 1;
	if (rem > peri)
		cur = mul(cur, M[peri - 1]);

	rem = rem%peri;
	if (rem > 0)
		cur = mul(cur, M[rem - 1]);

	if (cur == "+1")
		return true;
	else
		return false;
}

int main() {

	//FILE* pFile;
	//pFile = fopen("ou.txt","w");

	// string na;
	// if (tt == 0)
	//  getline(fin,na);

	// getline(fin,na);

	// istringstream sin(na); 
	// string v; 
	// while (sin>>v) 
	//   names.push_back(v); 

	//fprintf(pFile, "Case #%d: ", t+1);
	//fprintf(pFile,"%d\n",res);

	int TT;
	fin >> TT;

	for (int tt = 0; tt<TT; tt++)
	{
		int l, x;
		string s;

		fin >> l >> x;
		fin >> s;

		if (checko(l, x, s))
		    fout << "Case #" << tt + 1 << ": " << "YES" << endl;
		else
			fout << "Case #" << tt + 1 << ": " << "NO" << endl;
	}

	return 0;
}

