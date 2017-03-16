#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

int t, n;

int rev(int n) {
    if(n < 10) return n;
    vi v;
    while(n) {
        v.pb(n % 10);
        n /= 10;
    }
    int ans = 0;
    forit(it, v) {
        ans = 10 * ans + *it;
    }
    return ans;
}

int dp[1001000];

int calc(int n) {
    if(n == 1) return 1;
    if(n < 0) return inf;
    int &res = dp[n];
    if(res != -1) return res;
    res = inf;
    int y = n-1;
    res = min(res, 1 + calc(y));
    y = rev(n);
    if(y < n && rev(y) == n) res = min(res, 1 + calc(y));
    return res;
}

vi v;

void rec(int n) {
    v.pb(n);
    if(n == 1) return;
    int res = calc(n);
    int y = n-1;
    if(1 + calc(y) == res) {
        rec(n-1);
    } else {
        rec(rev(n));
    }
}

int main(){
    
    memset(dp, -1, sizeof dp);
    
    for(int n = 1; n <= (int)1e6; n++) {
        if(n == 1) {
            dp[n] = 1;
            continue;
        }
        int &res = dp[n];
        res = inf;
        int y = n-1;
        res = min(res, 1 + calc(y));
        y = rev(n);
        if(y < n && rev(y) == n) res = min(res, 1 + calc(y));
    }
    
    scanf("%d", &t);
    
    for(int i = 1; i <= t; i++) {
        scanf("%d", &n);
        printf("Case #%d: %d\n", i, dp[n]);
    }
    
    return 0;
}
