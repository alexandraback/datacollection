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

int n;
string s;
vector<int> w;
vector<string> v;
int u[500];

int main() {
    int T;
    cin >> T;
    for(int TT = 0; TT < T; ++TT) {
        cout << "Case #" << TT + 1 << ": ";
        cin >> n;
        v.clear();
        w.clear();
        for(int i = 0; i < n; ++i) {
            cin >> s;
            v.pb(s);
            w.pb(i);
        }
        int ans = 0;
        do {
            s = "";
            for(int i = 0; i < n; ++i) {
                s += v[w[i]];
            }
            bool can = true;
            clr(u);
            for(int i = 1; i < sz(s); ++i) {
                u[s[i - 1]] = 1;
                if (s[i] != s[i - 1] && u[s[i]]) {
                    can = false;
                }
            }
            ans += can;
        } while(next_permutation(w.begin(), w.end()));
        cout << ans << endl;
    }
    return 0;
}
