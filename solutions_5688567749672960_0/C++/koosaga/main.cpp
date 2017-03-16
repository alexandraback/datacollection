#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int n;

int rev(int n){
    int ret = 0;
    while (n) {
        ret *= 10;
        ret += n%10;
        n /= 10;
    }
    return ret;
}

bool vis[10000000];

queue<int> q,d;

void solve2(){
    scanf("%d",&n);
    while (!q.empty()) {
        q.pop();
        d.pop();
    }
    q.push(0);
    d.push(0);
    memset(vis,0,sizeof(vis));
    vis[0] = 1;
    while (!q.empty()){
        int qf = q.front();
        int df = d.front();
        if(qf == n){
            printf("%d\n",df);
            return;
        }
        q.pop();
        d.pop();
        if(!vis[rev(qf)]){
            vis[rev(qf)] = 1;
            q.push(rev(qf));
            d.push(df + 1);
        }
        if(!vis[qf + 1]){
            vis[qf + 1] = 1;
            q.push(qf + 1);
            d.push(df + 1);
        }
    }
}

int main(){
    freopen("A-small-attempt4.in","r",stdin);
    freopen("output","w",stdout);
    int t;
    scanf("%d",&t);
    for (int i=1; i<=t; i++) {
        printf("Case #%d: ",i);
        solve2();
    }
}