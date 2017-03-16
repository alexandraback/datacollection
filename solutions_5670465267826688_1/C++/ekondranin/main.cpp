#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define FOR(x, y, z) for (int x = (y); x < (z); ++x)
#define FORR(x, y, z) for (int x = (y); x > (z); --x)
#define GET(a, n) for (int i = 0; i < (n); ++i) cin >> a[i];
#define GETM(a, n, m) for (int i = 0; i < (n); ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
#define PRINTM(a, n, m) for (int i = 0; i < (n); ++i) { for (int j = 0; j < m; ++j) cout << a[i][j] << " ";  cout << endl; };
#define PRINT(a, n) for (int i = 0; i < (n); ++i) cout << a[i] << " ";
#define IT(a) a.begin(), a.end()
#define DEB(a) cout << #a << " = " << a << endl; cout.flush();
#define DEBA(a) for (auto i: a) cout << i << " "; cout << endl;
#define IFDEB(b, a) if (b) { cout << #a << " = " << a << endl; cout.flush(); }
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef vector <vector <int>> VVI;
typedef pair <int, int> PII;
const int MOD = 1000000007;
template <class T> typename T::value_type arr_sum(const T& v, int n) { typename T::value_type sum = 0; FOR(i, 0, n) sum += v[i]; return sum; }
struct Sync_stdio { Sync_stdio() { cin.tie(NULL); ios_base::sync_with_stdio(false); } } _sync_stdio;

int get_i(char c)
{
    if (c == 'i') {
        return 1;
    }
    if (c == 'j') {
        return 2;
    }
    return 3;
}

vector <vector <PII>> a = {{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
                            {{1, 0}, {0, 1}, {3, 0}, {2, 1}},
                            {{2, 0}, {3, 1}, {0, 1}, {1, 0}},
                            {{3, 0}, {2, 0}, {1, 1}, {0, 1}}};

PII mul(PII x, PII y)
{
    PII t = a[x.first][y.first];
    t.second = (t.second + x.second + y.second) % 2;
    return t;
}

PII bpow(PII &x, LL t)
{
    if (t == 0) {
        return {0, 0};
    }
    if (t % 2) {
        return mul(bpow(x, t - 1), x);
    }
    PII y = bpow(x, t / 2);
    return mul(y, y);
}

signed main()
{
    int t;
    cin >> t;
    FOR (k, 0, t) {
        LL l, x;
        cin >> l >> x;
        string s;
        cin >> s;
        PII elem = {0, 0};
        FOR (i, 0, s.size()) {
            elem = mul(elem, {get_i(s[i]), 0});
        }
        if (bpow(elem, x) != make_pair(0LL, 1LL)) {
            cout << "Case #" << k + 1 << ": NO" << endl;
            continue;
        }
        elem = {0, 0};
        int i = 0;
        for (; i < 200000; ++i) {
            elem = mul(elem, {get_i(s[i % s.size()]), 0});
            if (elem == make_pair(1LL, 0LL)) {
                break;
            }
        }
        if (elem != make_pair(1LL, 0LL)) {
            cout << "Case #" << k + 1 << ": NO" << endl;
            continue;
        }
        elem = {0, 0};
        int j = i + 1;
        for (; j < 400000; ++j) {
            elem = mul(elem, {get_i(s[j % s.size()]), 0});
            if (elem == make_pair(2LL, 0LL)) {
                break;
            }
        }
        if (elem != make_pair(2LL, 0LL)) {
            cout << "Case #" << k + 1 << ": NO" << endl;
            continue;
        }
        if (j >= l * x - 1) {
            cout << "Case #" << k + 1 << ": NO" << endl;
            continue;
        }
        cout << "Case #" << k + 1 << ": YES" << endl;
    }
}
