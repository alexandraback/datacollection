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

vector<int> make2(long long int M)
{
	vector<int> n2;

	while (M >= 1)
	{
		if (M % 2 == 0)
			n2.push_back(0);

		else
			n2.push_back(1);

		M /= 2;
	}

	return n2;
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
		int B;
		long long int M;

		scanf("%d %lld", &B, &M);

		if (pow(2, B - 2) < M)
			printf("Case #%d: IMPOSSIBLE\n", t);

		else
		{
			int **matrix = new int*[B];
			for (int i = 0; i < B; ++i)
				matrix[i] = new int[B];

			for (int i = 0; i < B; ++i)
				for (int j = 0; j < B; ++j)
					matrix[i][j] = 0;

			for (int i = 0; i < B - 1; ++i)
				for (int j = i + 1; j < B - 1; ++j)
					matrix[i][j] = 1;

			if (pow(2, B - 2) == M)
				for (int i = 0; i < B - 1; ++i)
					matrix[i][B - 1] = 1;

			else
			{
				vector<int> M2 = make2(M);
				
				for (int i = 1; i < M2.size() + 1; ++i)
					if (M2[i - 1] == 1)
						matrix[i][B - 1] = 1;
			}

			printf("Case #%d: POSSIBLE\n", t);
			for (int i = 0; i < B; ++i)
			{
				for (int j = 0; j < B; ++j)
					printf("%d", matrix[i][j]);

					printf("\n");
			}
		}

		++t;

	}

	return 0;
}

