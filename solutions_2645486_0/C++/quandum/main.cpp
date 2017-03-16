#include <cstdio>
#define maxn 10002
#define maxer 13
using namespace std;
int e,r,n,v[maxn],maxe;
long long f[maxer][maxn],res;
long long getmax(long long a,long long b){
    if (a>b) return a;
    else return b;
}
void process(){
    int i,j,k,af;
    for (i=0;i<maxer;i++)
        f[i][0]=-1;
    f[maxe][0]=0;
    for (i=1;i<=n;i++){
        for (j=0;j<=maxe;j++)  f[j][i]=-1;
        for (j=0;j<=maxe;j++)  if (f[j][i-1]>=0){
            for (k=0;k<=j;k++){
                af=j-k+r;
                if (af>maxe) af=maxe;
                f[af][i]=getmax((f[j][i-1]+(k*v[i])),f[af][i]);
            }
        }
    }
    res=f[0][n];
    for (i=1;i<=maxe;i++)
        res=getmax(res,f[i][n]);
}
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int ntest,i;        scanf("%d",&ntest);
    for (int test=1;test<=ntest;test++){
        scanf("%d%d%d",&maxe,&r,&n);
        for (i=1;i<=n;i++) scanf("%d",&v[i]);
        process();
        if (test>1) printf("\n");
        printf("Case #%d: %lld",test,res);
    }
    return 0;
}
