#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fs first
#define sc second
#define mp make_pair

#define next _next
#define prev _prev
#define hash _hash
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

#define PROBLEM "D"

template <class T>
void mout(T b, T e) {
#ifdef DEBUG
    for (T i = b; i != e; i++) {
        cout << *i << ' ';
    }
    cout << endl;
#endif
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
        int x, r, c;
        scanf("%d %d %d", &x, &r, &c);
        if ((r * c) % x != 0 || x >= 7) {
            printf("Case #%d: RICHARD\n", tt);
            continue;
        }
        if (x == 1) {
            printf("Case #%d: GABRIEL\n", tt);
            continue;
        }
        if (r > c) swap(r, c);
        if (x > c) {
            printf("Case #%d: RICHARD\n", tt);
            continue;
        }
        if (r == 1) {
            if (x >= 3) {
                printf("Case #%d: RICHARD\n", tt);
                continue;
            }
            else {
                printf("Case #%d: GABRIEL\n", tt);
                continue;
            }
        }
        if (r == 2) {
            if (x >= 4) {
                printf("Case #%d: RICHARD\n", tt);
                continue;
            }
            else {
                printf("Case #%d: GABRIEL\n", tt);
                continue;
            }
        }
        if (r == 3) {
            if ((x == 5 && c == 5) || x >= 6) {
                printf("Case #%d: RICHARD\n", tt);
                continue;
            }
            else {
                printf("Case #%d: GABRIEL\n", tt);
                continue;
            }
        }
        printf("Case #%d: GABRIEL\n", tt);
    }
	return 0;
}


