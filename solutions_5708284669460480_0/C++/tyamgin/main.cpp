#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:500000000") 
#include <functional>
#include <algorithm> 
#include <iostream> 
#include <string.h> 
#include <stdlib.h>
#include <limits.h>
#include <numeric>
#include <sstream> 
#include <fstream>
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
typedef pair<int, int> pii;

int pi[1111];

int Count(string &ins, string &tar)
{
	string s = tar + '@' + ins;
	int n = (int)s.length();
	for (int i = 1; i < n; i++) 
	{
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])  
			j++;
		pi[i] = j;
	}
	return count(pi + tar.length() + 1, pi + s.length(), tar.length());
}

double solve()
{
	int K, L, S;
	string kb, tar;
	cin >> K >> L >> S >> kb >> tar;
	string s(S, 'a');
	Int maxCnt = 0,
		sum = 0,
		cnt = 0;
	function<void(int)> rec = [&](int st)
	{
		if (st == S)
		{
			Int c = Count(s, tar);
			maxCnt = max(maxCnt, c);
			sum += c;
			cnt++;
			return;
		}
		for (int i = 0; i < K; i++)
		{
			s[st] = kb[i];
			rec(st + 1);
		}
	};
	rec(0);
	return maxCnt - sum * 1.0 / cnt;
}

int main()
{
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
		printf("Case #%d: %.9lf\n", test, solve());
}