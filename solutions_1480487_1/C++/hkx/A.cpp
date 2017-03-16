#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	freopen("A-large.in","r",stdin);freopen("out.txt","w",stdout);
	int T,cas=0;
	cin>>T;
	while(T--)
	{
		int N;
		int s[500];
		int i,j;
		cin>>N;
		for(i=1;i<=N;i++) cin>>s[i];
		cas++;
		printf("Case #%d:",cas);
		int X=0;
		bool ok[500];
		memset(ok,0,sizeof(ok));
		for(i=1;i<=N;i++) X+=s[i];
		int SUM=X,NN=N;
		while(1)
		{
			int flag=0;
			for(i=1;i<=N;i++)
			{
				if(ok[i]==1) continue;
				if(SUM-s[i]+X<s[i]*(NN-1))
				{
					ok[i]=1;
					SUM-=s[i];
					NN--;
					flag=1;
				}
			}
			if(flag==0) break;
		}
		for(i=1;i<=N;i++)
		{
			if(ok[i]==1)
			{
				printf(" 0.0");
				continue;
			}
			printf(" %.8f",(SUM-s[i]+X-s[i]*(NN-1)+0.0)/(X*NN)*100);
		}
		
		
		
	/*	for(i=1;i<=N;i++) X+=s[i];
		for(i=1;i<=N;i++)
		{
			double temp,sum=0;
			for(j=1;j<=N;j++)
			{
				if(i==j) continue;
				sum+=s[j];
			}
			temp=(sum+X-s[i]*(N-1))/X/N;
			if(temp<0) ok[i]=1;
		}
		return 0;
		for(i=1;i<=N;i++)
		{
			if(ok[i]==1)
			{
				printf(" %f",0.0);continue;
			}
			int NN=0;
			double temp,sum=0;
			for(j=1;j<=N;j++)
			{
				if(i==j || ok[j]==1) continue;
				sum+=s[j];
				NN++;
			}
			temp=(sum+X-s[i]*NN)/X/(NN+1);
			printf(" %.8f",temp*100);
		}*/
		printf("\n");
	}
	return 0;
}
