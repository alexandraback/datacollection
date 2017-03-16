#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<ctime>
#include<bitset>
#define LL long  long
#define db double
#define EPS 1e-15
#define inf 1e9

using namespace std;

int flag[1010],b[1010];
int cas=1;
vector<int>a[1010];
int ans,P[1010];
void sou(int x){
    if (flag[b[x]]==0){
        flag[b[x]]=flag[x]+1;
        sou(b[x]);
    }
    else ans=max(ans,flag[x]-flag[b[x]]+1);
}
void fuck(int x){
    P[x]=1;
    flag[x]=1;
    for (int i=0;i<a[x].size();i++){
        int to=a[x][i];
        if (flag[to]==1) continue;
        fuck(to);
        P[x]=max(P[x],P[to]+1);
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        a[i].clear();
    }
    for (int i=1;i<=n;i++)
        a[b[i]].push_back(i);
    ans=0;
    for (int i=1;i<=n;i++){
        memset(flag,0,sizeof(flag));
        flag[i]=1;
        sou(i);
    }
    memset(flag,0,sizeof(flag));
    int cnt=0;
    for (int i=1;i<=n;i++){
        if (flag[i]==1) continue;
        if (b[b[i]]==i){
            flag[i]=1;
            flag[b[i]]=1;
            fuck(i);
            fuck(b[i]);
            cnt=cnt+P[i];
            cnt=cnt+P[b[i]];
        }
    }
    if (cnt>ans) ans=cnt;
    printf("Case #%d: %d\n",cas++,ans);
}
int main(){
    freopen ("1.in", "r", stdin);
    freopen ("1.out", "w", stdout);
    int T;
    scanf("%d",&T);
    while (T--){
        solve();
    }
    return 0;
}
