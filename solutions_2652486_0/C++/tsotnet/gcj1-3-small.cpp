#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#define INF 1000000007
#define EPS 0.000000001
using namespace std;

int r,n,m,k,i,j,p,q;
int a[111][6];
int b[6];

int main()
{
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	scanf("%*d%d%d%d%d",&r,&n,&m,&k);
	printf("Case #1:\n");
	for(i=0;i<r;i++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(j=0;j<k;j++)
		{
			scanf("%d",&p);
			for(q=2;q<=5;q++)
				while(p%q==0)
				{
					p/=q;
					a[j][q]++;
				}
			b[2] = max(b[2],a[j][2]);
			b[3] = max(b[3],a[j][3]);
			b[5] = max(b[5],a[j][5]);
		}
		if(b[2] == 0)
		{
			while(b[3]+b[5]<n)
			{
				b[3]++;
				if(b[3]+b[5]<n && m>=5) b[5]++;
			}
		} else
		if(b[2]+b[3]+b[4]+b[5]>n)
		{
			while(b[2]+b[3]+b[4]+b[5]>n && b[2]>1)
			{
				b[2]-=2;
				b[4]+=1;
			}
		} else
		if(b[2]+b[3]+b[4]+b[5]<n)
		{
			while(b[2]+b[3]+b[4]+b[5]<n)
			{
				b[2]++;
				if(b[2]+b[3]+b[4]+b[5]<n) b[3]++;
				if(b[2]+b[3]+b[4]+b[5]<n && m>=5) b[5]++;
			}
		}
		for(j=0;j<=m;j++)
			while(b[j])
			{
				printf("%d",j);
				b[j]--;
			}
		printf("\n");
	}
	return 0;
}