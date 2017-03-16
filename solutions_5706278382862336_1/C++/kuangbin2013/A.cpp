/* ***********************************************
Author        :kuangbin
Created Time  :2014/5/11 16:55:46
File Name     :E:\2014ACM\±ÈÈü\2014_GCJ_R1C\A.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
long long gcd(long long a,long long b)
{
	if(b == 0)return a;
	else return gcd(b,a%b);
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    long long A,B;
	int T;
	int iCase = 0;
	scanf("%d",&T);
	while(T--)
	{
		iCase++;
		scanf("%I64d/%I64d",&A,&B);
		long long tt = gcd(A,B);
		A /= tt;
		B /= tt;
		long long tmp = B;
		while(tmp%2 == 0)tmp /= 2;
		if(tmp != 1)
		{
			printf("Case #%d: impossible\n",iCase);
			continue;
		}
		int cnt = 0;
		while(A < B)
		{
			B /= 2;
			cnt++;
		}
		printf("Case #%d: %d\n",iCase,cnt);
	}
    return 0;
}
