/*
 * test.cpp
 *
 *  Created on: 2013-05-12
 *      Author: fudq
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;
#define N 1000010
#define LL long long
char str[N];
int len,n,f[N];
char p[] = "aeiou";

bool jud(char a)
{
	for (int i = 0; i < 5; i++)
		if (a == p[i])
			return false;
	return true;
}

LL make()
{
	len = strlen(str);
	if (n > len)
		return 0;
	int temp = -1;
	if (jud(str[0]))
		f[0] = 1;
	else f[0] = 0;
	int i = 1;
	while (i < len && f[i - 1] < n)
	{
		if (jud(str[i]))
			f[i] = f[i - 1] + 1;
		else
			f[i] = 0;
		i++;
	}
	if (f[i - 1] < n)
		return 0;
	temp = i - n;
	LL res = temp + 1;
	for (; i < len; i++)
	{
		if (jud(str[i]))
			f[i] = f[i - 1] + 1;
		else
			f[i] = 0;
		if (f[i] >= n)
			temp = i - n + 1;
		res += temp + 1;
	}
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("A-large.in","r",stdin);
    freopen("testout.txt","w",stdout);
#endif
	int T,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ", cas++);
		scanf("%s%d",str,&n);
		printf("%I64d\n", make());
	}
	return 0;
}
