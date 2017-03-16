#include <stdio.h>
#include <string.h>

#define SIZE 102
int arr[SIZE][SIZE], N, M;


int valid()
{
	int r, c;
	for (r = 0; r <= N; ++r)
	{
		for (c = 0; c <= M; ++c)
		{
			if ( (arr[r][c] < arr[r][M + 1]) &&
					(arr[r][c] < arr[N + 1][c]) )
				return 0;

		}
	}
	return 1;
}

int main()
{
	int T, r, c, caseNo = 1;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d%d", &N, &M);
		bzero(arr, sizeof(arr));

		for (r = 1; r <= N; ++r)
		{
			for (c = 1; c <= M; ++c)
			{
				scanf("%d", &arr[r][c]);
				if (arr[N + 1][c] < arr[r][c]) arr[N + 1][c] = arr[r][c];
				if (arr[r][M + 1] < arr[r][c]) arr[r][M + 1] = arr[r][c];
			}
			if (!r) { continue; }
		}
		if (valid() == 0) printf("Case #%d: NO\n", caseNo++);
		else printf("Case #%d: YES\n", caseNo++);
	}
	return 0;
}
