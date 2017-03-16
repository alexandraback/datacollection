/*
FileName:  A.cpp
Created:  2013年05月12日 17时02分48秒
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

int K;
char str[105];
bool vowel(char chr)
{
	if(chr=='a'||chr=='e'||chr=='i'||chr=='o'||chr=='u') return true;
	return false;
}
bool judge(int st,int ed)
{
	int cnt=0;
	for(int i=st;i<=ed;i++)
	{
		if(vowel(str[i])) 
		{
			if(cnt>=K) return true;
			cnt=0;
		}
		else cnt++;
	}
	if(cnt>=K) return true;
	return 0;
}
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A.out","w",stdout);
	int t,t_cnt=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%d",str,&K);

		int len=(int)strlen(str),ans=0;
		for(int i=0;i<len;i++)
		{
			for(int j=i;j<len;j++) 
			{
				if(judge(i,j)) ans++;
			}
		}
		printf("Case #%d: %d\n",++t_cnt,ans);
	}
	return 0;
}

