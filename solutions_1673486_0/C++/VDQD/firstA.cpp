#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int k,n;

void solve(){
    scanf("%d%d",&k,&n);
    //printf("k=%d,n=%d\n",k,n);
    double x=1.0,p,res=n+2;
    for (int u=k-1;u>=0;u--){
        scanf("%lf",&p);
        x*=p;
        //printf("%d:%.4lf,%.4lf\n",u,p,x);
        res=min(res,x*(n-k+2*u+1)+(1-x)*(2*n-k+2*u+2));
    }
    printf("%.8lf\n",res);
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}
