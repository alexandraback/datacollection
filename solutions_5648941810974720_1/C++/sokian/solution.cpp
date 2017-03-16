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


vector<string> V = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

const ld EPS = 1e-9;
const int INF = (int)1e9;

int gauss (vector < vector<ld> > a, vector<ld> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs(a[i][col]) > abs(a[sel][col]))
                sel = i;
        if (abs(a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                ld c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

inline void solve(int test) {
    cout << "Case #" << test << ":";
    int cnt[10][26];
    memset(cnt, 0, sizeof(cnt));
    forn(i, 10) {
        for (char c : V[i]) {
            cnt[i][c - 'A']++;
        }
    }
    string s;
    cin >> s;
    int cn[26];
    memset(cn, 0, sizeof(cn));
    for (char c : s) {
        cn[c - 'A']++;
    }
    vector<vector<ld> > A(26, vector<ld>(11, 0));
    forn(i, 26) {
        A[i][10] = cn[i];
        forn(j, 10) {
            A[i][j] = cnt[j][i];
        }
    }
    vector<ld> ans;
    int g = gauss(A, ans);
    assert(g == 1);
    cout << " ";
    forn(i, 10) {
        int c = int(ans[i] + 0.5);
        forn(j, c) {
            cout << i;
        }
    }
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
