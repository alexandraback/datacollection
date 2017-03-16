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
typedef unsigned long long ull;

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
    a = abs(a);
    b = abs(b);
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}


typedef ll ptdata;

struct pt {
    ptdata x, y;
    pt() {}
    pt(ptdata x, ptdata y) : x(x), y(y) {}

    pt operator - (const pt &r) const {
        return pt(x - r.x, y - r.y);
    }
    pt operator + (const pt &r) const {
        return pt(x + r.x, y + r.y);
    }
    pt operator * (const ld &r) const {
        return pt(x * r, y * r);
    }
    ptdata sqlen() const {
        return abs(x * x + y * y);
    }
    ld len() const {
        return sqrtl(sqlen());
    }

    bool operator < (const pt &r) const {
        if (x != r.x) return x < r.x;
        return y < r.y;
    }
    bool operator == (const pt &r) const {
        return x == r.x && y == r.y;
    }
};

ptdata cross(const pt &l, const pt &r) {
    return l.x * r.y - l.y * r.x;
}

ptdata dot(const pt &l, const pt &r) {
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

template<typename T>
inline T sqr(T x) {
    return x * x;
}


bool check(int v, const std::string &s) {
    vector<int> d(s.length(), 0);
    forn(i, s.length()) {
        d[i] = v % 10;
        v /= 10;
    }
    if (v > 0) return false;
    reverse(all(d));
    forn(i, s.length()) {
        if (s[i] == '?') continue;
        if (s[i] - '0' != d[i]) return false;
    }
    return true;
}

void print(int v,  const std::string &s) {
    vector<int> d(s.length(), 0);
    forn(i, s.length()) {
        d[i] = v % 10;
        v /= 10;
    }
    reverse(all(d));
    forn(i, s.length()) {
        cout << d[i];
    }
}

inline void solve(int test) {
    cout << "Case #" << test << ": ";
    string a, b;
    cin >> a >> b;
    vector<int> va, vb;
    forn(i, 1000) {
        if (check(i, a)) {
            va.pb(i);
        }
    }
    forn(j, 1000) {
        if (check(j, b)) {
            vb.pb(j);
        }
    }
    int ans = INT_MAX;
    int aa = 0, bb = INT_MAX;
    forn(i, va.size()) {
        forn(j, vb.size()) {
            if (abs(va[i] - vb[j]) < ans) {
                ans = abs(va[i] - vb[j]);
                aa = va[i];
                bb = vb[j];
            } else {
                if (abs(va[i] - vb[j]) > ans) continue;
                if (aa > va[i]) {
                    aa = va[i];
                    bb = vb[j];
                } else {
                    if (aa < va[i]) continue;
                    if (bb > vb[j]) {
                        aa = va[i];
                        bb = vb[j];
                    }
                }
            }
        }
    }
    print(aa, a);
    cout << " ";
    print(bb, b);
    cout << "\n";
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
    forn(i, t) {
        solve(i + 1);
    }

    cerr << "Time " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}
