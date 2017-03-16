#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <list>
#include <deque>
#include <algorithm>

using namespace std;

class Solution
{
	static const int MAXN = 1012;
	int Result;
	int N;
	int F[MAXN];

	bool IsUsed[MAXN];
	int M[MAXN];
public:
	void Work()
	{
		int i, k, r;
		Result = 1;

		memset(M, 0, sizeof(M));

		for (i = 0; i < N; ++i)
		{
			memset(IsUsed, 0, sizeof(IsUsed));

			r = 0;
			for (k = i; !IsUsed[k]; k = F[k])
			{
				IsUsed[k] = true;
				++r;
			}
			if (k == i&& Result < r)
				Result = r;
			if (F[F[k]] == k && M[k] < r-1)
				M[k] = r-1;
		}

		r = 0;
		for (i = 0; i < N; ++i)
			r += M[i];
		if (Result < r)
			Result = r;
	}

	void Read()
	{
		int i;
		scanf("%d", &N);
		for (i = 0; i < N; ++i)
		{
			scanf("%d", &F[i]);
			--F[i];
		}
	}

	void Write(int t)
	{
		printf("Case #%d: %d\n", t, Result);
	}
};

vector< Solution > solution;

int main()
{
	int i, t;
	scanf("%d", &t);
	solution.resize(t);
	for (i = 0; i < t; ++i)
		solution[i].Read();
#pragma omp parallel for schedule(dynamic, 1)
	for (i = 0; i < t; ++i)
		solution[i].Work();
	for (i = 0; i < t; ++i)
		solution[i].Write(i + 1);
	return 0;
}
