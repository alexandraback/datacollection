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

string c[123];
vector<int> v[123];
int u[123];
string ans;

void dfs(int x) {
    if (u[x]) return;
    ans += c[x];
    u[x] = 1;

    while(true) {
        string sm = "lol";
        for(int i = 0; i < v[x].size(); ++i) {
            if (u[v[x][i]]) continue;
            sm = min(sm, c[v[x][i]]);
        }
        if (sm == "lol") break;
        for(int i = 0; i < v[x].size(); ++i) {
            if (u[v[x][i]]) continue;
            if (sm == c[v[x][i]]) {
                dfs(v[x][i]);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    for(int T = 0; T < t; ++T) {
        ans = "";
        cout << "Case #" << T + 1 << ": ";

        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; ++i) {
            v[i].clear();
            cin >> c[i];
        }
        for(int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            v[x].pb(y);
            v[y].pb(x);
        }
        clr(u);
        string sm = c[0];
        int id = 0;
        for(int i = 1; i < n; ++i) {
            if (sm > c[i]) {
                sm = c[i];
                id = i;
            }
        }
        dfs(id);
        cout << ans << endl;
    }
    return 0;
};
