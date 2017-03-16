#include<iostream>
#include<cstdio>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cmath>

using namespace std;

#define maxn 1100
#define maxm 1100000
#define eps 1e-10
#define inf 1000000000

double mat[maxm];
int main()
{
	int i,j,t,ca,n;
	double x,y,sum,low,high,mid;
	scanf("%d",&t);
	for(ca=1;ca<=t;ca++)
	{
		printf("Case #%d:",ca);
		scanf("%d",&n);
		for(i=0,sum=0.0;i<n;i++)
		{
			scanf("%lf",&mat[i]);
			sum+=mat[i];
		}
		for(i=0;i<n;i++)
		{
			low=0.0;
			high=1.0;
			while(low+eps<high)
			{
				mid=(low+high)/2.0;
				x=mat[i]+mid*sum;
				y=1.0-mid;
				for(j=0;j<n;j++)
				{
					if(j==i)continue;
					if(mat[j]-x>-eps)continue;
					else
					{
						y-=(x-mat[j])/sum;
					}
				}
				if(y<-eps)high=mid;
				else low=mid;
			}
			printf(" %.6lf",high*100.0);
		}
		puts("");
	}
}
