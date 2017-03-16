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

char C[32];
char J[32];

int SolveTest(int test)
{
	scanf("%s%s", C, J);
	int n = strlen(C);

	int i, j, k, l;
	Int value = 0;
	pair<Int, pair<Int, Int>> res(1LL << 62, MP(0, 0));
	FOR(i, 0, n)
	{
		int cfrom = 0, cto = 9;
		int jfrom = 0, jto = 9;
		if (C[i] != '?') cfrom = cto = C[i] - '0';
		if (J[i] != '?') jfrom = jto = J[i] - '0';

		FOR(j, cfrom, cto + 1)
			FOR(k, jfrom, jto + 1)
				if(j != k)
				{
					Int cvalue = 10 * value + j;
					Int jvalue = 10 * value + k;
					FOR(l, i + 1, n)
					{
						int cdigit = C[l] == '?' ? (cvalue < jvalue ? 9 : 0) : C[l] - '0';
						int jdigit = J[l] == '?' ? (cvalue > jvalue ? 9 : 0) : J[l] - '0';

						cvalue = 10 * cvalue + cdigit;
						jvalue = 10 * jvalue + jdigit;
					}

					Int diff = cvalue - jvalue;
					if (diff < 0) diff = -diff;
					res = min(res, MP(diff, MP(cvalue, jvalue)));
				}


		if (C[i] != '?' && J[i] != '?' && C[i] != J[i]) break;
		value *= 10;
		if (C[i] != '?')
			value += C[i] - '0';
		else if (J[i] != '?')
			value += J[i] - '0';
	}

	if (i == n) res = min(res, MP(0LL, MP(value, value)));
	char buf[64];
	sprintf(buf, "%%0%dlld", n);
	string s = "Case #%d: ";
	s += buf;
	s += " ";
	s += buf;
	s += "\n";
	printf(s.c_str(), test + 1, res.second.first, res.second.second);
	return 0;
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

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
