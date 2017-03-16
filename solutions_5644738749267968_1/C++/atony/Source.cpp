#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 1001;
const int MAXM = 2000011;
const int MAXK = 201;
const int INF = 1000000001;
const double eps = 1e-5;

double a[MAXN];
double b[MAXN];
char mark[MAXN];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int cas,T,n,i,j,head,tail,ans1,ans2;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf",&a[i]);
		for(i=0;i<n;i++)
			scanf("%lf",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		head=0; tail=n-1;
		ans1=0;
		for(i=0;i<n;i++)
		{
			if(a[i]>b[head])
			{
				ans1++;
				head++;
			}
			else
			{
				tail--;
			}
		}
		ans2=0;
		for(j=0;j<n;j++)
			mark[j]=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				if(mark[j]==0&&b[j]>a[i])
				{
					mark[j]=1;
					break;
				}
			if(j==n)
			{
				for(j=0;j<n;j++)
					if(mark[j]==0)
					{
						mark[j]=1;
						ans2++;
						break;
					}
			}
		}
		printf("Case #%d: %d %d\n",cas,ans1,ans2);
	}
	return 0;
	
}