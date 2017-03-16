/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/5/8 17:23:42
 */
#include <vector>
#include <list>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

#define px first
#define py second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define clr(v, e) memset(v, e, sizeof(v))
#define rep(it, v) for (auto it : v)
#define forn(i, n) for (int i = 0; i < (n); ++ i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; -- i)
#define form(i, a, b) for (int i = (a); i <= (b); ++ i)
#define rform(i, a, b) for (int i = (b); i >= (a); -- i)
#define forv(i, v) for (int i = 0; i < sz(v); ++ i)
#define iter(it, v) for (auto it = v.begin(); it != v.end(); ++ it)

typedef long long lint;
typedef vector<int> vint;
typedef vector<string> vstring;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int maxn = 12;
const int MA = 10000;
const int MB = 100;

int t;
int J, P, S, K;

int vis[maxn][maxn][maxn];

int main() {
    freopen("heroming.out", "w", stdout);
    srand(time(NULL));
    scanf("%d", &t);
    form (cas, 1, t) {
        printf("Case #%d: ", cas);
        scanf("%d%d%d%d", &J, &P, &S, &K);
        vint w;
        form (i, 1, J) form (j, 1, P) form (k, 1, S) {
            w.pb(i * MA + j * MB + k);
        }
        vint ans;
        forn (p, 100000) {
            int n = sz(w);
            forn (i, n) {
                int k = rand() % n;
                swap(w[i], w[k]);
            }
            vint v;
            clr(vis, 0);
            bool change = 1;
            rep (it, w) {
                int i = it / MA;
                int j = it % MA / MB;
                int k = it % MB;
                if (vis[i][j][k]) continue;
                if (vis[i][j][0] == K || vis[i][0][k] == K || vis[0][j][k] == K) continue;
                ++ vis[i][j][0];
                ++ vis[i][0][k];
                ++ vis[0][j][k];
                ++ vis[i][j][k];
                v.pb(it);
            }
            if (sz(ans) < sz(v)) {
                ans.clear();
                rep (pt, v) {
                    ans.pb(pt);
                }
            }
        }
        printf("%d\n", sz(ans));
        rep (it, ans) {
            printf("%d %d %d\n", it / MA, it % MA / MB, it % MB);
        }
    }
    return 0;
}
