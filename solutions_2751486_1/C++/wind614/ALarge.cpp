/*
FileName:  ALarge.cpp
Created:  2013年05月12日 17时24分27秒
Author:  shiqi_614
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;
const int N=1e6+5;

int K;
char str[N];

bool vowel(char chr)
{
	if(chr=='a'||chr=='e'||chr=='i'||chr=='o'||chr=='u') return true;
	return false;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("ALarge.out","w",stdout);

	int t,t_cnt=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%d",str,&K);

		int len=(int)strlen(str);

		LL ans=0;

		int cnt=0,lft=0,rht=-1;
		while(rht<=len)
		{
			if(cnt>=K) 
			{
				ans+=(LL)(len-rht);
				lft++;

				if(rht-lft+1<K) cnt--;
			}
			else 
			{
				if(vowel(str[++rht])==0) cnt++;
				else cnt=0;
			}
		}
		printf("Case #%d: %lld\n",++t_cnt,ans);
	}
	return 0;
}

