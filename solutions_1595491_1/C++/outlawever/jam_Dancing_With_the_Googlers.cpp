#include <iostream>
#include <algorithm>
using namespace std;

int T,N,S,P,sc[200],mv[200];

int work()
{
	for(int i=0;i<N && S;i++)
	{
		if(sc[i]%3==1) 
			continue;
		if(mv[i]+1!=P)
			continue;
		if(sc[i]%3==0)
		{
			if(sc[i]>=3)
			{
				mv[i]++;
				S--;
			}
		}
		else
		{
			if(sc[i]>=2)
			{
				mv[i]++;
				S--;
			}
		}
	}
	int cnt=0;
	for(int i=0;i<N;i++)
		if(mv[i]>=P)
			cnt++;
	return cnt;
}
int main()
{	
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	scanf("%d",&T);
	for(int cnb=1;cnb<=T;cnb++)
	{
		scanf("%d%d%d",&N,&S,&P);
		for(int i=0;i<N;i++)
			scanf("%d",sc+i);
		sort(sc,sc+N);
		for(int i=0;i<N;i++)
		{
			mv[i]=sc[i]/3;
			if(sc[i]%3) 
				mv[i]++;
		}
		printf("Case #%d: %d\n",cnb,work());
	}
}