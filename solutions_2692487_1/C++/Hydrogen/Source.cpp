#include <stdio.h>
#include <algorithm>

using namespace std;

int mote[1000];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		int A,N;
		scanf("%d%d",&A,&N);
		for(int i=0;i<N;i++)
			scanf("%d",&mote[i]);
		if(A==1)
		{
			printf("Case #%d: %d\n",t+1,N);
			continue;
		}
		sort(mote,mote+N);
		int ans=987654321,cnt=0;
		for(int i=0;i<N;i++)
		{
			ans=ans<cnt+N-i?ans:cnt+N-i;
			while(A<=mote[i])
			{
				A+=A-1;
				cnt++;
			}
			A+=mote[i];
		}
		ans=ans<cnt?ans:cnt;
		printf("Case #%d: %d\n",t+1,ans);
	}
	return 0;
}