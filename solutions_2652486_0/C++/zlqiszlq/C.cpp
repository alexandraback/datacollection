#include<cstdio>
#include<cstring>
using namespace std;
#define MAXK  13
#define MAXN  13

int T;
int R,N,M,K;

int A[MAXK],B[MAXN];
bool X[1000];

void find(int dep,int re)
{
	if (dep == N)
	{
		X[re] = 1;
		return ;
	}
	find(dep+1,re);
	find(dep+1,re*B[dep]);
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int i;
	scanf("%d",&T);
	scanf("%d%d%d%d",&R,&N,&M,&K);
	printf("Case #1:\n");
	for (int t=0;t<R;t++)
	{
		for (i=0;i<K;i++)
			scanf("%d",&A[i]);
		for (B[0] = 2;B[0] <= M;B[0] ++)
			for (B[1] = 2;B[1] <= M;B[1] ++)
				for (B[2]= 2;B[2] <=M;B[2] ++)
				{
					memset(X,0,sizeof X);
					find(0,1);
					for (i=0;i<K;i++)
						if (!X[A[i]])
							break;
					if (i == K)
						goto HERE;
				}
				
	HERE:
		for (i=0;i<N;i++)
			printf("%d",B[i]);
		printf("\n");
	}
	return 0;
}
