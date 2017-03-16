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
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;
typedef vector <vb> vvb;

const int INF = (1 << 30) - 1;
const ldb EPS = 1e-9;
const ldb PI = fabs(atan2(0.0, -1.0));

int n;
vi start;
int need[20];
vi keys[20];
void load()
{
	start.clear();
	int k;
	scanf("%d%d", &k, &n);
	for (int i = 0, a; i < k; i++)
	{
		scanf("%d", &a);
		start.pb(a - 1);
	}

	for (int i = 0, t; i < n; i++)
	{
		scanf("%d%d", &need[i], &t);
		--need[i];
		keys[i].clear();
		for (int j = 0, a; j < t; j++)
		{
			scanf("%d", &a);
			keys[i].pb(a - 1);
		}
	}
}

bool can[1 << 20][20];
char dp[1 << 20];
int pr[1 << 20];

char f(int mask)
{
	if (mask == (1 << n) - 1)
		return 1;

	char &res = dp[mask];
	int &best = pr[mask];
	if (res != -1) return res;

	res = 0;
	best = -1;

	for (int i = 0; i < n; i++)
	{
		if (!can[mask][i]) continue;
		char cres = f(mask | (1 << i));
		if (cres)
		{
			best = i;
			res = 1;
			break;
		}
	}

	return res;	
}

void out(int mask)
{
	if (mask == (1 << n) - 1)
		return;
	int cur = pr[mask];
	printf(" %d", cur + 1);
	out(mask | (1 << cur));
}

void solve(int test)
{
	memset(dp, -1, sizeof(dp));
	memset(can, false, sizeof(can));
	for (int mask = 0; mask < (1 << n); mask++)
	{
		char cnt[210] = {0};
		for (int i = 0; i < (int)start.size(); i++)
			cnt[start[i]]++;
		for (int i = 0; i < n; i++)
		{
			if (has(mask, i))
			{
				cnt[need[i]]--;
				for (int j = 0; j < (int)keys[i].size(); j++)
					cnt[keys[i][j]]++;
			}
		}
		bool bad = false;
		for (int i = 0; !bad && i < 200; i++)
			bad &= cnt[i] >= 0;
		if (bad) continue;
			
		for (int i = 0; i < n; i++)
		{
			if (has(mask, i) || cnt[need[i]] == 0) continue;
			can[mask][i] = true;
		}
	}

	if (!f(0))
	{
		printf("Case #%d: IMPOSSIBLE\n", test);
		return;
	}
	printf("Case #%d:", test);
	out(0);
	printf("\n");
}

int main()
{
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		load();
		solve(test);
	}	
	return 0;
}
