#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int m[101][101];
int v[101][101];
int N,M;

int main()
{
	int i,j,k;
	int cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		cin >> N >> M;
		for(i=0; i<N; i++) for(j=0; j<M; j++) cin >> m[i][j];
		int step;
		for(step=1; step<=100; step++)
		{
			memset(v, 0, sizeof(v));
			for(i=0; i<N; i++) for(j=0; j<M; j++)
			{
				if (m[i][j] != step) continue;
				if (v[i][j]) continue;
				int f = 0;
				for(k=0; k<M; k++)
					if (!(m[i][k] == step || v[i][k]))
						break;
				if (k >= M)
				{
					for(k=0; k<M; k++)
						v[i][k] = 1;
					f = 1;
				}
				for(k=0; k<N; k++)
					if (!(m[k][j] == step || v[k][j]))
						break;
				if (k >= N)
				{
					for(k=0; k<N; k++)
						v[k][j] = 1;
					f = 1;
				}
				if (f == 0)
					goto fail;
			}
			for(i=0; i<N; i++) for(j=0; j<M; j++)
			{
				if (v[i][j])
					m[i][j] = step+1;
			}
		}
		printf("Case #%d: YES\n", cc);
		continue;
fail:
		printf("Case #%d: NO\n", cc);
	}
}
