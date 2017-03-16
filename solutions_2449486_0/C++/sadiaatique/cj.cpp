#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int ar[20][20];
int n,m;
bool bi[20][20];

int main()
{
	//freopen("0.in","r",stdin);
	//freopen("/home/fahimzubaer/Desktop/B-small-attempt0.in","r",stdin);
	//freopen("/home/fahimzubaer/Desktop/0.out","w",stdout);
	
	int t;
	
	scanf("%d",&t);
	
	int a,b,c;
	
	for(int i=1;i<=t;i++)
	{
		scanf("%d %d",&n,&m);
		for(a=0;a<n;a++) for(b=0;b<m;b++) scanf("%d",&ar[a][b]);
		for(a=0;a<n;a++) for(b=0;b<m;b++) bi[a][b]=0;
		
		for(a=0;a<n;a++)
		{
			for(b=0;b<m;b++)
			{
				if(ar[a][b]!=1) break;
			}
			if(b==m) for(b=0;b<m;b++) bi[a][b]=1;
		}
		
		for(a=0;a<m;a++)
		{
			for(b=0;b<n;b++)
			{
				if(ar[b][a]!=1) break;
			}
			if(b==n) for(b=0;b<n;b++) bi[b][a]=1;
		}
		
		c=0;
		
		for(a=0;a<n;a++)
		{
			for(b=0;b<m;b++) if(ar[a][b]==1 && bi[a][b]==0) c++;
		}
		
		if(c) printf("Case #%d: NO\n",i);
		else printf("Case #%d: YES\n",i);
	}
	
	return 0;
	
}
