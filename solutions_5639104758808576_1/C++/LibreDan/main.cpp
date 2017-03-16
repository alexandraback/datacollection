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

#define PROBLEM "A"

template <class T>
void mout(T b, T e) {
#ifdef DEBUG
    for (T i = b; i != e; i++) {
        cout << *i << ' ';
    }
    cout << endl;
#endif
}

const int N = 2000;

char s[N];

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
        int h;
        scanf("%d", &h);
        scanf(" %s", s);
        int b = 0, ad = 0;
        for (int i = 0; i <= h; ++i) {
            if (i > b + ad) {
                ad += i - b - ad;
            }
            b += s[i] - '0';
        }
        printf("Case #%d: %d\n", tt, ad);
    }
	return 0;
}


