#include <stdio.h>

#define MAXN (10005)

typedef long long ll;

int T;
int E, R, N;
int V[MAXN];
int H[MAXN];

inline int min2(int a, int b)
{
	return (a <= b) ? a : b;
}

int main()
{
	int tt;
	scanf("%d", &T);
	for(tt = 1; tt <= T; ++tt)
	{
		int i, j;
		scanf("%d %d %d", &E, &R, &N);
		if(R > E)
			R = E;

		for(i = 1; i <= N; ++i)
			scanf("%d", V + i);

		ll sol = V[1] * ll(E);
		H[1] = E;

		for(i = 2; i <= N; ++i)
		{
			sol += V[i] * ll(R);
			H[i] = R;
		}

		j = N - 1;
		int h = 0;
		for(i = N; i > 1; --i)
		{
			h += H[i];
			if(j == i)
				j = i - 1;

			while(j >= 1 && h < E && H[i] < E)
			{
//				printf("i j %d %d\n", i, j);

				if(V[i] > V[j])
				{
					if(H[j] == 0)
					{
						--j;
						continue;
					}

					int dh = min2(E - H[i], min2(E - h, H[j]));
					h += dh;
					H[i] += dh;
					H[j] -= dh;
					sol += dh * ll(V[i] - V[j]);
				}
				else
					break;
			}

			h -= R;
			if(h < 0)
				h = 0;
		}

/*
		for(i = 1; i <= N; ++i)
			printf("%dx%d (%d)  ", H[i], V[i], H[i] * V[i]);
		putchar('\n');
//*/

		printf("Case #%d: %I64d\n", tt, sol);
	}

	return 0;
}
