#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string.h>
#include <queue>
#include <cstdio>
#include <cassert>
#include <deque>
#include <stack>
#include <utility>
#include <numeric>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, l, r) for (int i = (int)(l); i < (int)(r); i++)
#define forv(i, v) forn(i, v.size())

#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

struct Runner {
    ll dist;
    ll time;
    Runner() {}
    Runner(ll dist, ll time) : dist(dist), time(time) {}
};

void solveCase(int tc) {
    cerr << tc << endl;
    printf("Case #%d: ", tc);
    int g;
    cin >> g;
    vector<Runner> runner;
    forn(i, g) {
        ll d, m;
        int h;
        cin >> d >> h >> m;
        forn(j, h) {
            runner.push_back(Runner(d, m + j));
        }
    }
    ll ans = 1e18;
    int n = runner.size();
    forn(mask, (1 << n)) {
        ll timeUp = 1e18;
        ll timeDown = 0;
        ll cur = 0;
        forn(i, n) {
            if (mask & (1 << i)) {
                timeUp = min(timeUp, runner[i].time * (360 - runner[i].dist));
                cur++;
            } else {
                timeDown = max(timeDown, runner[i].time * (360 - runner[i].dist));
            }
        }
        if (timeDown > timeUp) continue;
        forn(i, n) {
            if (!(mask & (1 << i))) {
                cur += (timeDown - runner[i].time * (360 - runner[i].dist)) / (runner[i].time * 360);
            }
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;
}

int main() {
#ifdef NEREVAR_PROJECT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc; cin >> tc;
    forn(it, tc) solveCase(it + 1);
    return 0;
}
