/***********************************************\
 |Author: YMC
 |Created Time: 2015/5/10 19:14:46
 |File Name: C.cpp
 |Description: 
\***********************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)
#define mset(l,n) memset(l,n,sizeof(l))
#define rep(i,n) for(int i=0;i<n;++i)
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define srep(i,n) for(int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
int C,D,V;
int cas = 1;
map<int,int> vis;
int da[100];
int tot;
void dfs(int now,int t) {
    vis[now] = 1;
    if(now > V) return ;
    if(t >= tot) return ;
    for(int i=0;i<=C;++i) {
        vis[now + da[t]*i] = 1;
        dfs(now + da[t]*i,t + 1);
    }
}
void solve(int c,int d,int v) {
    //memset(vis,false,sizeof(vis));
    vis.clear();
    tot = D;
    //dfs(0,0);
    while(1) {
        dfs(0,0);
        bool fg = true;
        for(int i=1;i<=V;++i) {
            if(vis[i] == 0) {
                //cout<<i<<endl;
                da[tot ++] = i;
                fg = false;
                break;
            }
        }
        if(fg) break;
    }
    printf("Case #%d: %d\n",cas ++,tot - D);
}
int main() {
	freopen("C-small-attempt0.in","r",stdin); 
    freopen("out.txt","w",stdout); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d %d",&C,&D,&V);
        rep(i,D) {
            scanf("%d",&da[i]);
        }
        solve(C,D,V);
        //printf("Case #%d: %d\n",cas ++, solve(C,D,V));
    }
	return 0;
}

