#include <stdio.h>
#include <string.h>

#define WORDS (522000)
#define MAXL (12)
#define MAXS (64)

FILE *dict;

int W;
char D[WORDS][MAXL];
int L[WORDS];

int TT;
char S[MAXS];
int dp[MAXS][6];

inline int min2(int a, int b)
{
	return (a <= b) ? a : b;
}

int main()
{
	dict = fopen("garbled_email_dictionary.txt", "rt");
	if(dict == NULL)
		return 1;

	W = 0;
	while(fscanf(dict, "%s", D[W]) > 0)
	{
		L[W] = strlen(D[W]);
		++W;
	}

	fclose(dict);

//	printf("W %d\n", W);

	scanf("%d", &TT);
	for(int tt = 1; tt <= TT; ++tt)
	{
		int i, j, k;

		scanf("%s", S);
		int N = strlen(S);

		memset(dp, 30, sizeof(dp)); // some large number
		dp[0][4] = 0;

		for(i = 1; i <= N; ++i)
		{
			for(j = 0; j < W; ++j)
			{
				if(L[j] <= i) // vocab short enough
				{
					int d1 = -1;
					int d2 = -1;
					int dn = 0;

					for(k = 0; k < L[j]; ++k)
					{
						char cs = S[i - L[j] + k]; // S
						char cv = D[j][k]; // vocab

						if(cs != cv)
						{
							if(d1 == -1)
								d1 = k;
							d2 = k;
							++dn;
						}
					}

					if(dn > 2 || (dn == 2 && d1 + 5 > d2))
						continue;

					for(k = 0; k <= 4; ++k)
					{
						if(dn == 0 || k + d1 >= 4)
						{
							int i1 = min2(4, ((dn == 0) ? k + L[j] : L[j] - d2 - 1));

							dp[i][i1] = min2(dp[i][i1], dp[i - L[j]][k] + dn);
//							printf("%s\n", D[j]);
						}
					}
				}
			}
		}

/*
		for(i = 0; i <= N; ++i)
		{
			for(j = 0; j <= 4; ++j)
				printf("%9d ", dp[i][j]);
			putchar('\n');
		}
//*/

		int sol = N;
		for(i = 0; i <= 4; ++i)
			sol = min2(sol, dp[N][i]);

		printf("Case #%d: %d\n", tt, sol);
	}

	return 0;
}
