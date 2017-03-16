#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct T
{char m[51][51]; T() {memset(this, 0, sizeof(T));}};

bool rec(T& D, int R, int C, int M)
{
	if(M == 0)
		return true;
	else if(R <= 2)
	{
		if(M % R == 1)
			return false;
		if(C < 2 + M/R)
			return false;
		for(int i = 0; i < M/R; ++i)
			for(int j = 0; j < R; ++j)
				D.m[j][C-i-1] = '*';
		return true;
	}
	else if(C <= 2)
	{
		if(M % C == 1)
			return false;
		if(R < 2 + M/C)
			return false;
		for(int i = 0; i < M/C; ++i)
			for(int j = 0; j < C; ++j)
				D.m[R-i-1][j] = '*';
		return true;
	}
	else
	{
		int h = R, w = C;
		int p = w + h - 1;
		if(p < 0) p = 0;
		if(p == 0 && M != 0)
			return false;

		int n = M < p ? M : p;
		int first = min(w, h);
		bool f = first <= n;

		n = min(first, n);
		if(n == first - 1)
			n = first - 2;
		if(first == w)
		{
			for(int i = 0; i < n; ++i)
				D.m[R-1][C-i-1] = '*';
			--R;
		}
		else
		{
			for(int i = 0; i < n; ++i)
				D.m[R-i-1][C-1] = '*';
			--C;
		}
		M -= n;
		return rec(D, R, C, M);
	}
	return true;
}

bool fob(T& D, int R, int C, int M)
{
	bool fill = M + 1 == R*C;
	for(int j = 0; j < R; ++j)
		for(int i = 0; i < C; ++i)
			D.m[j][i] = fill ? '*' : '.';
	D.m[0][0] = 'c';
	if(fill)
		return true;
	return rec(D, R, C, M);
	//return foo(D, R, C, M);
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int N;
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		int R, C, M;
		scanf("%d %d %d", &R, &C, &M);
		printf("Case #%d:\n", i, R, C, M);
		T D;
		if(!fob(D, R, C, M))
			printf("Impossible\n");
		else
		{
			for(int j = 0; j < R; ++j)
			{
				for(int i = 0; i < C; ++i)
					printf("%c", D.m[j][i]);
				printf("\n");
			}
		}
	}
	return 0;
}