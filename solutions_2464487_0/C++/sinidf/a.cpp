// File Name: a.cpp
// Author: gonewithsin
// Created Time: 2013/4/27 9:22:29

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
using namespace std;

int T;
long long r, t;

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.out","w",stdout);	
	int cnt = 0;
	scanf("%d", &T);
	while(T--)
	{
		cnt++;
		scanf("%I64d%I64d", &r, &t);
		double tmp = (1 - 2 * r) + sqrt( (2 * r - 1) * (2 * r - 1) + 4 * 2 * t );
		long long ans = tmp / 4;
		printf("Case #%d: %I64d\n", cnt, ans);
	}
    return 0;
}
