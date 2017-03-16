#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

const int64 MAXN = 2000000;

int64 n, t[4 * MAXN];

void init(int64 val) {
    n = val; 
    for (int64 i = 0; i < 4 * MAXN; ++i)
        t[i] = 0;
}

int64 get_min(int64 left, int64 right) {
    int64 result = 1000000000;
    for (int64 i = left; i <= right; ++i)
         result = min(result, t[i]);
    return result;
}

void set_max(int64 left, int64 right, int64 val) {
    for (int64 i = left; i <= right; ++i)
         t[i] = max(t[i], val);
}


void solve() {
    int64 n;
    cin >> n;
    vector<int64> left, right, s, date;
    set<int64> coords;
    for (int64 i = 0; i < n; ++i) {
         int64 di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
         cin >> di >> ni >> wi >> ei >> si >> delta_di >> delta_pi >> delta_si;
         for (int64 j = 0; j < ni; ++j) {
              left.pb(wi);
              right.pb(ei - 1);
              s.pb(si);
              date.pb(di);
              coords.insert(wi - 1);
              coords.insert(wi);
              coords.insert(wi + 1);
              coords.insert(ei - 1);
              coords.insert(ei);
              coords.insert(ei + 1);
              wi += delta_pi;
              ei += delta_pi;
              si += delta_si;
              di += delta_di;
         }
    }
    
    int64 num = 0;
    map<int64, int64> val;
    for (set<int64>::iterator it = coords.begin(); it != coords.end(); ++it) {
        val[*it] = num;
        ++num;
    }
    map<int64, vector<pair<pair<int64, int64>, int64> > > tasks;
    for (int64 i = 0; i < sz(left); ++i) {
        tasks[date[i]].pb(mp(mp(val[left[i]], val[right[i]]), s[i]));
    }
    int64 ans = 0;
    init(val.size());
    for (map<int64, vector<pair<pair<int64, int64>, int64> > >::iterator it = tasks.begin(); it != tasks.end(); ++it) {
         vector<pair<pair<int64, int64>, int64> > a = it->second;
         for (int64 i = 0; i < sz(a); ++i) {
     //        cout << it->first << " " << a[i].first.first << " " << a[i].first.second << " " << a[i].second << endl;
              if (get_min(a[i].first.first, a[i].first.second) < a[i].second)
                  ++ans;
         }
         for (int64 i = 0; i < sz(a); ++i)
              set_max(a[i].first.first, a[i].first.second, a[i].second);
    }
    cout << ans << endl;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
