#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
#define maxn 101010
#define LL long long
int n,m;
long long e,r;
long long v[maxn];
long long nex[maxn];
int main()
{
	int ncase,i,j,tt=0;
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	scanf("%d",&ncase);
	while(ncase--)
	{
		scanf("%lld %lld",&e,&r);
		scanf("%d",&n);
		for(i=0;i<n;++i)
			scanf("%lld",&v[i]);
		v[n]=100000000;
		nex[n]=n;
		for(i=n-1;i>=0;--i){
			for(j=i+1;v[j]<=v[i];j=nex[j]);
			nex[i]=j;
		}
		LL cur,x,y,ans=0;
		cur=e;
		for(i=0;i<n;i++)
		{
			LL tmp;
			if(nex[i]==n) tmp=cur;
			else
			{
				x=r*(nex[i]-i);
				tmp=min(cur+x-e,cur);
			}
			if(tmp>0)
				ans+=tmp*v[i],cur-=tmp;
			cur+=r;
			cur=min(cur,e);
		}
		printf("Case #%d: %lld\n",++tt,ans);
	}
}