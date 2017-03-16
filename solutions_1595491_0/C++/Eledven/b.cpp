#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <iomanip>
#define nextLine() { for (int c = getchar(); c != '\n' && c != EOF; c = getchar()); }
#define sqr(a) ((a)*(a))
#define has(mask,i) (((mask) & (1<<(i))) == 0 ? false : true)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

typedef long long LL;
typedef long double ldb;

const int INF = (1 << 30) - 1;
const ldb EPS = 1e-9;
const ldb PI = fabs(atan2(0.0, -1.0));
const int MAXN = 105;

int n;
int s;
int p;
int tot[MAXN];

void load()
{
	scanf("%d", &n);
	scanf("%d", &s);
	scanf("%d", &p);
	for (int i = 0; i < n; i++)
		scanf("%d", &tot[i]);
}

class Triplet
{
	public:
		int judge1;
		int judge2;
		int judge3;

		Triplet() {};

		Triplet(int judge1, int judge2, int judge3)
		{
			this->judge1 = judge1;
			this->judge2 = judge2;
			this->judge3 = judge3;
		}

		bool possible() const
		{
			return abs(judge1 - judge2) <= 2 && 
			       abs(judge1 - judge3) <= 2 &&
			       abs(judge2 - judge3) <= 2;
		}

		bool isSurprising() const
		{
			int cnt = 0;
			if (abs(judge1 - judge2) == 2) cnt++;
			if (abs(judge1 - judge3) == 2) cnt++;
			if (abs(judge2 - judge3) == 2) cnt++;
			return cnt > 0;
		}

		int bestResult() const
		{
			return max(max(judge1, judge2), judge3);
		}

};

const int MAXSCORE = 30;

vector <Triplet> triplets[MAXSCORE + 1];

void precalcScores()
{
	for (int score = 0; score <= MAXSCORE; score++)
	{
		triplets[score].clear();
		for (int judge1 = 0; judge1 <= 10; judge1++)
		{
			for (int judge2 = 0; judge2 <= 10; judge2++)
			{
				for (int judge3 = 0; judge3 <= 10; judge3++)
				{
					if (judge1 + judge2 + judge3 != score) continue;
					Triplet cur(judge1, judge2, judge3);
					if (cur.possible()) 
						triplets[score].pb(cur);
				}
			}
		}	
	}	
}

int dp[MAXN][MAXN];
bool was[MAXN][MAXN];

int f(int pos, int s)
{
	if (s < 0) return -INF;

	if (pos == n)
		return s == 0 ? 0 : -INF;

	int &res = dp[pos][s];
	if (was[pos][s]) return res;

	res = -INF;
	was[pos][s] = true;

	for (int i = 0; i < (int)triplets[tot[pos]].size(); i++)
	{
		Triplet cur = triplets[tot[pos]][i];
		assert(cur.judge1 + cur.judge2 + cur.judge3 == tot[pos]);
		int cres = f(pos + 1, s - (int)cur.isSurprising()) + (int)(cur.bestResult() >= p);
		res = max(res, cres);
	}

	return res;	
}

void solve(int test)
{
	memset(was, false, sizeof(was));
	printf("Case #%d: %d\n", test, f(0, s));
}

int main()
{
	precalcScores();
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		load();
		solve(test);
	}	
	return 0;
}
