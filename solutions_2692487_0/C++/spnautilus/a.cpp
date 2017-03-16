#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAXN (128)

int TT;
int A;
int N;
int M[MAXN];

inline int min2(int a, int b)
{
	return (a <= b) ? a : b;
}

int main()
{
	scanf("%d", &TT);
	for(int tt = 1; tt <= TT; ++tt)
	{
		int i;

		scanf("%d %d", &A, &N);
		for(i = 0; i < N; ++i)
			scanf("%d", M + i);
		sort(M, M + N);

		int sol = N;
		int a = A;
		int res = 0;

		if(A == 1)
			N = 0;

		for(i = 0; i < N; ++i)
		{
			if(a > M[N - 1])
			{
				sol = min2(sol, res);
				break;
			}

			// Remove the rest
			sol = min2(sol, res + N - i);

			// Add mote until large enough
			while(a <= M[i])
			{
				a += a - 1;
				++res;
			}

			a += M[i];
		}

		printf("Case #%d: %d\n", tt, sol);
	}

	return 0;
}
