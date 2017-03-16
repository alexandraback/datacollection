#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <deque>
#include <set>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

#define pb push_back
#define mp make_pair
#define F first
#define S second

#define foreach(i, c) for (typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

#ifdef LOCAL
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif // LOCAL

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int INF = int(1e9);
const ll INFll = 1ll * INF * INF;
const int MOD = 1000000007;

bool f1[10001], f2[10001][10001], f3[10001];

inline int mul(int a, int b) {
    int q1 = 1, q2 = 1;
    if (a < 0)
        q1 = -1, a *= -1;
    if (b < 0)
        q2 = -1, b *= -1;
    int q = q1 * q2;
    if (a == 0)
        return b * q;
    if (b == 0)
        return a * q;
    if (a == 1 || b == 1)
        return a * b * q;
    if (a == b)
        return -q;
    if (a == 2 && b == 3)
        return 4 * q;
    if (a == 2 && b == 4)
        return -3 * q;
    if (a == 3 && b == 2)
        return -4 * q;
    if (a == 3 && b == 4)
        return 2 * q;
    if (a == 4 && b == 2)
        return 3 * q;
    return -2 * q;
}

int cnv(char x) {
    if (x == 'i')
        return 2;
    if (x == 'j')
        return 3;
    return 4;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    int T;
    cin >> T;
    for (int O = 1; O <= T; ++O) {
        cout << "Case #" << O << ": ";
        int l, x;
        cin >> l >> x;
        string s;
        cin >> s;
        string tmp = s;
        for (int i = 0; i < x - 1; ++i)
            s += tmp;
        int cur = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int a = cnv(s[i]);
            cur = mul(cur, a);
            f1[i] = (cur == 2);
        }
        cur = 0;
        for (int i = n - 1; i >= 0; --i) {
            int a = cnv(s[i]);
            cur = mul(a, cur);
            f3[i] = (cur == 4);
        }
        for (int i = 0; i < n; ++i) {
            cur = 0;
            for (int j = i; j < n; ++j) {
                int a = cnv(s[j]);
                cur = mul(cur, a);
                f2[i][j] = (cur == 3);
            }
        }
        bool f = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 2; j < n; ++j)
                if (f || f1[i] && f3[j] && f2[i + 1][j - 1]) {
                    f = 1;
                    break;
                }
        if (f)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    debug("%ld\n", clock());
    return 0;
}

