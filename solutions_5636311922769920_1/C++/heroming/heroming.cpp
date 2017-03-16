/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/4/9 10:38:08
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
#define form(i, a, b) for (int i = (a); i <= (b); ++ i)
#define forv(i, v) for (int i = 0; i < sz(v); ++ i)
#define iter(it, v) for (auto it = v.begin(); it != v.end(); ++ it)

typedef long long lint;
typedef vector<int> vint;
typedef vector<string> vstring;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int maxn = 64;

lint v[maxn];
int t, n, m, s;

int main() {
    freopen("heroming.out", "w", stdout);
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++ cas) {
        printf("Case #%d:", cas);
        scanf("%d%d%d", &n, &m, &s);
        int cnt = (n + m - 1) / m;
        if (s < cnt) {
            printf(" IMPOSSIBLE\n");
        } else {
            if (n == 1) {
                printf(" 1\n");
            } else {
                v[m - 1] = 1;
                for (int i = m - 2; i >= 0; -- i) {
                    v[i] = v[i + 1] * n;
                }
                for (int k = 0; k < n; k += m) {
                    lint idx = 1;
                    for (int i = 0; i < m; ++ i) {
                        idx += min(n - 1, k + i) * v[i];
                    }
                    printf(" %I64d", idx);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
