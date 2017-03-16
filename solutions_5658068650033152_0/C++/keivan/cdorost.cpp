#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define FOREACH(i, c) for(__typeof( (c).begin() ) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, n) for(__typeof(n) i = (a); i<(n); ++i)
#define REP(i, a, n) for(__typeof(n) i = (a); i<=(n); ++i)
#define ROF(i, n, a) for(__typeof(n) i = (n); i>=(a); --i)
#define error(n) cout << #n << " = " << n << endl
#define all(c) c.begin(), c.end()
#define pb push_back
#define po pop_back
#define Size(n) ((int)(n).size())
#define X first
#define Y second
#define scanf _ = scanf
// #define X real()
// #define Y imag()

typedef long long   ll ;
typedef long double ld ;
typedef pair<int,int> pii ;

const int maxn = 22;

int T;
int n, m, k;
bool a[maxn][maxn];
int close[maxn][maxn];
bool is[maxn][maxn];

bool notclosed(int r , int c) {
    if (a[r][c])
        return false;
    if (r == 0 || r == n-1 || c == 0 || c == m-1)
        return true;
    if (is[r][c])
        return false;
    is[r][c] = true;
    return notclosed(r-1,c)||notclosed(r+1,c)||notclosed(r,c-1)||notclosed(r,c+1);
}

int main() {
    cin >> T;
    REP (lv,1,T) {
        cin >> n >> m >> k;
        int ans = k;
        for (int i = 0 ; i < (1<<(n*m)) ; ++i) {
            int bit = __builtin_popcount(i);
            if (bit >= ans)
                continue;
            int cnt = 0;
            for (int r = 0 ; r < n ; ++r)
                for (int c = 0 ; c < m ; ++c) {
                    a[r][c] = ((i&(1<<cnt))?1:0);
                    ++cnt;
                }
            int num = 0;
            for (int r = 0 ; r < n ; ++r)
                for (int c = 0 ; c < m ; ++c) {
                    memset (is,false,sizeof(is));
                    if (!notclosed(r,c))
                        ++num;
                }
            if (num >= k)
                ans = bit;
        }
        cout << "Case #" << lv << ": " << ans << endl;
    }
    return 0 ;
}
