#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


const int MAX = 1500;
vector<int> G[MAX];
int par[MAX];
char s1[100], s2[100];

bool used[MAX];

bool find(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int i = 0; i < G[v].size(); ++i) {
        int nxt = G[v][i];
        if (par[nxt] == -1 || find(par[nxt])) {
            par[nxt] = v;
            return true;
        }
    }
    return false;
}

void solve() {
    for (int i = 0; i < MAX; ++i) {
        G[i].clear();
        par[i] = -1;
    }
    int n;
    scanf("%d", &n);
    map<string, int> n1, n2;
    for (int i = 0; i < n; ++i) {
        scanf("%s%s", s1, s2);
        int a = 0, b = 0;
        if (n1.find(s1) != n1.end()) {
            a = n1[s1];
        } else {
            a = n1.size();
            n1[s1] = a;
        }
        if (n2.find(s2) != n2.end()) {
            b = n2[s2];
        } else {
            b = n2.size();
            n2[s2] = b;
        }
        G[a].push_back(b);
    }
    int required = n1.size() + n2.size();
    for (int i = 0; i < n1.size(); ++i) {
        memset(used, false, sizeof(used));
        if (find(i)) {
            --required;
        }
    }
    printf("%d\n", n - required);
}

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}