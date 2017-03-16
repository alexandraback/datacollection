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

string D[] = {
	"ZERO",
	"TWO",
	"SIX",
	"EIGHT",
	"SEVEN",
	"FIVE",
	"FOUR",
	"ONE",
	"THREE",
	"NINE"
};

const string U = "ZWXGSVFORI";
const int O[] = { 0, 2, 6, 8, 7, 5, 4, 1, 3, 9 };

int SolveTest(int test)
{
	char buf[1 << 11];
	scanf("%s", buf);
	int n = strlen(buf);

	int cnt[256];
	CLEAR(cnt, 0);

	int i, j;
	FOR(i, 0, n) ++cnt[buf[i]];


	int res[10];
	CLEAR(res, 0);
	FOR(i, 0, 10)
	{
		int a = cnt[U[i]];
		res[O[i]] += a;
		FOR(j, 0, SIZE(D[i]))
			cnt[D[i][j]] -= a;
	}

	string ret = "";
	FOR(i, 0, 10)
		ret += string(res[i], '0' + i);

	printf("Case #%d: %s\n", test + 1, ret.c_str());

	return 0;
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

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
