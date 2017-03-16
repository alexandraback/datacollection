//#pragma comment(linker, "/STACK:134217728")

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

map<string, int> M[2];
char buf[1 << 10][2][32];
int E[1 << 11][1 << 11];
int B[1 << 11];
int gN;

int dfs(int a)
{
	if (a == gN - 1) return 1;
	B[a] = 1;
	int i;
	FOR(i, 0, gN)
		if(B[i] == 0 && E[a][i] > 0 && dfs(i) != 0)
		{
			--E[a][i];
			++E[i][a];
			return 1;
		}

	return 0;
}

int get(int idx, string s)
{
	if(M[idx].find(s) == M[idx].end())
	{
		int value = SIZE(M[idx]);
		M[idx][s] = value;
	}

	return M[idx][s];
}

int SolveTest(int test)
{
	int i, j;
	FOR(i, 0, 2) M[i].clear();

	int N;
	scanf("%d", &N);

	FOR(i, 0, N)
		FOR(j, 0, 2)
		{
			scanf("%s", buf[i][j]);
			get(j, buf[i][j]);
		}

	int n = SIZE(M[0]);
	int m = SIZE(M[1]);

	CLEAR(E, 0);
	FOR(i, 0, N)
	{
		int a = get(0, buf[i][0]);
		int b = get(1, buf[i][1]);
		E[a][n + b] = 1;
	}

	FOR(i, 0, n)
		E[n + m][i] = 1;
	FOR(i, 0, m)
		E[n + i][n + m + 1] = 1;

	gN = n + m + 2;

	int flow = 0;
	while(true)
	{
		CLEAR(B, 0);
		if (dfs(n + m) == 0) break;
		++flow;
	}

	int real = n + m - flow;
	printf("Case #%d: %d\n", test + 1, N - real);
	return 0;
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);

	int T, t;
	char buf[1 << 7];
	fgets(buf, 1 << 7, stdin);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
	{
		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
		SolveTest(t);
	}

	return 0;
};
