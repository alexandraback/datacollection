#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <map>
#include <cassert>
#include <queue>
#include <set>

using namespace std;
#define ll long long
#define maxn 4100

int n;
int a[maxn];
string as[maxn];
string bs[maxn];
int b[maxn];
vector<int> G[maxn];
int match[maxn];
bool used[maxn];
int size;

bool dfs(int v) {
    used[v] = true;
    for (int i = 0; i < G[v].size(); ++i) {
        int u = G[v][i], w = match[u];
        if (w < 0 || !used[w] && dfs(w)) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int bm()
{
    int res = 0;
    memset(match, -1, sizeof(match));
    for (int v = 1; v <= size; ++v) {
        if (match[v] < 0) {
            memset(used, 0, sizeof(used));
            if (dfs(v)) res++;
        }
    }
    return res;
}



int main() {
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int T;
    cin >> T;
    int ca = 0;
    while (T--) {
        cin >> n;
        map<string, int> amap, bmap;
        size = 0;
        for (int i = 0; i <= 2 * n; ++i) G[i].clear();
        for (int i = 0; i < n; ++i) {
            cin >> as[i] >> bs[i];
            if (!amap.count(as[i])) amap[as[i]] = ++size;
            if (!bmap.count(bs[i])) bmap[bs[i]] = ++size;
            a[i] = amap[as[i]];
            b[i] = bmap[bs[i]];
            G[a[i]].push_back(b[i]);
            G[b[i]].push_back(a[i]);
        }
        int ans =n - size + bm();
        printf("Case #%d: %d\n", ++ca, ans);
    }
    return 0;
}



