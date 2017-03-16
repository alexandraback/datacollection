#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxN=105;

int n,s,p;
int f[maxN];

void solve(){
    scanf("%d%d%d",&n,&s,&p);
    int a,g0,g1;
    memset(f,0x8f,sizeof f);
    f[0]=0;
    for (int i=1;i<=n;i++){
        scanf("%d",&a);
        g0=(a+2)/3; g1=(a+4)/3;
        for (int k=s;k>0;k--){
            f[k]+=(g0>=p);
            if (g1<=10&&g1>=2)
                f[k]=max(f[k],f[k-1]+(g1>=p));
        }
        f[0]+=(g0>=p);
    }
    printf("%d\n",f[s]);
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; scanf("%d",&t);
    for (int i=1;i<=t;i++){
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}
