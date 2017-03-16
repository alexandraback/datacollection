#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int d[MAX];
vector<int> digit(int x) {
    vector<int> res;
    while (x>0) {
        res.push_back(x%10);
        x/=10;
    }
    return (res);
}
void dfs(void) {
    memset(d,-1,sizeof d);
    queue<int> q;
    d[1]=1;
    q.push(1);
    while (!q.empty()) {
        int u=q.front();q.pop();
        if (u+1<MAX && d[u+1]<0) {
            d[u+1]=d[u]+1;
            q.push(u+1);
        }
        vector<int> dig=digit(u);
        int x=0;
        REP(i,dig.size()) x=x*10+dig[i];
        if (x<MAX && d[x]<0) {
            d[x]=d[u]+1;
            q.push(x);
        }
    }
}
int main(void) {
    dfs();
    int t;
    scanf("%d",&t);
    FOR(i,1,t) {
        int x;
        scanf("%d",&x);
        printf("Case #%d: %d\n",i,d[x]);
    }
    return 0;
}
