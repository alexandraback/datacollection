#include <stdio.h>

int T;
int N, S, P;

int main()
{
	int i, j;
	int tt;

	scanf("%d", &T);
	for(tt = 1; tt <= T; ++tt)
	{
		int sol = 0;

		scanf("%d %d %d", &N, &S, &P);
		for(i = 0; i < N; ++i)
		{
			int t;
			scanf("%d", &t);

			if(t + 2 >= 3 * P && t >= P)
				++sol;
			else if(S > 0 && t + 4 >= 3 * P && t >= P)
			{
				--S;
				++sol;
			}
		}

		printf("Case #%d: %d\n", tt, sol);
	}

	return 0;
}
