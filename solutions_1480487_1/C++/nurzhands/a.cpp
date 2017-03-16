// iTwin
#ifdef UNIX
#define i64 "%lld"
#else
#define i64 "%I64d"
#endif

#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <bitset>
#include <vector>
#include <string>
#include <cstdio>
#include <cassert>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(a) (int)a.size()
#define fill(a,key) memset(a, key, sizeof(a))
#define all(x) x.begin(), x.end()
#define sqr(x) (x)*(x)
#define fi first
#define se second
#define forn(i,n) for (i = 0; i < n; i++)
#define curtime double(clock())/double(CLOCKS_PER_SEC)
typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int dx[] = {-1,0,1,0,-1,-1,1,1,0};
const int dy[] = {0,1,0,-1,-1,1,1,-1,0};
const int inf = 1<<30;

const double eps = 1e-12;

int s[300], x, i, sum, n, t;

bool ok(double y, double cur, int ind)
{
	double total = 1 - y, need;
	for (int i = 0; i < n; i++) if (i != ind)
		total -= max((cur-s[i])/sum,.0);
	return total < eps;
}

double calc(int ind)
{
	double l = 0, r = 1, mid, ans;

	for (int i = 0; i < 100; i++)
	{
		mid = (l + r) / 2;
		//printf("%.5lf", s[ind]+mid*sum); exit(0);
		if (ok(mid,s[ind]+mid*sum,ind))
		{
			ans = mid;
			r = mid;
		}
		else
			l = mid;
	}
	return ans;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	srand(time(0));
	#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif

	cin >> t;

	for (x = 1; x <= t; x++)
	{
		cin >> n;

		sum = 0;

		for (i = 0; i < n; i++)
		{
			cin >> s[i];
			sum += s[i];
		}

		printf("Case #%d: ", x);

		for (i = 0; i < n; i++)
			printf("%.6lf ", calc(i)*100);

		printf("\n");
	}

	return 0;
}