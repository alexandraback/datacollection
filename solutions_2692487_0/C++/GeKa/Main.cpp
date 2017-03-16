#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <memory.h>
#include <math.h>


using namespace std;

int mas[1000];

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int N, A;
		scanf("%d%d", &A, &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &mas[i]);
		int res = N;
		if (A > 1)
		{
			sort(mas, mas + N);
			int added = 0;
			for (int i = 0; i < N; i++)
			{
				res = min(res, added + N - i);
				while (A <= mas[i])
				{
					A += A-1;
					added++;
				}
				A += mas[i];
				res = min(res, added + N - i - 1);
			}
		}
		printf("Case #%d: %d\n", t+1, res);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}