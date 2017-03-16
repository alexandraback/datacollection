#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define LL long long
#define mxn 1005

string F[mxn], S[mxn];
map<string, int> mpF, mpS;
int cntF, cntS;

int lin[mxn];
bool used[mxn];
vector<int> g[mxn];

void init(int &n) {
    scanf("%d", &n);

    for (int i = 0; i < mxn; ++i) g[i].clear();
    mpF.clear();
    mpS.clear();
    cntF = cntS = 0;

    char f[100], s[100];
    for (int i = 0; i < n; ++i) {
        scanf("%s%s", f, s);
        F[i] = f, S[i] = s;
        if (!mpF.count(f)) mpF[f] = cntF++;
        if (!mpS.count(s)) mpS[s] = cntS++;
    }

    for (int i = 0; i < n; ++i) {
        g[mpF[F[i]]].push_back(mpS[S[i]]);
    }
}

bool dfs(int u) {
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (!used[v]) {
            used[v] = true;
            if (lin[v] == -1 || dfs(lin[v])) {
                lin[v] = u;
                return true;
            }
        }
    }
    return false;
}

int solve() {
    int ret = 0;
    memset(lin, -1, sizeof(lin));
    for (int u = 0; u < cntF; ++u) {
        memset(used, 0, sizeof(used));
        if (dfs(u)) ++ret;
    }
    return ret;
}

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c_out.txt", "w", stdout);

    int t, n, cas = 0;
    scanf("%d", &t);
    while (t--) {
        init(n);
        int tmp = solve();
        int ans = n - (cntF + cntS - tmp);
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}
