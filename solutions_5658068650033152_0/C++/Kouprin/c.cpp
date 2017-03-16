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

int n, m, ans, k;
int a[23][23];

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (a[x][y]) return;
    a[x][y] = 2;
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

bool check() {
    for(int i = 0; i < n; ++i) {
        if (!a[i][0]) dfs(i, 0);
        if (!a[i][m - 1]) dfs(i, m - 1);
    }
    for(int i = 0; i < m; ++i) {
        if (!a[0][i]) dfs(0, i);
        if (!a[n - 1][i]) dfs(n - 1, i);
    }
    int loc = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if (a[i][j] < 2) ++loc;
        }
    }
    return loc >= k;
}

int main() {
    int T;
    cin >> T;
    for(int TT = 0; TT < T; ++TT) {
        cout << "Case #" << TT + 1 << ": ";
        ans = 1000;
        cin >> n >> m >> k;
        int p = n * m;
        for(int x = 0; x < (1 << p); ++x) {
            int q = 0;
            int cur = x;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    a[i][j] = cur & 1;
                    if (a[i][j]) ++q;
                    cur /= 2;
                }
            }
            if (q < ans && check()) ans = q;
        }
        cout << ans << endl;
    }
    return 0;
};
