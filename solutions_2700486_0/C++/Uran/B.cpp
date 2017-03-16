#ifdef SHTRIX 
#include "/Users/roman/Dev/SharedCpp/DebugOutput.h"
#endif
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <memory>
using namespace std;
#define pb push_back
#define INF 1000000000
#define L(s) (int)((s).end()-(s).begin())
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define C(a) memset((a),0,sizeof(a))
#define ll long long
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define VI vector<int>
#define ppb pop_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
//#define x first
//#define y second
#define sqr(a) (a)*(a)
#define D(a,b) sqrt(((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
#define pi 3.1415926535897932384626433832795028841971
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define die(w) printf("Case #%d: %.9lf\n", case_id, w); return;

double dp[1111][1111];
double getProb(int qnt, int side, int lev) {
	C(dp);
	rept(i, qnt + 1)
		rept(j, qnt + 1) {
			if (i + j > qnt) continue;
			if (i == 0 && j == 0) {
				dp[i][j] = 1.0;
			}
			if (i == side) {
				dp[i][j + 1] += dp[i][j];
				continue;
			}
			if (j == side) {
				dp[i + 1][j] += dp[i][j];
				continue;
			}
			dp[i + 1][j] += 0.5 * dp[i][j];
			dp[i][j + 1] += 0.5 * dp[i][j];
		}
	double ans = 0.0;
	for (int L = lev + 1; L <= side; L++) {
		int R = qnt - L;
		if (R < 0) continue;
		ans += dp[L][R];
	}
	return ans;
}

inline void solve(int case_id) {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    if (y < 0) {
    	die(0.0);
    }
    int h = 0, next_lev = 1, sum = 0;
    while (n >= next_lev) {
    	sum += next_lev;
    	n -= next_lev;
    	h++;
    	next_lev += 4;
    }
    if (x + y <= 2 * (h - 1)) {
    	die(1.0);
    }
    if (x + y > 2 * h) {
    	die(0.0);
    }
    int side = (next_lev - 1) / 2;
    int level = (x + y) / 2 - 1;
    double ans = getProb(n, side, level);
    printf("Case #%d: %.9lf\n", case_id, ans);
}

int main()
{
    #ifdef SHTRIX 
    freopen("input.txt","rt",stdin); 
    //freopen("output.txt","wt",stdout); 
    #endif
	int TC;
    scanf("%d", &TC);
    rep(tc, TC) solve(tc);
    return 0;
}
