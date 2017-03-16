#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#pragma comment(linker, "/STACK:1024000000,1024000000")

#define     IT              iterator
#define     PB(x)           push_back(x)
#define     CLR(a,b)        memset(a,b,sizeof(a))

using namespace std;

typedef     unsigned int            uint;
typedef     long long               ll;
typedef     unsigned long long      ull;
typedef     vector<int>             vint;
typedef     vector<ll>              vll;
typedef     vector<ull>             vull;
typedef     set<int>                sint;
typedef     set<ull>                sull;

const int maxn = 1000000 + 5;
int n,m1,m2;
int fa[maxn];
vint G[maxn];
int in[maxn];

void init(int n) {
    for (int i = 0; i <= n; i++) in[i] = 0;
    for (int i = 0; i <= n; i++) G[i].clear();
    for (int i = 0; i <= n; i++) fa[i] = i;
}

int getf(int x) {
    if (fa[x] == x) return x;
    else return fa[x] = getf(fa[x]);
}

bool unit(int x,int y) {
    x = getf(x);
    y = getf(y);
    if (x == y) return false;
    if (x > y) fa[x] = y;
    else fa[y] = x;
    return true;
}

bool vis[maxn];

bool topsort(int n) {
    //for (int i = 1; i <= n; i++) vis[i] = false;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i] && !G[i].empty()) q.push(i);
    }
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        for (int i = 0; i < G[tmp].size(); i++) {
            in[G[tmp][i]]--;
            if (!in[G[tmp][i]]) q.push(G[tmp][i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] > 0) return false;
    }
    return true;
}

int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d",&n,&m1,&m2);
        //cout<<m1<<m2<<endl;
        init(n);
        //cout<<m1<<m2<<endl;
        bool flag = true;
        for (int i = 0; i < m1; i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            if (!flag) continue;
            else flag = unit(u,v);
        }
        //cout<<"shit"<<endl;
        for (int i = 0; i < m2; i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            if (!flag) continue;
            int x = getf(u);
            int y = getf(v);
            G[x].PB(y);
            in[y]++;
        }
        //for (int i = 1; i <= n; i++) cout<<in[i]<<endl;
        //cout<<"shit"<<endl;
        if (flag) {
            if (!topsort(n)) printf("YES\n");
            else printf("NO\n");
        }
        else printf("YES\n");
    }
}
