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
        int n;
        cin >> n;
        int ans = 0;
        string s;
        cin >> s;
        int cur = 0;
        for (int i = 0; i <= n; ++i) {
            int a = s[i] - '0';
            if (cur < i)
                ans += i - cur, cur = i;
            cur += a;
        }
        cout << ans << endl;
    }
    debug("%ld\n", clock());
    return 0;
}

