#include <bits/stdc++.h>

#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define for1(i, n) for(int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define prev asdfsdf
#define x first
#define y second

using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long i64;

template <class T>
bool remin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool remax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
struct pt {
    ll x, y;
    pt() {}
    pt(ll x, ll y) : x(x), y(y) {}

    pt operator - (const pt &r) const {
        return pt(x - r.x, y - r.y);
    }
    ll sqlen() const {
        return x * x + y * y;
    }
    bool operator < (const pt &r) const {
        if (x != r.x) return x < r.x;
        return y < r.y;
    }
    bool operator == (const pt &r) const {
        return x == r.x && y == r.y;
    }
};

ll cross(const pt &l, const pt &r) {
    return l.x * r.y - l.y * r.x;
}

ll dot(const pt &l, const pt &r) {
    return l.x * r.x + l.y * r.y;
}

ll pwmod(ll a, ll n, ll mod) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}


int getMask(long long val) {
    int res = 0;
    while (val) {
        res |= (1 << (val % 10));
        val /= 10;
    }
    return res;
}

inline void solve(int test) {
    cout << "Case #" << test << ": ";
    long long val;
    cin >> val;
    if (val == 0) {
        cout << "INSOMNIA\n";
        return;
    }
    int mask = 0;
    long long cv = 0;
    while (mask != ((1 << 10) - 1)) {
        cv += val;
        mask |= getMask(cv);
    }
    cout << cv << "\n";
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    cerr << "Time " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}
