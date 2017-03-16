#include <iostream>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 2010;
const int MAXM = 100100;//边数的最大值
int id;
map<string,int> mp;
set<int> l,r;
struct Node
{
    string a,b;
    void read()
    {
        cin>>a>>b;
    }
}p[MAXN];
struct Edge {
    int to,next;
} edge[MAXM];
int head[MAXN],tot;
void init() {
    tot = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v) {
    //cout << u << " : " << v << endl;
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
int linker[MAXN];
bool used[MAXN];
int uN;
bool dfs(int u) {
    for(int i = head[u]; i != -1 ; i = edge[i].next) {
        int v = edge[i].to;
        if(!used[v]) {
            used[v] = true;
            if(linker[v] == -1 || dfs(linker[v])) {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}
int hungary() {
    int res = 0;
    memset(linker,-1,sizeof(linker));
    for(int u = 0; u < uN; u++)
    {
        memset(used,false,sizeof(used));
        if(dfs(u))res++;
    }
    return res;
}


void solve() {
    int T,cnt = 0;
    cin>>T;
    while(T--) {
        int n;
        mp.clear();
        l.clear();
        r.clear();
        id = 0;
        scanf("%d",&n);
        int num = 0;
        for(int i = 0; i < n; ++i) {
            p[i].read();
            if(mp[p[i].a] == 0)
                mp[p[i].a] = id++;
            if(mp[p[i].b] == 0)
                mp[p[i].b] = id++;
        }
        init();
        for(int i = 0; i < n; ++i)
        {
            addedge(mp[p[i].a],mp[p[i].b]);
            l.insert(mp[p[i].a]);
            r.insert(mp[p[i].b]);
        }
        uN = id;
        int ans = hungary();
        ans = ans + n - (l.size() + r.size());
        printf("Case #%d: %d\n",++cnt,ans);
    }
}

int main() {
    freopen("in","r",stdin);
    freopen("A.out","w",stdout);
    solve();
    return 0;
}
