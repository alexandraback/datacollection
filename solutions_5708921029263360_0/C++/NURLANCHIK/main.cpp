#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#pragma comment(linker, "/STACK:64000000")

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define sqr(x) ((x) * (x))
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int N = 30;

int j, p, s;
int k;
vector <pair <int, pii>> v;
map <pii, int> cnt[3];

void solve() {
    cin >> j >> p >> s >> k;
    v.clear();
    for (int x = 1; x <= j; x++) {
        for (int y = 1; y <= p; y++) {
            for (int z = 1; z <= s; z++) {
                v.pb({x, {y, z}});
            }
        }
    }
    vector <pair <int, pii>> res;
    int mx = 0;
    for (int it = 1; it <= 1e4; it++) {
        random_shuffle(all(v));
        for (int i = 0; i < 3; i++) {
            cnt[i].clear();
        }
        int x, y, z;
        int sz = 0;
        for (int i = 0; i < sz(v); i++) {
            x = v[i].f;
            y = v[i].s.f;
            z = v[i].s.s;
            if (cnt[0][{x, y}] == k || cnt[1][{y, z}] == k || cnt[2][{x, z}] == k) {
                break;
            }
            cnt[0][{x, y}]++;
            cnt[1][{y, z}]++;
            cnt[2][{x, z}]++;
            sz++;
        }
        if (sz > mx) {
            mx = sz;
            res.clear();
            for (int i = 0; i < sz; i++) {
                res.pb(v[i]);
            }
        }
    }
    cout << sz(res) << "\n";
    for (pair <int, pii> it : res) {
        cout << it.f << " " << it.s.f << " " << it.s.s << "\n";
    }
}

int main() {
    freopen("/Users/nurlan/Dropbox/Programming/Google/googleSmall/googleSmall/input", "r", stdin);
    freopen("/Users/nurlan/Dropbox/Programming/Google/googleSmall/googleSmall/output", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cout << "Case #" << test << ": ";
        solve();
//        cout << "\n";
    }
    return 0;
}