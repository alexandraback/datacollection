#include <ctime>
#include <queue>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <numeric>
#include <deque>
#include <list>
#include <memory>
#include <memory.h>

using namespace std;

#define SZ(a) (int)(a).size()
#define FOR(i, a, b) for(int i=(a), _b(b); i<_b; ++i)
#define FORD(i, a, b) for(int i=(a)-1, _b(b); i>=_b; --i)
#define FIND(a, b) ((a).find(b)!=(a).end())
#define FILL(a, b) memset(a, b, sizeof(a))
#define SQR(a) ((a)*(a))

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const int mod = 1000000009;

int ADD(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int SUB(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int MUL(LL a, LL b) { return a*b%mod; }
int POW(int a, int b)
{
	if (!b) return 1;
	int t = POW(a, b >> 1);
	t = MUL(t, t);
	if (b & 1) t = MUL(t, a);
	return t;
}
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }

double beginTime;

string word, al;
int pref[128];
int minPr;

int p[26], n, m, k;

double dp[101][101][101];
double probWord, probSuf;
double mx = 0;

double Calc(int pos, int occur, int pr)
{
	if (pr == m)
	{
		occur++; pr = 0;
		if (minPr < m) pr = m - minPr;
		mx = max(mx, (double)occur);
	}

	if (pos == n) return occur;
	if (pos >= n) return 0;

	double &res = dp[pos][occur][pr];

	if (res == -1)
	{
		res = 0;
		FOR(i, 0, 26)
		{
			if (!p[i]) continue;
			double prob = (double)p[i] / (double)k;
			int P = pr;

			while (P && word[P] - 'A' != i)
			{
				P = pref[P];
			}
			
			if (word[P] - 'A' == i)
				res += prob * Calc(pos + 1, occur, P + 1);
			else
				res += prob * Calc(pos + 1, occur, 0);
		}

	}

	return res;
}

int main()
{
#ifdef ALMAG_LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#endif

	int tc; scanf("%d", &tc);
	int cs = 0;
	while (tc --> 0)
	{
		int K, L, S; scanf("%d %d %d", &K, &L, &S);
		cin >> al;
		cin >> word;

		FOR(i, 0, 26) p[i] = 0;
		FOR(i, 0, SZ(al)) p[al[i] - 'A']++;

		FOR(i, 0, 128) pref[i] = 0;
		FOR(i, 1, SZ(word)+1)
		{
			string s = word.substr(0, i);
			FOR(j, 1, SZ(s))
			{
				if (s.substr(SZ(s) - j) == word.substr(0, j)) pref[i] = j;
			}
		}
		
		k = K;  n = S; m = L;

		FOR(i, 0, 101) FOR(j, 0, 101) FOR(k, 0, 101) dp[i][j][k] = -1;

		mx = 0;
		double res = Calc(0, 0, 0);

		printf("Case #%d: %.10lf\n", ++cs, mx - res);
	}

	return 0;
}