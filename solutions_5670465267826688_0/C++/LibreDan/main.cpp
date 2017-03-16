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

#define PROBLEM "C"

template <class T>
void mout(T b, T e) {
#ifdef DEBUG
    for (T i = b; i != e; i++) {
        cout << *i << ' ';
    }
    cout << endl;
#endif
}

struct quat {
    int sgn;
    char q;
    quat(int sgn = 1, char q = '1'): sgn(sgn), q(q) {}
    bool operator == (quat a) {
        return sgn == a.sgn && q == a.q;
    }
    bool operator != (quat a) {
        return sgn != a.sgn || q != a.q;
    }
};

quat operator * (quat a, quat b) {
    int sgn = a.sgn * b.sgn;
    if (a.q == '1') {
        return quat(sgn, b.q);
    }
    if (b.q == '1') {
        return quat(sgn, a.q);
    }
    if (a.q == b.q) {
        return quat(-sgn, '1');
    }
    if (a.q > b.q) {
        sgn *= -1;
        swap(a, b);
    }
    if (a.q == 'i' && b.q == 'j') {
        return quat(sgn, 'k');
    }
    if (a.q == 'i' && b.q == 'k') {
        return quat(-sgn, 'j');
    }
    if (a.q == 'j' && b.q == 'k') {
        return quat(sgn, 'i');
    }
}

const int N = 500500;

char s[N], s1[N];

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
        int l;
        ll x;
        scanf("%d %lld", &l, &x);
        scanf(" %s", s);
        x = min(x, x % 12 + 12);
        strcpy(s1, s);
        for (int i = 1; i < x; ++i) {
            strcat(s, s1);
        }
        l = x * l;
//        printf("%d %s\n",l, s);
        int l_id = 0;
        quat cur = quat();
        for (; l_id < l; ++l_id) {
            cur = cur * quat(1, s[l_id]);
            if (cur == quat(1, 'i')) {
                break;
            }
        }
        if (cur != quat(1, 'i')) {
            printf("Case #%d: NO\n", tt);
            continue;
        }
        int r_id = l - 1;
        cur = quat();
        for (; r_id >= 0; --r_id) {
            cur = quat(1, s[r_id]) * cur;
            if (cur == quat(1, 'k')) {
                break;
            }
        }
        if (cur != quat(1, 'k')) {
            printf("Case #%d: NO\n", tt);
            continue;
        }
//        printf("%d %d\n", l_id, r_id);
        cur = quat();
        for (int i = l_id + 1; i < r_id; ++i) {
            cur = cur * quat(1, s[i]);
        }
        if (cur != quat(1, 'j')) {
            printf("Case #%d: NO\n", tt);
            continue;
        }
        printf("Case #%d: YES\n", tt);
    }
	return 0;
}
