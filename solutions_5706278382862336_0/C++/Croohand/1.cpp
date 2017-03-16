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
#include <iomanip>
#include <ctime>
#include <fstream>

#define pb push_back
#define mp make_pair
#define F first
#define S second

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

ll gcd(ll x, ll y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    cin.tie(0);
    //ios_base::sync_with_stdio(0);
    #ifdef LOCAL
        freopen("A-small-attempt0.in", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    for (int o = 1; o <= t; ++o) {
        cout << "Case #" << o << ": ";
        ll p = 0, q = 0;
        string s;
        scanf("%I64d/%I64d", &p, &q);
        ll g = gcd(p, q);
        p /= g, q /= g;
        int k = 0, x = -1;
        while (q % 2 == 0) {
            k++;
            q /= 2;
            if (x == -1 && q <= p)
                x = k;
        }
        if (q > 1)
            cout << "impossible";
        else
            cout << x;
        cout << endl;
    }
    return 0;
}

