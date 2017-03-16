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

const int maxn = 64;

int t;
lint n, m;
lint v[maxn];
char c[maxn][maxn];

int main() {
    freopen("heroming.out", "w", stdout);
    v[2] = 1;
    v[0] = v[1] = 0;
    form (k, 3, 50) {
        v[k] = v[k - 1] << 1;
    }
    scanf("%d", &t);
    form (cas, 1, t) {
        printf("Case #%d: ", cas);
        scanf("%I64d%I64d", &n, &m);
        if (m > v[n]) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        printf("POSSIBLE\n");
        clr(c, 0);
        forn (i, n) forn (j, n) c[i][j] = '0';
        form (i, 1, n - 1) {
            form (j, i + 1, n - 1) {
                c[i][j] = '1';
            }
        }
        if (m == v[n]) {
            form (i, 1, n - 1) {
                c[0][i] = '1';
            }
        } else {
            for (int k = n - 1; k > 1; -- k) {
                if (v[k] <= m) {
                    m -= v[k];
                    c[0][n - k] = '1';
                }
            }
            if (m) {
                c[0][n - 1] = 1;
            }
        }
        forn (i, n) printf("%s\n", c[i]);
    }
    return 0;
}
