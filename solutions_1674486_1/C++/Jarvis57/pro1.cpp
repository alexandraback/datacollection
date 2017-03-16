#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string>
using namespace std;
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define DOW(i, a, b) for(int i=a; i>=b; i--)
#define FOREACH(it, c) for(typeof(c.begin()) it=c.begin(); it!=c.end(); it++)
#define RESET(c, val) memset(c, val , sizeof(c))

int test, a[1005];
bool fr[1005], flag;
vector<int> s[1005];
int n, m, x;

void dfs(int u) {
    fr[u]=false;
    FOREACH(it, s[u]) if (!fr[*it]) {flag=true; return;}
        else dfs(*it);
}
int main() {
    freopen("1large.in", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> test;
    FOR(t, 1, test) {
        RESET(a, 0);
        scanf("%d", &n);
        FOR(i, 1, n) {
            s[i].clear();
            scanf("%d", &m);
            FOR(k, 1, m) scanf("%d", &x), s[i].push_back(x), a[x]++;
        }
        flag=false;
        FOR(i, 1, n) if (a[i]==0) {
            RESET(fr, true);
            flag=false;
            dfs(i);
            if (flag) break;
        }
        if (flag) printf("Case #%d: Yes\n", t);
            else printf("Case #%d: No\n", t);
    }
    //system("pause");
    return 0;
}
