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

int main()
{
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		string s;
		cin >> s;
		vector<int> cnt(128);
		string res;

		auto Do = [&](int i)
		{
			res += i + '0';
			for (auto c : G[i])
				cnt[c]--;
		};

		for (auto c : s)
			cnt[c]++;
		while (cnt['Z'])
			Do(0);
		while (cnt['W'])
			Do(2);
		while (cnt['X'])
			Do(6);
		while (cnt['U'])
			Do(4);
		while (cnt['G'])
			Do(8);
		while (cnt['O'])
			Do(1);
		while (cnt['F'])
			Do(5);
		while (cnt['T'])
			Do(3);
		while (cnt['S'])
			Do(7);
		while (cnt['N'])
			Do(9);
		sort(res.begin(), res.end());
		printf("Case #%d: %s\n", test, res.c_str());
	}
}

/*
"ZERO" - Z
"TWO" - W
"SIX" - X
"FOUR" - U
"EIGHT" - G
"ONE" - O
"FIVE" - F
"THREE" - T
"SEVEN" - S
"NINE"

, , , , , ,  };
*/