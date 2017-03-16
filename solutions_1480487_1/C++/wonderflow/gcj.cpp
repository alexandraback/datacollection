#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct node
{
	double x;
	int num;
}a[300];

bool cmp(node a,node b)
{
	return a.x<b.x;
}

bool vis[1000];

int main()
{
	int T,n;

	scanf("%d",&T);
	double sum;
	double ans[1000];
	for(int icas = 1;icas<=T;icas++)
	{
		sum = 0;
		int f = 0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&a[i].x);
			sum+=a[i].x;
			if(a[i].x == 0)f++ ;
			vis[i] = 0;
		}
	//	sort(a,a+n,cmp);
		int num = n;
		double ts = sum;
		for(int i=0;i<n;i++)
		{
			if(2.0/n<a[i].x/sum)
			{
				vis[i]=1;
				sum-=a[i].x;
				num--;
				ans[i] = 0;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(!vis[i])ans[i] = (ts+sum)/(ts*num)-a[i].x/ts;
		}
		printf("Case #%d:",icas);
		for(int i=0;i<n;i++)
		{
			printf(" %.6lf",ans[i]*100);
		}
		printf("\n");
	}
	return 0;
}

