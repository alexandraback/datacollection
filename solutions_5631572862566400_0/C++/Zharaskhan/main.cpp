#include <iostream>
#include <stdio.h>
#include <fstream>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <time.h>
#include <cassert>
#include <map>
#include <set>
#include <stack>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <bitset>

#include <complex>

//#include <unordered_map>
//#include <unordered_set>

#define llong long long int
#define pb push_back
#define mp make_pair
#define pr pair <int, int>
#define X first
#define Y second
#define endl "\n"
using namespace std;
//const int MAXN = 1e5 + 7;
//const int INF = 1e9 + 7;
//const llong LINF = 1e18;
//const llong MOD = 1e9 + 7;
//const long double EPS = 1e-18;
using namespace std;
int bff[1100];

int used[1100];
int L[1100];
int mxcycle;
vector<pair <int, int > > ST;
vector<int> tome[1100];

void dfs(int x, int p, int len) {
    used[x] = 1;
    L[x] = len;
    if (bff[x] == p) {
        ST.pb(mp(x, p));
    } else {
        int to = bff[x];
        if (!used[to]) {
            dfs(to, x, len + 1);
        } else if (used[to] == 1){
            mxcycle = max(mxcycle, L[x] - L[to] + 1);;
        }
    }
    used[x] = 2;
}
int mx = 0;
void dfs2(int x, int par, int len) {
    mx = max(len, mx);
    for (auto i: tome[x]) {
        if (i != par)
            dfs2(i, x, len + 1);
    }
}
int main() {
#ifdef DEBUG
    
    double beg = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
#else
    //freopen("centroid.in", "r", stdin);
    //freopen("centroid.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);cin.tie();
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            tome[i].clear();
        }
        ST.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &bff[i]);
            used[i] = 0;
            L[i] = 0;
            tome[bff[i]].pb(i);
            
        }
        mxcycle = 0;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                dfs(i, -1, 1);
            }
        }
        int ans = 0;
        for (auto i: ST) {
            mx = 0;
            dfs2(i.first, i.second, 2);
            ans += mx;
            mx = 0;
            dfs2(i.second, i.first, 0);
            ans += mx;
            //cerr << i.first << ' ' << i.second << ' ' << mx << '\n';
        }
        ans = max(ans, mxcycle);
        
        cout << "Case #"<< test << ": " << ans << '\n';
        
    }
#ifdef DEBUG
    double end = clock();
    fprintf(stderr, "\n*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
    return 0;
}