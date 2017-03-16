#include<stdio.h>      
#include<stdlib.h>      
#include<math.h>  

int minf(int a,int b)
{
	if (a<b) return a;
	else return b;
}

int maxf(int a,int b)
{
	if (a>b) return a;
	else return b;
}

int main() { 
	
	int T,i,j; 
	scanf("%d",&T);
	int E,R,N;
	long long gain;
	for (i=1; i<=T; i++)
	{
		scanf("%d",&E);
		scanf("%d",&R);
		scanf("%d",&N);
		
		int v[N+1];
		gain=0;
	
		for (j=1;j<=N;j++)
		{
			scanf("%d",&v[j]);
		}
		
		int max[N+1], min[N+1];
		for (j=1;j<=N;j++) {max[j]=E;min[j]=0;}
		int visited[N+1];
		for (j=1;j<=N;j++) visited[j]=0; //not visited
		
		int count=0;
		while (count<N)
		{
			count++; int maximum=0; int max_pos=0;
			for (j=1;j<=N;j++)
			{
				if ((visited[j]==0)&&(v[j]>=maximum)) 
				{
					maximum=v[j];
					max_pos=j;
				}
			}			
			visited[max_pos]=1;
			
			for (j=1;j<=floor(maximum/R);j++)
			{
				if (max_pos+j<=N) 
				{
					max[max_pos+j]=minf(j*R, max[max_pos+j]);
				}
			}
		
			for (j=1;j<=floor(maximum/R);j++)
			{
				if (max_pos-j>=1)
				{
					min[max_pos-j]=maxf(min[max_pos-j],max[max_pos]-j*R-R);
				}
			}
			
			gain=gain+maximum*(max[max_pos]-min[max_pos]);		
		}

		printf("Case #%d: %lld\n",i,gain);
	}
	return 0;
}