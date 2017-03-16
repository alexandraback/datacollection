#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define ll long long
#define sf scanf
#define pf printf
#define Maxn 10100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
int E, R, n, ans;
int v[Maxn];
int dp[15][10];

int dfs(int p, int s) {
    if (p > n) {
        return 0;
    }
    if (dp[p][s] != -1) return dp[p][s];
    dp[p][s] = 0;
    for (int i = 0; i <= s; i++) {
        dp[p][s] = max(dp[p][s], v[p] * i + dfs(p+1, min(E, s-i+R)));
    }
    return dp[p][s];
    
}
int main() {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
    int T, ca = 0;
    sf("%d", &T);
    while (T--) {
        sf("%d%d%d", &E, &R, &n);
        FOR(i, 1, n+1) sf("%d", &v[i]);
        //sort(v+1, v+n+1, greater<int>());
        //FOR(i, 1, n+1) cout <<v[i] <<endl;
        memset(dp, -1, sizeof(dp));
        ans = dfs(1, E);
        pf("Case #%d: %d\n", ++ca, ans);
    }
    return 0;
}
