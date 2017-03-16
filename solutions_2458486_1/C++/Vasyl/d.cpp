#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

int A[512][512];
int B[512];
int C[512];
int D[512];
int T[512];
int K[512];
int R[512];

int f(int n, int m)
{
	int i, j;
	CLEAR(C, 0);
	FOR(i, 0, n)
	{
		--C[ T[i] ];
		FOR(j, 0, K[i])
			++C[ A[i][j] ];
	}

	FOR(i, 1, m)
		if(C[i] < 0)
			return 0;

	CLEAR(C, 0);
	FOR(i, 0, n)
		if(B[i] != 0)
		{
			--C[ T[i] ];
			FOR(j, 0, K[i])
				++C[ A[i][j] ];
		}

	queue<int> Q;
	FOR(i, 0, m)
		if(C[i] > 0)
			Q.push(i);

	while(!Q.empty())
	{
		int a = Q.front();
		Q.pop();

		FOR(i, 0, n)
			if(B[i] == 0 && T[i] == a)
				FOR(j, 0, K[i])
				{
					int b = A[i][j];
					if(C[b] == 0)
					{
						C[b] = 1;
						Q.push(b);
					}
				}
	}

	FOR(i, 0, n)
		if(B[i] == 0 && C[ T[i] ] == 0)
			return 0;

	return 1;
}

int SolveTest(int test)
{
	int n;
	scanf("%d%d", &K[0], &n);
	++n;
	T[0] = 0;

	int i, j, k;
	FOR(i, 0, n)
	{
		if(i != 0)
			scanf("%d%d", &T[i], &K[i]);

		FOR(j, 0, K[i])
			scanf("%d", &A[i][j]);
	}

	printf("Case #%d: ", test + 1);
	CLEAR(B, 0);
	B[0] = 1;
	if(f(n, 512) == 0)
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}

	FOR(i, 0, n - 1)
	{
		CLEAR(D, 0);
		FOR(j, 0, n)
			if(B[j] != 0)
			{
				--D[ T[j] ];
				FOR(k, 0, K[j])
					++D[ A[j][k] ];
			}

		FOR(j, 0, n)
			if(B[j] == 0 && D[ T[j] ] > 0)
			{
				B[j] = 1;
				if(f(n, 512) != 0)
				{
					R[i] = j;
					break;
				}

				B[j] = 0;
			}

		if(j == n)
			throw 0;
	}

	FOR(i, 0, n - 1)
		printf("%d%c", R[i], i == n - 2 ? '\n' : ' ');

	return 0;
}

int main()
{
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);

	int T, t;
	char buf[1 << 7];
	gets(buf);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
	{
		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
		SolveTest(t);
	}

	return 0;
};
