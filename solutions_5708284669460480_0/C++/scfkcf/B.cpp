#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define lc (k<<1)
#define rc ((k<<1)|1)
#define mi ((l+r)>>1)
#define fk puts("fuck!")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


char keyboard[133], target[133];
char type[133];
int k, l, s, mx, match;

int pan()
{
	int res=0;
	for(int i=0;i<=s-l;i++)
	{
		for(int j=0;j<l;j++)
		{
			if(type[i+j]!=target[j]) break;
			if(j==l-1) res++;
		}
	}
	return res;
}

void dfs(int p)
{
	if(p==s)
	{
		int res=pan();
		mx=max(res,mx);
		match+=res;
		return;
	}
	for(int i=0;i<k;i++)
	{
		type[p]=keyboard[i];
		dfs(p+1);
	}
}


int main()
{
	//freopen("in","r",stdin);///
	int cas;scanf("%d",&cas);
	for(int t=1;t<=cas;t++)
	{
		scanf("%d%d%d",&k,&l,&s);
		scanf("%s",keyboard);
		scanf("%s",target);
		mx=match=0;
		int sum=1;
		for(int i=1;i<=s;i++)
			sum*=k;
		dfs(0);
		double ans=(1.0*mx*sum-match)/1.0/sum;
		printf("Case #%d: %.7f\n",t,ans);
	}
	return 0;
}