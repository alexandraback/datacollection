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

double A[1 << 10];
double B[1 << 10];

int SolveTest(int test)
{
	int n;
	scanf("%d", &n);

	int i;
	FOR(i, 0, n)
		scanf("%lf", &B[i]);
	FOR(i, 0, n)
		scanf("%lf", &A[i]);

	sort(A, A + n);
	sort(B, B + n);

	int pos = n - 1;
	int score = 0;
	RFOR(i, n, 0)
	{
		while (pos != -1 && B[pos] > A[i])
			--pos;

		if (pos == -1)
			++score;
		else
			--pos;
	}

	pos = 0;
	int score2 = 0;
	FOR(i, 0, n)
	{
		while (pos != n && B[pos] < A[i])
			++pos;

		if (pos != n)
		{
			++score2;
			++pos;
		}
	}

	while (pos != 0 && B[n - pos] < A[pos - 1])
		--pos;

	printf("Case #%d: %d %d\n", test + 1, score2, score);
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
