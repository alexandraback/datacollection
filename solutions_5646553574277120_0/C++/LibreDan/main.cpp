#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fs first
#define sc second
#define mp make_pair
#define eb emplace_back

#define next _next
#define prev _prev
#define hash _hash
#define rank _rank
#define all(s) s.begin(), s.end()

#ifdef DEBUG
#define dout(x) cerr << x
#else
#define dout(x)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#define PROBLEM "B"

template <class T>
void mout(T b, T e) {
#ifdef DEBUG
    for (T i = b; i != e; i++) {
        cout << *i << ' ';
    }
    cout << endl;
#endif
}

const int N = 105;

set <int> y;
int c, d, v;

int gen(set <int> a, int min_x = 1) {
    if (int(a.size()) - int(y.size()) >= 6) return INF;
    set <int> g;
    g.insert(0);
    for (auto j : a) {
        if ((int) g.size() >= v + 1) return a.size();
        set  <int> new_g;
        for (int i = 0; i <= c; ++i) {
            for (auto h : g) {
                if (h + i * j <= v) {
                    new_g.insert(h + i * j);
                }
            }
        }
        g = new_g;
    }
    if ((int) g.size() >= v + 1) return a.size();
    int ans = INF;
    for (int i = min_x; i <= v; ++i) {
        if (!a.count(i)) {
            a.insert(i);
            ans = min(ans, gen(a, i + 1));
            a.erase(i);
        }
    }
    return ans;
}

int main()
{
#ifdef DEBUG
	assert(freopen(PROBLEM".in", "r", stdin) != NULL);
	assert(freopen(PROBLEM".out", "w", stdout));
#else
//	assert(freopen(PROBLEM".in", "r", stdin) != NULL);
//	assert(freopen(PROBLEM".out", "w", stdout));
#endif

    int t;
    cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        scanf("%d%d%d", &c ,&d, &v);
        y.clear();
        for (int i = 0; i < d; ++i) {
            int yy;
            scanf("%d", &yy);
            y.insert(yy);
        }
        printf("Case #%d: %d\n", tt, gen(y) - (int) y.size());
    }
	return 0;
}


