#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

long long int dp[10006],dv[10006],a[10006];
int main()
{
	freopen("abc.txt","r",stdin);
	freopen("test.txt","w",stdout);
	
	long long int f,f1,c,d,v,i,j,k,ans,x;
	scanf("%lld",&f);
	for(f1=1;f1<=f;f1++)
	{
		scanf("%lld %lld %lld",&c,&d,&v);
		for(i=0;i<d;i++)
		scanf("%lld",&a[i]);
		for(i=0;i<=10006;i++)
		dp[i]=0;
		
		for(i=0;i<d;i++)
		{
			for(j=0;j<c;j++)
			{
				for(k=0;k<=v;k++)
				dv[k]=0;
				
				for(k=0;k<=v;k++)
				{
					if(dp[k]==1)
					{
						dv[k+a[i]]=1;
					}
				}
				
				for(k=0;k<=v;k++)
				{
					if(dv[k]==1)
					dp[k]=1;
				}
				dp[a[i]]=1;
			}
		}
		
		ans=0;
		for(i=1;i<=v;i++)
		{
			if(dp[i]==1);
			else
			{
				ans++;
				x=i;
				for(j=0;j<c;j++)
				{
					for(k=0;k<=v;k++)
					dv[k]=0;
					
					for(k=0;k<=v;k++)
					{
						if(dp[k]==1)
						{
							dv[k+x]=1;
						}
					}
					
					for(k=0;k<=v;k++)
					{
						if(dv[k]==1)
						dp[k]=1;
					}
					dp[x]=1;
				}
			}
		}
		printf("Case #%lld: %lld\n",f1,ans);
	}
	return 0;
}
