#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string.h>
 
typedef long long ll;
 
using namespace std;
 
int cmp(const void *_a, const void *_b)
{
	int *a = (int *)_a;
	int *b = (int *)_b;

	return b[0] - a[0];
}

int jp[10][10];
int js[10][10];
int ps[10][10];

int r[1000][3];

int main(void)
{
	int T;

	scanf ("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		int J, P, S, K;

		scanf ("%d %d %d %d", &J, &P, &S, &K);

		for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++)
			jp[i][j] = js[i][j] = ps[i][j] = 0;

		int cnt = 0;

		for (int i = 0; i < J; i++) for (int j = 0; j < P; j++) for (int k = 0; k < S; k++)
		{
			if (jp[i][j] < K && js[i][k] < K && ps[j][k] < K)
			{
				r[cnt][0] = i + 1;
				r[cnt][1] = j + 1;
				r[cnt][2] = k + 1;
				cnt++;
				jp[i][j]++;
				js[i][k]++;
				ps[j][k]++;
			}
		}

		printf ("Case #%d: %d\n", t, cnt);

		for (int i = 0; i < cnt; i++)
			printf ("%d %d %d\n", r[i][0], r[i][1], r[i][2]);

	}
}