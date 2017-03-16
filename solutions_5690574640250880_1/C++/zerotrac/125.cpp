#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

#define maxlongint 2147483647
#define LL long long
#define pb push_back
#define mp make_pair

using namespace std;

int m,n,k,T,cs=0;

int main()
{
	freopen("123.in","r",stdin);
	freopen("123.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&m,&n,&k);
		printf("Case #%d:\n",++cs);
		int blank=m*n-k;
		if(m==1)
		{
			for(int i=1;i<=n;i++)if(i==1)printf("c");else if(i<=blank)printf(".");else printf("*");
			printf("\n");
			continue;
		}
		if(n==1)
		{
			for(int i=1;i<=m;i++)if(i==1)printf("c\n");else if(i<=blank)printf(".\n");else printf("*\n");
			continue;	
		}
		bool flag=false;
		for(int l=1;l<=n;l++)//枚举大的放几个 
		{
			int row=blank/l,s=blank%l;//row表示大的占了几行,s表示小的放几个 
			if((row>m) || (row==m && s))continue;
			bool add=false; 
			if((l==1 && row==1) || (l>1 && row>1 && !s) || (l>2 && row>1 && s>1) || (l>2 && row>2 && s==1))
			{
				flag=true;
				if(l>2 && row>2 && s==1)add=true;else add=false;
				for(int x=1;x<=m;x++)
				{
					for(int y=1;y<=n;y++)
						if(x==1 && y==1)
							printf("c");
						else if((x<row && y<=l) || (x==row && y<l) || (x==row && y==l && !add))
							printf(".");
						else if(x==row+1 && (y<=s || (y==s+1 && add)))
							printf(".");
						else
							printf("*");
					printf("\n");
				}
				break;
			}
		}
		if(!flag)printf("Impossible\n");
	}
	return 0;
}
