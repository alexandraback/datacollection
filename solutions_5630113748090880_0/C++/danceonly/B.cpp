#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 105;

int a[N][N];
int mp[N][N];
vector<int> ans;
int vis[N];
int n;

void dfs(int cur) {
    if (cur > n) return ;
    vector<int> vec;
    int mi = INF;
    for (int i = 1; i < 2 * n; i++) {
        if (vis[i]) continue;
        if (a[i][cur] < mi) {
            mi = a[i][cur];
            vec.clear();
            vec.push_back(i);
        }else if (a[i][cur] == mi) {
            vec.push_back(i);
        }
    }
    map<int, int> cnt;
    if (vec.size() == 1) {
        for (int i = 1; i < 2 * n; i++) {
            if (vis[i]) continue;
            cnt[a[i][cur]] ++;
        }
        int id = vec[0];
        ans.push_back(a[id][cur]);
        for (int i = cur; i <= n; i++) {
            cnt[a[id][i]] --;
        }
        for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); ++ it) {
            if (it->second > 0)ans.push_back(it->first);
        }
        return ;
    }else {
        for (int i = 1; i < 2 * n; i++) {
            if (vis[i]) continue;
            cnt[a[i][cur]] ++;
        }
        for (int i = cur; i <= n; i++) {
            for (int j = 0; j < 2; j++) {
                int id = vec[j];
                if (cnt[a[id][i]] == 0) {
                    ans.push_back(a[id][i]);
                    vis[vec[j]] = 1;
                    vis[vec[j^1]] = 1;
                    dfs(cur + 1);
                    return ;
                }
                cnt[a[id][i]] --;
            }
        }
    }
    return ;
}

void work(int cas) {
    scanf("%d", &n);
    for (int i = 1; i < 2 * n; i++) {
        for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    }
    ans.clear();
    memset(vis, 0, sizeof(vis));
    dfs(1);
    printf("Case #%d:", cas);
    for (int i = 0; i < ans.size(); i++) printf(" %d", ans[i]); puts("");
    return ;
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        work(cas);
    }
    return 0;
}
