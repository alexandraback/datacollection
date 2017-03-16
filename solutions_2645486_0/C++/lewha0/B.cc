#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<string.h>

const int INF = 1000000000;

using namespace std;

int E, R, N;
int A[111];
int D[111][111];
int T;

int main(void)
{
	int l1, l2, l0, l3;

	scanf("%d",&T);
	for(l0=1;l0<=T;l0++)
	{

		scanf("%d %d %d", &E, &R, &N);
		for(l1 = 1; l1 <= N; l1++) scanf("%d", &A[l1]);
		int ret = 0;

		for(l1 = 0; l1 <= N; l1++) for(l2 = 0; l2 <= E; l2++) D[l1][l2] = -INF;

		D[0][E] = 0;

		for(l1 = 1; l1 <= N; l1++)
		{
			for(l2 = 0; l2 <= E; l2++)
			{
				for(l3 = 0; l3 <= l2; l3++)
				{
					int next = l2 - l3 + R;
					if(next > E) next = E;

					D[l1][next] = max(D[l1][next], D[l1-1][l2] + A[l1] * l3);
				}
			}
		}
		for(l1 = 0; l1 <= N; l1++) for(l2 = 0; l2 <= E; l2++) if(ret < D[l1][l2]) ret = D[l1][l2];

		printf("Case #%d: %d\n",l0, ret);
	}

}
