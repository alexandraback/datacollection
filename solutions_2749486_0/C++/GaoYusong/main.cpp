#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> pii;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char to[256];


vector<int> bfs(int x, int y)
{
    vector<int> ret;
    map<pii, pair<pii, int> > fa;
    map<pii, int> dp;
    queue<pii> que;

    
    pii s = make_pair(0, 0), t = make_pair(x, y); 
    dp[s] = 0;
    fa[s] = make_pair(make_pair(-1, -1), -1);

    que.push(s);
    while (!que.empty()) {
        pii u = que.front();
        que.pop();
        int len = dp[u] + 1;
        if (len > 500 || u == t) {
            break;
        }
        for (int d = 0; d < 4; d++) {
            pii v = make_pair(u.first + dx[d] * len, u.second + dy[d] * len);
            if (dp.find(v) == dp.end()) {
                dp[v] = dp[u] + 1;
                fa[v] = make_pair(u, d);
                que.push(v);
            }
        }
    }

    pii p = t;

    while (fa[p].second != -1) {
        ret.push_back(fa[p].second);
        p = fa[p].first;
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    int T;
    int cn = 0;

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);

    scanf("%d", &T);

    to[0] = 'N';
    to[1] = 'E';
    to[2] = 'S';
    to[3] = 'W';

    while (T--) {
        int x, y;
        scanf("%d%d", &x, &y);

        vector<int> a = bfs(x, y);
        printf("Case #%d: ", ++cn);
        for (int i = 0; i < a.size(); i++) {
            printf("%c", to[a[i]]);
        }
        printf("\n");

    }
    return 0;
}
