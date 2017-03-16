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

int ar[105][105];
int n,m;
bool bi[105][105],mark[105],cut[105][105][105];

int main()
{
	//freopen("0.in","r",stdin);
	//freopen("/home/fahimzubaer/Desktop/B-large.in","r",stdin);
	//freopen("/home/fahimzubaer/Desktop/0.out","w",stdout);
	//freopen("0.out","w",stdout);
	
	int t;
	
	scanf("%d",&t);
	
	int a,b,c,d,z;
	
	for(int i=1;i<=t;i++)
	{
		scanf("%d %d",&n,&m);
		for(a=0;a<n;a++)
		{
			for(b=0;b<m;b++) bi[a][b]=0;
		}
		
		for(a=1;a<=100;a++)
		{
			 mark[a]=0;
			 for(b=0;b<n;b++)
			 {
				 for(c=0;c<m;c++)
				 {
					 cut[a][b][c]=0;
				 }
			 }
		}
		
		for(a=0;a<n;a++)
		{
			for(b=0;b<m;b++)
			{
				 scanf("%d",&ar[a][b]);
				 mark[ar[a][b]]=1;
			}
		 }
		
		for(c=100;c>=1;c--)
		{
			if(!mark[c]) continue;
			
			for(a=0;a<n;a++)
			{
				for(b=0;b<m;b++)
				{
					if(ar[a][b]>c) break;
				}
				if(b==m) for(b=0;b<m;b++) cut[c][a][b]=1;
			}
	    }
	    
		for(c=100;c>=1;c--)
		{
			if(!mark[c]) continue;
			
			for(a=0;a<m;a++)
			{
				for(b=0;b<n;b++)
				{
					if(ar[b][a]>c) break;
				}
				if(b==n) for(b=0;b<n;b++) cut[c][b][a]=1;
			}
	    }
	    
	    
		
		c=0;
		
		for(a=0;a<n;a++)
		{
			for(b=0;b<m;b++)
			{
				d=ar[a][b];
				if(!cut[d][a][b]) c++;
			}
		}
		
		if(c) printf("Case #%d: NO\n",i);
		else printf("Case #%d: YES\n",i);
	}
	
	return 0;
	
}
