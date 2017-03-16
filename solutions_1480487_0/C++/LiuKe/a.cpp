#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int T,n;
double sum,avg;
double s[200],ans[200];
bool flag[200];

int main()
{
	scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		printf("Case #%d:",t);
		scanf("%d",&n);
		for (int i=0;i<n;i++)	scanf("%lf",&s[i]);
		
		memset(flag,0,sizeof(flag));
		memset(ans,0,sizeof(ans));
		bool done=false;
		sum=0;
		int m=n;
		for (int i=0;i<n;i++)	sum+=s[i];
		
		sum*=2;
		done=false;
		while (!done)
		{
			done=true;
			avg=sum/m;
			for (int i=0;i<n;i++)
				if (s[i]>avg-1e-8 && !flag[i])
				{
					done=false;
					flag[i]=true;
					m--;
					sum-=s[i];
				}
		}
		sum=0;
		for (int i=0;i<n;i++)	sum+=s[i];
		for (int i=0;i<n;i++)
			if (!flag[i])
				ans[i]=(avg-s[i])/sum*100;
	
		for (int i=0;i<n;i++)
			printf(" %.7f",ans[i]);
		printf("\n");
	}
	return 0;
}
	
			
