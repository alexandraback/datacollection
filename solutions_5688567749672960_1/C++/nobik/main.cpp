//#pragma comment(linker,"/STACK:100000000000,100000000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <stack>
#include <set>
#include <iomanip>
#include <queue>
#include <map>
#include <functional>
#include <list>
#include <sstream>
#include <ctime>
#include <climits>
#include <bitset>
#include <list>
#include <cassert>
#include <complex>

using namespace std;

/* Constants begin */
const long long inf = 2e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-12;
const double PI = 2*acos(0.0);
const double E = 2.71828;
/* Constants end */

/* Defines begin */
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define double long double
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define forn(i,n) for (int (i)=0; (i)<(n); ++(i))
#define random (rand()<<16|rand())
#define sqr(x) (x)*(x)
#define base complex<double>
#define sz(a) (int)(a).size()
/* Defines end */

int t;

long long f[1000005];

ll getr(ll x) {
    ll r = 0;
    while (x > 0) {
        r = r * 10 + x % 10;
        x /= 10;
    }
    return r;
}

ll getLen(ll x) {
    ll r = 0;
    while (x) {
        ++r;
        x /= 10;
    }
    return r;
}

bool check(ll x, int num) {
    if (x % 10 != 1) return false;
    x /= 10;
    for (int i = 0; i < num; ++i) {
        if (x % 10 != 0) {
            return false;
        }
        x /= 10;
    }
    return true;
}

ll Set(ll x, int num) {
    x /= 10;
    for (int i = 0; i < num; ++i) {
        x /= 10;
    }
    for (int i = 0; i < num; ++i) {
        x *= 10;
    }
    x *= 10;
    ++x;
    return x;
}

ll calc(ll x) {
    ll r = 0;
    while (x >= 1) {
        if (getLen(x) == 1) {
            --x;
            ++r;
            continue;
        }
        int num = (getLen(x) + 1) / 2 - 1;
        if (check(x, num) && getr(x) < x) {
            x = getr(x);
            ++r;
        } else {
            if (Set(x, num) < x) {
                r += x - Set(x, num);
                x = Set(x, num);
            } else {
                --x;
                ++r;
            }
        }
    }
    return r;
}

void pre() {
    f[1] = 1;
    for (int i = 2; i <= 1000000; ++i) {
        f[i] = f[i - 1] + 1;
        if (i % 10 != 0 && getr(i) < i) {
            f[i] = min(f[i], f[getr(i)] + 1);
        }
    }
}

void gen() {
    freopen("input.txt", "w", stdout);
    srand(time(NULL));
    cout << 100 << endl;
    for (int i = 0; i < 100; ++i) {
        ll x = 1LL * random * random % 100000000000000;
        cout << x << endl;
    }
    exit(0);
}

int main(void) {
    #ifdef nobik
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
   // gen();
    pre();
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        cerr << i << endl;
        long long x; cin >> x;
        cout << "Case #" << i << ": " << calc(x) << "\n";
    }
    return 0;
}
