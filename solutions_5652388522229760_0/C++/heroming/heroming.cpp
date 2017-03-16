/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/4/9 8:54:38
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

const int maxn = 1000000;
const int maxm = 12;

int n;
bool v[maxm];

int solve(const int x) {
    clr(v, 1);
    int cnt = 0;
    for (int i = 1; i <= 100; ++ i) {
        int w = x * i;
        while (w) {
            int e = w % 10;
            w /= 10;
            if (v[e]) {
                v[e] = 0;
                ++ cnt;
                if (cnt == 10) {
                    return x * i;
                }
            }
        }
    }
    return -1;
}

int main() {
    freopen("heroming.out", "w", stdout);
    int cas = 0;
    scanf("%d", &cas);
    for (int l = 1; l <= cas; ++ l) {
        scanf("%d", &n);
        int ans = solve(n);
        if (ans == -1) {
            printf("Case #%d: INSOMNIA\n", l);
        } else {
            printf("Case #%d: %d\n", l, ans);
        }
    }
    
    return 0;
}
