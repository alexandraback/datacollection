#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <set>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <map>
using namespace std;

#define forn(i,n) for(int i = 0; i < (int)n; ++i)
#define _mp(a,b) make_pair(a,b)
#define _pb(x) push_back(x)
#define mins(a,b) a = min(a,b)
#define maxs(a,b) a = max(a,b)

int const MAXN = 25;
int arr[MAXN][MAXN] = {};
int n,m,k;

int tmp[MAXN][MAXN];

pair<int,int> q[MAXN*MAXN];

inline int tes()
{
    forn(i,n)
        forn(j, m)
            tmp[i][j] = 0;
    int len = 0;
    forn(i,n)
        forn(j, m)
            if (i == 0 || j == 0 || i == n-1 || j == m-1)
                if (!arr[i][j])
                {
                    q[len++]  = _mp(i,j);
                    tmp[i][j] = 1;
                }

    int index = 0;
    while (index < len)
    {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int curx = q[index].first;
        int cury = q[index].second;
        forn(k,4)
        {
            int nextx = curx + dx[k];
            int nexty = cury + dy[k];
            if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && tmp[nextx][nexty] == 0 && arr[nextx][nexty] == 0)
            {
                tmp[nextx][nexty] = 1;
                q[len++] = _mp(nextx, nexty);
            }
        }
        ++index;
    }
    return len;
}

int main() {
   ios_base::sync_with_stdio(false);
//    cout << fixed;
//    cout << setprecision(9);
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int T = 0;
    cin >> T;
    forn(test, T)
    {
        cout << "Case #" << test + 1 << ": ";
        cin >> n >> m >> k;
        int ans = n*m+1;
        int cnt = n*m;
        int mask = 1 << cnt;
        forn(i,  mask)
        {
            int cur = 0;
            forn(j, cnt)
            {
                arr[j/m][j%m] = i & (1 << j);
                if (i & (1 << j))
                    ++cur;
            }
            int t = cnt - tes();
            if (t >= k)
                mins(ans, cur);

        }
        cout << ans << "\n";

    }

    return 0;
}
