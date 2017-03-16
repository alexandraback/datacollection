#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>
#include <memory.h>


using namespace std;
#define MAX 110
int matr[MAX][MAX];

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int N, M;
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				scanf("%d", &matr[i][j]);

		bool f = true;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				bool v = true, h = true;
				for (int k = 0; k < N; k++)
					if (matr[k][j] > matr[i][j])
					{
						v = false;
						break;
					}
				for (int k = 0; k < M; k++)
					if (matr[i][k] > matr[i][j])
					{
						h = false;
						break;
					}
				if (!v && !h)
				{
					f = false;
					break;
				}
			}
			if (!f)
				break;
		}
		printf("Case #%d: %s\n", t+1, f?"YES":"NO");
	}

	return 0;
}