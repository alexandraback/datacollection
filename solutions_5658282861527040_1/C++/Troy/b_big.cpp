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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int A, B, K;
ll dp[40][2][2][2], ans;

void int2binary(int x, vi &vec) {
    vec.clear();
    while (x) {
        if (x & 1) vec.pb(1);
        else vec.pb(0);
    }
}

ll dfs(int idx, int sa, int sb, int sc) {
    if (idx < 0) {
        if (sa && sb && sc) return 1;
        else return 0;
    }
    if (dp[idx][sa][sb][sc] != -1) return dp[idx][sa][sb][sc];
    
    ll ret = 0;
    
    REP(i, 2) {
        if (!sa && !(A&(1<<idx)) && i) continue;
        REP(j, 2) {
            if (!sb && !(B&(1<<idx)) && j) continue;
            int x = (i & j);
            if (!sc && !(K&(1<<idx)) && x) continue;
            
            int nsa = ((A&(1<<idx)) && !i) ? 1 : sa;
            int nsb = ((B&(1<<idx)) && !j) ? 1 : sb;
            int nsc = ((K&(1<<idx)) && !x) ? 1 : sc;
                
            ret += dfs(idx - 1, nsa, nsb, nsc);
        }
    }
    return dp[idx][sa][sb][sc] = ret;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T, ca = 0;
    cin >>T;
    while (T--) {
        cin >>A >>B >>K;
        memset(dp, -1, sizeof(dp));
        ans = 0;
        ans = dfs(31, 0, 0, 0);
        cout <<"Case #" <<++ca <<": " <<ans <<endl;
    }
    return 0; 
}

