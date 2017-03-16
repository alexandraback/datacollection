#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

vector<int> g[55];
string code[55];
int n;
char buff[110];

void getthem() {
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        g[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%s", buff);
        code[i] = buff;
    }
    for (int i = 0; i < m; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

int order[55];
int now ;
int stack[55];
int dep;

bool dele[55], mark[55], old[55], vis[55];

bool smaller(int a, int b) { // a smaller than b
    if (a < 0) return false;
    if (b < 0) return true;
    return code[a] < code[b];
}

void dfs(int t) {
    if (mark[t] || old[t] || dele[t]) return;
    mark[t] = 1;
    for (size_t i = 0; i < g[t].size(); ++i)
        dfs(g[t][i]);
}

bool checkdel(int dd) {
    for (int i = 0; i <= n; ++i) dele[i] = mark[i] = 0;
    for (int i = dd; i <= dep; ++i)
        dele[stack[i]] = 1;
    for (int i = 1; i <= n; ++i)
        if (!old[i] && !dele[i]) {
            dfs(i);
            break;
        }
    for (int i = 1; i <= n; ++i)
        if (!old[i] && !mark[i] & !dele[i])
            return false;
    return true;
}

int minNeib(int t) {
    int ret = -1;
    for (size_t i = 0 ; i < g[t].size(); ++i) 
        if (!vis[g[t][i]])
            if (smaller(g[t][i], ret))
                ret = g[t][i];
    return ret;
}

void findmin() {
    int newdep, outbound = -1;
    int d = dep;
    while (d >= 1) {
        int k = minNeib(stack[d]);
        if (smaller(k, outbound)) {
            outbound = k;
            newdep = d;
        }
        if (d > 1 && checkdel(d)) 
            --d;
        else break;
    }
    for (int i = newdep + 1; i <= dep; ++i) 
        old[stack[i]] = 1;
    stack[dep = newdep + 1] = outbound;
    order[++now] = outbound;
    vis[outbound] = 1;
}


void work(int start) {
    order[now = 1] = start;
    stack[dep = 1] = start;
    for (int i = 0; i <= n; ++i) old[i] = vis[i] = 0;
    vis[start] = 1;
    for (int rd = 1; rd < n; ++rd) {
        findmin();
    }
}

string fuckthem() {
    int s = 1;
    for (int i = 1; i <= n; ++i) 
        if (code[i] < code[s])
            s = i;
    now = 0;
    work(s);
    string ret;
    for (int i = 1; i <= n; ++i)
        ret += code[order[i]];
    return ret;
}
    


int main() {
    int task; scanf("%d", &task);
    for (int cas = 1; cas <= task; ++cas) {
        getthem();
        string ans = fuckthem();
        printf("Case #%d: %s\n", cas, ans.c_str());
    }
    return 0;
}
