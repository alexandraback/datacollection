#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

int m[1010],h[1010][15],q[1010];

int main()
{
	int t,T,n,i,j,front,rear,ok;
//	freopen("A-large.in","r",stdin);
//	freopen("ou.out","w",stdout);
	scanf("%d",&T);
//	printf("T=%d\n",T);
	for(t=1;t<=T;++t)
	{
		scanf("%d",&n);
	//	printf("n=%d\n",n);
		for(i=1;i<=n;++i)
		{
			scanf("%d",&m[i]);
		//	printf("m=%d:",m[i]);
			for(j=1;j<=m[i];++j)
			{scanf("%d",&h[i][j]);
		//	printf("%d,",h[i][j]);
			}
		//	printf("\n");
		}
		for(q[0]=1;q[0]<=n;++q[0])
		{
		front=0;
		rear=1;
		ok=0;
		while(front<rear)
		{
			for(i=1;i<=m[q[front]];++i)
			{
				q[rear]=h[q[front]][i];
				for(j=rear-1;j>=0;--j)
				{
					if(q[rear]==q[j])
					{
						ok=1;
						goto L;
					}
				}
				++rear;
			}
			++front;
		}
		}
L:
		printf("Case #%d: %s\n",t,ok?"Yes":"No");
	}
	return 0;

}