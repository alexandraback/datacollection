#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a,b,res,m;
int p[10];

void process(int n){
    int c[10];
    for (int i=1;i<m;i++)
        c[i]=(n%p[i])*p[m-i]+n/p[i];
    c[0]=0;
    sort(c+1,c+m);
    for (int i=1;i<m;i++)
        if (c[i]!=c[i-1]&&c[i]>=a&&c[i]<n) res++;
}

void solve(){
    scanf("%d%d",&a,&b);
    res=0; m=0;
    for (int i=0;i<10;i++) if (a>=p[i]) m=i+1;
    for (int i=a;i<=b;i++){
        process(i);
        //printf("%d: res=%d\n",i,res);
    }
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; scanf("%d",&t);
    p[0]=1; for (int i=1;i<10;i++) p[i]=p[i-1]*10;
    for (int i=1;i<=t;i++){
        solve();
        printf("Case #%d: %d\n",i,res);
    }
    return 0;
}
