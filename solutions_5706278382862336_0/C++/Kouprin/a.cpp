#pragma comment(linker, "/STACK:65000000")
#include <algorithm>
#include <cmath>
#include <cstdio> 
#include <cstring> 
#include <iostream> 
#include <map> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <string> 
#include <vector> 

using namespace std; 

template<class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long long lng;
typedef long double ld;
typedef stringstream istr;

#define TynKogep TOPCODER
#define bublic public:
#define pb push_back
#define sz(x) ((int)(x).size())
#define mp make_pair
#define first fi
#define second se
#define clr(a) memset((a),0,sizeof(a))

string s;
lng x, y;

int main() {
    int T;
    cin >> T;
    for(int TT = 0; TT < T; ++TT) {
        cout << "Case #" << TT + 1 << ": ";
        cin >> s;
        for(int i = 0; i < sz(s); ++i) {
            if (s[i] == '/') s[i] = ' ';
        }
        istringstream is(s);
        is >> x >> y;
        if (x > y) {
            cout << "impossible" << endl;
            continue;
        }
        lng g = __gcd(x, y);
        x /= g;
        y /= g;
        if (__builtin_popcount(y) == 1) {
            int ans = 0;
            while(y > 1) { ++ans; y /= 2; }
            while(x > 1) { --ans; x /= 2; }
            cout << ans << endl;
            continue;
        } else {
            cout << "impossible" << endl;
            continue;
        }
    }
    return 0;
};
