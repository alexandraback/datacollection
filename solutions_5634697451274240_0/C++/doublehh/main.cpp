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
	mp.clear();
	n = strlen(s);
	q.push(s);
	mp[s] = 0;
	while (!q.empty()) {
		string str = q.front(); q.pop();
		int x = mp[str];
		for (int i = 1; i <= n; i++) {
			reverse(str.begin(), str.begin() + i);
			for (int j = 0; j < i; j++)
				str[j] = '+' + '-' - str[j];
			if (!mp.count(str)) {
				mp[str] = x + 1;
				q.push(str);
			}
			for (int j = 0; j < i; j++)
				str[j] = '+' + '-' - str[j];
			reverse(str.begin(), str.begin() + i);
		}
	}
	for (int i = 0; i < n; i++)
		s[i] = '+';
	return mp[s];
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
