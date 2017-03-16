#include <bits/stdc++.h>

using namespace std;

#define all(c) ((c).begin()), ((c).end())
#define dump(c) cerr << "> " << #c << " = " << (c) << endl;
#define iter(c) __typeof((c).begin())
#define tr(i, c) for (iter(c) i = (c).begin(); i != (c).end(); i++)
#define REP(i, a, b) for (int i = a; i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define mp make_pair
#define fst first
#define snd second
#define pb push_back
#define debug(fmt, ...) \
        fprintf( stderr, \
                  fmt "\n", \
                  ##__VA_ARGS__ \
        )

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1 << 29;
const double EPS = 1e-10;

double zero(double d) {
    return d < EPS ? 0.0 : d;
}

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    return os << '(' << p.first << ',' << p.second << ')';
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &a) {
    os << '[';
    rep(i, a.size()) os << (i ? " " : "") << a[i];
    return os << ']';
}

string toString(int i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

const int MOD = 1000000007;

// a^k
ll fpow(ll a, ll k, int M) {
    ll res = 1ll;
    ll x = a;
    while (k != 0) {
        if ((k & 1) == 1)
            res = (res * x) % M;
        x = (x * x) % M;
        k >>= 1;
    }
    return res;
}

struct prepare {
    prepare() {
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(8);
        ios_base::sync_with_stdio(false);
    }
} _prepare;

int main() {

    int T;
    cin >> T;
    rep(_t, T) {
        int N;
        cin >> N;
        map<string, int> numA, numB;
        map<string, map<string, int> > hash;
        rep(i, N) {
            string a, b;
            cin >> a >> b;
            hash[a][b]++;
            numA[a]++;
            numB[b]++;
        }

        map<string, int> overA, overB;
        tr(it, numA)
            if (it->second != 0)
                overA[it->first] += it->second - 1;
        tr(it, numB)
            if (it->second != 0)
                overB[it->first] += it->second - 1;

        ll ans = 0;
        tr(it, overA) {
            tr(it2, overB) {
                while (it->second > 0 && it2->second > 0
                       && hash[it->first][it2->first] > 0) {
                    it->second--;
                    it2->second--;
                    ans++;
                }
            }
        }

        cout << "Case #" << _t + 1 << ": ";
        cout << ans;
        cout << endl;
    }

    return 0;
}