#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:500000000") 
#include <functional>
#include <algorithm>
#include <iostream> 
#include <string.h> 
#include <stdlib.h>
#include <complex>
#include <sstream> 
#include <fstream>
#include <numeric>
#include <ctype.h> 
#include <stdio.h> 
#include <bitset>
#include <vector> 
#include <string> 
#include <math.h> 
#include <time.h> 
#include <queue> 
#include <stack> 
#include <list>
#include <map> 
#include <set> 
#define Int long long 
#define INF 0x3F3F3F3F 
#define eps 1e-9
using namespace std;

char str[11];
string G[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
string s;

void solve(int pos)
{
	if (pos > 0)
	{
		str[pos] = 0;
		string e;
		for (int i = 0; i < pos; i++)
			e += G[str[i] - '0'];
		if (e.size() == s.size())
		{
			sort(e.begin(), e.end());
			if (s == e)
			{
				puts(str);
				throw 1;
			}
		}
	}
	if (pos < 7)
	{
		for (char c = (pos ? str[pos - 1] : '0'); c <= '9'; c++)
		{
			str[pos] = c;
			solve(pos + 1);
		}
	}
}

int main()
{
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		cin >> s;
		sort(s.begin(), s.end());
		int i, j;
		printf("Case #%d: ", test);
		try 
		{
			solve(0);
		} 
		catch(int)
		{	
		}
	}
}