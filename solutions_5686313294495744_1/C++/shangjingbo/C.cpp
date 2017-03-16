#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

const int MAXN = 1000;

int match[MAXN];
vector<int> adj[MAXN];
bool mark[MAXN];

int getID(unordered_map<string, int> &h, string x)
{
    if (h.count(x)) {
        return h[x];
    }
    int id = h.size();
    return h[x] = id;
}

bool find(int x)
{
    for (int i = 0; i < adj[x].size(); ++ i) {
        int y = adj[x][i];
        if (!mark[y]) {
            mark[y] = true;
            if (match[y] == -1 || find(match[y])) {
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int tests, test = 1;
    for (scanf("%d", &tests); test <= tests; ++ test) {
        int n;
        scanf("%d", &n);
        unordered_map<string, int> ha, hb;
        for (int i = 0; i < n; ++ i) {
            adj[i].clear();
        }
        for (int i = 0; i < n; ++ i) {
            char sa[100], sb[100];
            scanf("%s%s", &sa, &sb);
            int a = getID(ha, sa);
            int b = getID(hb, sb);
            adj[a].push_back(b);
        }

        memset(match, -1, sizeof(match));
        int ans = ha.size() + hb.size();
        for (int i = 0; i < ha.size(); ++ i) {
            memset(mark, false, sizeof(mark));
            if (find(i)) {
                -- ans;
            }
        }
        printf("Case #%d: %d\n", test, n - ans);
    }
    return 0;
}
