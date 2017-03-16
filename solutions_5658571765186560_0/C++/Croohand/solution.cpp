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
    for (int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": ";
        int x, n, m;
        cin >> x >> n >> m;
        if (n > m)
            swap(n, m);
        if (x == 1) {
            cout << "GABRIEL\n";
            continue;
        }
        if (x == 2) {
            if (n * m % 2 == 0)
                cout << "GABRIEL\n";
            else
                cout << "RICHARD\n";
            continue;
        }
        if (x == 4) {
            if (n * m % 4 == 0) {
                if (n <= 2)
                    cout << "RICHARD\n";
                else
                    cout << "GABRIEL\n";
            } else
                cout << "RICHARD\n";
            continue;
        }
        if (n * m % 3 == 0) {
            if (n == 1)
                cout << "RICHARD\n";
            else
                cout << "GABRIEL\n";
        } else
            cout << "RICHARD\n";
    }
    debug("%ld\n", clock());
    return 0;
}

