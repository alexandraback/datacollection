#include <stdio.h>
#include <memory.h>
typedef long long LL;
LL ans[107];
int K,C,S,students;
LL KC;

int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int i,j,t,T;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		students = 0;
		KC = 1;
		printf("Case #%d: ",t);
		scanf("%d %d %d",&K, &C, &S);
		for(i=0;i<C;i++) KC = KC * K;
		for(i=1;i<=K;i+=C) // group by C
		{
			LL r = KC;
			LL pos = 1;
			for(j=i;j<=i+C;j++)
			{
				int x = j;
				if(x > K) x = K;
				pos += (r / K) * (x-1);
				r = r / K;
			}
			ans[students++]=pos;
		}
		if( students > S ) printf("IMPOSSIBLE\n");
		else
		{
			for(i=0;i<students;i++) printf("%lld ",ans[i]);
			printf("\n");
		}
	}
}