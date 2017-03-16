#include <iostream>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <deque>
#include <stack>
typedef long long ll;
using namespace std;
int an[105][105];
int bn[105][105];
int tag[105];
int cn[105];
int n,m;
bool check(int x){
	memset(bn,0,sizeof bn);
	for (int i=0;i<n;i++)
	{
		int xx=1;
		for (int j=0;j<m;j++)
		{
			if (an[i][j]>x)
			{
				xx=0;
				break;
			}
		}
		if (xx)
		{
			for (int j=0;j<m;j++)
			{
				bn[i][j]=1;
			}
		}
	}
	for (int i=0;i<m;i++)
	{
		int xx=1;
		for (int j=0;j<n;j++)
		{
			if (an[j][i]>x)
			{
				xx=0;
				break;
			}
		}
		if (xx)
		{
			for (int j=0;j<n;j++)
			{
				bn[j][i]=1;
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (an[i][j]<=x&&bn[i][j]==0)
			{
				return false;
			}
		}
	}
	return true;
}

int main(){
	int tt,cas=1;
	scanf("%d",&tt);
	while (tt--)
	{
		printf("Case #%d: ",cas++);
		scanf("%d%d",&n,&m);
		memset(tag,0,sizeof tag);
		int p=0;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				scanf("%d",&an[i][j]);
				if (tag[an[i][j]]==0)
				{
					tag[an[i][j]]=1;
					cn[p++]=an[i][j];
				}
			}
		}
		int ans=1;
		for (int i=0;i<p;i++)
		{
			if (check(cn[i])==false)
			{
				ans=0;
				break;
			}
		}
		if (ans)
		{
			printf("YES\n");
		}else printf("NO\n");
	}
	return 0;
}