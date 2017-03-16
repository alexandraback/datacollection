/*
*   Copyright (C) 2016 All rights reserved.
*   
*   filename: main.cpp
*   author: doublehh
*   e-mail: sserdoublehh@foxmail.com
*   create time: 2016-04-05 11:04:36
*   last modified: 2016-04-05 11:04:36
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int n;
char s[101];
map<string, int> mp;
queue<string> q;

int solve()
{
	int ret = 0;
	n = strlen(s);
	char target = '+';
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == target) continue;
		ret++;
		target = '+' + '-' - target;
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf("%s", s);
		printf("Case #%d: %d\n", i, solve());
	}
}
