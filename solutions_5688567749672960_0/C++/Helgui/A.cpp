#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <utility>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(x) (x)*(x)
#define _with_file
#define TASK ""
#define forn(i, n) for(int i = 0; i < (int)n; ++i)

void quit(); 

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
#ifdef local
typedef double ld;
#else
typedef long double ld;
#endif
typedef pair <int, int> PII;
typedef pair <i64, i64> PII64;
typedef pair <ld, ld> PLL;

const ld PI = acos(-1);
const ld EPS = 1e-10;
double __t;

int dp[1000100];

inline int rev(int x)
{
	int res = 0;
	while(x)
	{
		res *= 10;
		res += (x%10);
		x /= 10;
	}
	return res;
}

int main()
{
	#ifdef local
		__t = clock();
		#ifndef _with_files
			freopen("z.in", "rt", stdin);
			freopen("z.out", "wt", stdout);
		#endif
	#endif
	#ifdef _with_files
		freopen(TASK".in", "rt", stdin);
		freopen(TASK".out", "wt", stdout);
	#endif
	int T;
	cin >> T;
	int n;
	for(int test = 1; test <= T; ++test)
	{
		cin >> n;
		memset(dp, 0x7f, sizeof(dp));
		dp[1] = 1;
		int r;
		for(int i = 1; i < n; ++i)
		{
			r = rev(i);
			if (r <= n)
				dp[r] = min(dp[r], dp[i] + 1);
			dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		}
		cout << "Case #" << test << ": " << dp[n] << endl;
	}
	quit();
}

void quit()
{
	#ifdef local
		cerr << "\nTOTAL TIME: "<< (clock() - __t)/1000.0 << " s\n";
	#endif
	exit(0);		
}