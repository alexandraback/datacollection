#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <functional>
#include <cstring>

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
#define INF 987654321
using namespace std;

bool compare(int a, int b)
{
	return a < b;
}

int main()
{
	freopen("small.txt", "r", stdin);
	freopen("small_answer.txt", "w", stdout);

	int T;

	int t = 1;

	scanf("%d", &T);

	while (T >= t)
	{
		int J, P, S, K;

		scanf("%d %d %d %d", &J, &P, &S, &K);

		int JPS = J*P*S;
		int JPK = J*P*K;

		if (JPS > JPK)
		{
			printf("Case #%d: %d\n", t, JPK);
			int kkk = 1;
			int kk = kkk;
			int k = kk;

			for (int i = 0; i < K; ++i)
			{
				kk = kkk;
				for (int a = 0; a < J; ++a)
				{
					k = kk;
					for (int b = 0; b < P; ++b)
					{
						printf("%d %d %d\n", a + 1, b + 1, k);
						k += 1;
						if (k > S)
							k %= S;
					}

					kk += 1;
					if (kk > S)
						kk %= S;
				}

				kkk += 1;
				if (kkk > S)
					kkk %= S;

			}
		}

		else
		{
			printf("Case #%d: %d\n", t, JPS);
			for (int a = 0; a < J; ++a)
				for (int b = 0; b < P; ++b)
					for (int c = 0; c < S; ++c)
						printf("%d %d %d\n", a + 1, b + 1, c + 1);
		}

		++t;

	}

	return 0;

}