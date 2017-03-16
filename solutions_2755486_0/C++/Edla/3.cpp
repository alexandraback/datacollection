#include<cstdio>
using namespace std;
int wall[40000000];
int mid=40000000/2;
int main()
{
	int t,T,i,N,n[10],s[10],d[10],w[10],e[10],del_d[10],del_p[10],del_s[10],ans,rem,temp;
	int min,j;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d",&N);
		ans=0;
		rem=0;
		for(i=0;i<N;i++)
		{
			scanf("%d%d%d%d%d%d%d%d",&d[i],&n[i],&w[i],&e[i],&s[i],&del_d[i],&del_p[i],&del_s[i]);
			rem+=n[i];
		}
		for(i=0;i<40000000;i++)
			wall[i]=0;
		while(rem>0)
		{
			min=10000000;
			for(i=0;i<N;i++)
			{
				if(d[i]<min&&n[i]>0)
					min=d[i];
			}
			for(i=0;i<N;i++)
			{
				temp=0;
				if(d[i]==min&&n[i]>0)
				{
					for(j=2*w[i]+mid;j<=2*e[i]+mid;j++)
					{
						if(wall[j]<s[i])
						{
							temp=1;
							break;
						}
					}
					//printf("tribe=%d day=%d\n",i,d[i]);
				}
				ans+=temp;				
			}
			for(i=0;i<N;i++)
			{
				if(d[i]==min&&n[i]>0)
				{
					for(j=2*w[i]+mid;j<=2*e[i]+mid;j++)
					{
						if(wall[j]<s[i])
						{
							wall[j]=s[i];
						}
					}
					d[i]=d[i]+del_d[i];
					n[i]--;
					rem--;
					w[i]=w[i]+del_p[i];
					e[i]=e[i]+del_p[i];
					s[i]=s[i]+del_s[i];
				}				
			}
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
