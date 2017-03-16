#include<stdio.h>
#include<algorithm>
using namespace std;
double N[1010],K[1010];
bool vis[1010];
int NDW,NW;
int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		int n;
		
		
		
		scanf("%d",&n);
		NDW=n;
		NW=n;
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&N[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&K[i]);
		}
		sort(N,N+n);
		sort(K,K+n);
		for(int i=0;i<n;i++)
		vis[i]=0;
		// get score of War method
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				
				if(vis[j])continue;
				if(N[i]<K[j])
				{
					NW--;
					//printf("----%.7f ? %.7f\n",N[i],K[j]);
					vis[j]=1;
					break;
				}
			}
		}
		//get score of DWar method
		for(int i=0;i<n;i++)
		vis[i]=0;
		int mx=n-1,mn=0;
		for(int i=0;i<n;i++)
		{
			if(N[i]<K[mn])
			{
				NDW--;
				mx--;
			}
			else
			{
				mn++;
			}
		}
		
		printf("Case #%d: ",t);
		printf("%d %d\n",NDW,NW);
		
	}
}
