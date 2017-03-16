#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
#include <bitset>
#include <utility>
#include <list>
#include <numeric>

#include <cstdio>
#include <cmath>
#include <cctype>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
#define trav(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, pii> pdp;
typedef vector<int> vi;
int main()
{
    int tt; scanf("%d", &tt);
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    rep(sd,0,tt)
    {
        int h, n, m; scanf("%d %d %d", &h, &n, &m);
        int cei[n][m], flo[n][m];
        rep(i,0,n) rep(j,0,m)
            scanf("%d", &cei[i][j]);
        rep(i,0,n) rep(j,0,m)
            scanf("%d", &flo[i][j]);

        double vz[n][m];
        bool seen[n][m];
        rep(i,0,n) rep(j,0,m)
            seen[i][j] = false, vz[i][j] = 1e20;

        vz[0][0] = -100000000;
        set<pdp> q;
        q.insert(pdp(vz[0][0], pii(0, 0)));

        while (!q.empty())
        {
            pii u = q.begin()->second;
            double cur_time = q.begin()->first;
            q.erase(q.begin());
            seen[u.first][u.second] = true;

            rep(k,0,4)
            {
                int s = u.first + dx[k], t = u.second + dy[k];
                if (s < 0 || s >= n || t < 0 || t >= m || seen[s][t])
                    continue;
                int podlaha = max(flo[u.first][u.second], flo[s][t]);
                if (podlaha + 50 > cei[s][t])
                    continue;
                if (flo[s][t] + 50 > cei[u.first][u.second])
                    continue;

                double cas = (h - cei[s][t] + 50) / 10.;
                if (cas < 0)
                    cas = cur_time;
                else
                    cas = max(cur_time, cas);
                double need = cas;
                if (h - 10 * max(0., cas) >= 20 + flo[u.first][u.second])
                    need = 1 + cas;
                else
                    need = 10 + cas;

                if (!seen[s][t] && need < vz[s][t])
                {
                    q.erase(pdp(vz[s][t], pii(s, t)));
                    vz[s][t] = need;
                    q.insert(pdp(need, pii(s, t)));
                }
            }
        }

        double res = max(.0, vz[n - 1][m - 1]);
        printf("Case #%d: %.8lf\n", sd + 1, res);
    }
}
