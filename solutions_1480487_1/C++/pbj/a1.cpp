#include <iostream>
#include <cstring>
#include <cstdio>
#define N 500
using namespace std;
int t,n,judge[N],sum;
double des;
double ans[N];
int main()
{
	int i,j;
	double p[N];
//	freopen("d:\\gcj\\A1-large.in","r",stdin);
//	freopen("d:\\gcj\\A1-large.out","w",stdout);
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		memset(ans,0,sizeof(ans));
		sum=0;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&judge[j]);
			sum+=judge[j];
		}
		printf("Case #%d:",i);
		des=sum*2.0;
		int m=n;
		for(j=0;j<n;j++)
		{
			/*if(des>judge[j])
				ans[j]=100*(des-judge[j])*1.0/sum;
			else
				ans[j]=0;
			printf(" %.6lf",ans[j]);*/
			if(des/n<judge[j])
			{
				des-=judge[j];
				m--;
			}
		}
		des/=m;
		//cout<<"des="<<des<<endl;
		for(j=0;j<n;j++)
		{
			if(des<judge[j])
				ans[j]=0;
			else
				ans[j]=100*(des-judge[j])*1.0/sum;
			printf(" %.6lf",ans[j]);
		}
		puts("");
	}
	return 0;
}