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

int Mul2(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a == b)
		return 4;

	int next = a == 3 ? 1 : a + 1;
	int prev = a == 1 ? 3 : a - 1;
	return b == next ? prev : (next ^ 4);
}

int Mul(int a, int b)
{
	return ((a & 4) ^ (b & 4)) ^ Mul2(a & 3, b & 3);
}

int A[1 << 20];
char buf[1 << 20];

int f(int L, Int X)
{
	int expected = Mul(1, Mul(2, 3));

	int i;
	int res = 0;
	FOR(i, 0, L)
		res = Mul(res, A[i]);

	int all = 0;
	FOR(i, 0, X)
		all = Mul(all, res);

	if (all != expected)
		return 0;

	res = 0;
	FOR(i, 0, 4 * L)
	{
		res = Mul(res, A[i % L]);
		if (res == 1)
			break;
	}

	if (i == 4 * L)
		return 0;

	int left = i + 1;
	res = 0;
	FOR(i, 0, 4 * L)
	{
		res = Mul(A[L - 1 - (i % L)], res);
		if (res == 3)
			break;
	}

	if (i == 4 * L)
		return 0;

	int right = i + 1;
	return left + right < L*X ? 1 : 0;
}

int SolveTest(int test)
{
	int L, X;
	scanf("%d%d%s", &L, &X, buf);

	int i;
	FOR(i, 0, L)
		A[i] = buf[i] == 'i' ? 1 : (buf[i] == 'j' ? 2 : 3);

	printf("Case #%d: %s\n", test + 1, f(L, X) == 0 ? "NO" : "YES");
	return 0;
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);

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
