#include <stdio.h>
#define maxN 1000000

int n;
int que[maxN+10], visit[maxN];

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);

	int tcn;
	scanf("%d",&tcn);
	for(int tc=1;tc<=tcn;tc++)
	{
		scanf("%d",&n);
		int t = 1;
		while( t < n ) t*=10;
		for(int i=0;i<=t;i++) visit[i] = 0;
		
		visit[1] = 1;
		que[1] = 1;

		int f=1, s=1, now, next;
		while( f<=s && !visit[n] )
		{
			now = que[f];
			//printf("%d, %d\n",now,visit[now]);
			next = now+1;
			if( !visit[next] )
			{
				que[++s] = next;
				visit[next] = visit[now] + 1;
			}

			next = 0;
			for(int t=now;t;t/=10) next = next*10 + t%10;
			if( !visit[next] )
			{
				que[++s] = next;
				visit[next] = visit[now] + 1;
			}

			f++;
		}

		printf("Case #%d: %d\n",tc,visit[n]);
	}

	return 0;
}