#define MAX 100005
#define inf 1e9
#include <stdio.h>
#include <math.h>
double p[MAX];
double cum[MAX];
double res[MAX];
int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int t,a,b,i;
    scanf("%d",&t);
    for(int cc=1;cc<=t;++cc){
        double mini=inf;
        scanf("%d%d",&a,&b);
        cum[0]=1.0;
        for(i=1;i<=a;++i){
            scanf("%lf",&p[i]);
            cum[i]=cum[i-1]*p[i];
        }
        res[0]=cum[a]*(b-a+1)+(1.0-cum[a])*(b-a+1+b+1);
        res[a+1]=1+b+1;
        for(i=1;i<=a;++i){
            res[i]=cum[a-i]*(i+b-a+1+i)+(1.0-cum[a-i])*(i+b-a+1+i+b+1);
        }
        for(i=0;i<=a+1;++i) if(res[i]<mini) mini=res[i];
        printf("Case #%d: %.15lf\n",cc,mini);
    }
    return 0;
}
