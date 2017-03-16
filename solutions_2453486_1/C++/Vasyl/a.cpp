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

char A[8][8];

int SolveTest(int test)
{
	int i, j, k;
	FOR(i, 0, 4)
		scanf("%s", A[i]);

	char chars[] = {'X', 'O', 'T'};
	int res = -1;
	int empty = 0;
	FOR(i, 0, 4)
		FOR(j, 0, 4)
			if(A[i][j] == '.')
				empty = 1;

	FOR(k, 0, 2)
	{
		int cnt = 0;
		FOR(i, 0, 4)
		{
			cnt = 0;
			FOR(j, 0, 4)
				if(A[i][j] == chars[k] || A[i][j] == chars[2])
					++cnt;

			if(cnt == 4)
				res = k;
		}

		FOR(j, 0, 4)
		{
			cnt = 0;
			FOR(i, 0, 4)
				if(A[i][j] == chars[k] || A[i][j] == chars[2])
					++cnt;

			if(cnt == 4)
				res = k;
		}

		cnt = 0;
		FOR(i, 0, 4)
			if(A[i][i] == chars[k] || A[i][i] == chars[2])
				++cnt;

		if(cnt == 4)
			res = k;

		cnt = 0;
		FOR(i, 0, 4)
			if(A[i][3 - i] == chars[k] || A[i][3 - i] == chars[2])
				++cnt;

		if(cnt == 4)
			res = k;
	}

	printf("Case #%d: %s\n", test + 1, res == -1 ? (empty == 0 ? "Draw" : "Game has not completed") : (res == 0 ? "X won" : "O won"));
	return 0;
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

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
