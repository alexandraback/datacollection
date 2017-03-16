#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const int MAXN = 2e5 + 1000;

enum quat {ONE = 1, I = 2, J = 3, K = 4};

int table[4][4] = {
    {ONE, I, J, K},
    {I, -ONE, K, -J},
    {J, -K, -ONE, I},
    {K, J, -I, -ONE}};
quat s[MAXN];
string str;
int sgn(int a) {
    if (a > 0)
        return 1;
    else
        return -1;
}
int mul(int a, int b) {
    return sgn(a) * sgn(b) * table[abs(a) - 1][abs(b) - 1];
}

int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	//freopen("", "w", stderr);
	
	int T;
	cin >> T;
	FOR(test, T) {
	    int l;
	    ll x;
	    cin >> l >> x;
	    cin >> str;
	    FOR(i, l) {
	        s[i] = quat(str[i] - 'i' + 2);
	    }
	    int res = x % 4;
	    while (res + 4 < 12 && res + 4 <= x)
	        res += 4;
	    x = res;
	    for (int r = 1; r <= x; ++r) {
	        FOR(i, l)
	            s[r * l + i] = s[i];
	    }
	    l = x * l;
	    int st = ONE;
	    int ipos = -1;
	    FOR(i, l) {
	        st = mul(st, s[i]);
//	        cerr << i <<' ' << st << '\n';
	        if (st == I) {
	            ipos = i;
	            break;
	        }
	    }
        int kpos = -1;
        st = ONE;
        for (int k = l - 1; k >= 0; --k) {
            st = mul(s[k], st);
//	        cerr << k <<' ' << st << '\n';
            if (st == K) {
                kpos = k;
                break;
            }
        }
  //      cerr << ipos << ' ' << kpos << '\n';
        cout << "Case #" << test + 1 << ": ";
        if (ipos == -1 || kpos == -1 || ipos >= kpos) {
            cout << "NO\n";
            continue;
        }
        st = ONE;
        for (int j = ipos + 1; j < kpos; ++j) {
            st = mul(st, s[j]);
        }
        if (st != J) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
	}



	return 0;
}

