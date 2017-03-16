#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int now,total;
double p[100003];

double calc1(){
    double ret=1;
    for(int i=1;i<=now;++i)
        ret*=p[i];
    return ret*(total-now+1)+(1-ret)*(total-now+1+total+1);
}

double calc2(){
    return 1+total+1;
}

int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int _,cas=0;
    for(scanf("%d",&_);_--;){
        scanf("%d%d",&now,&total);
        for(int i=1;i<=now;++i)scanf("%lf",p+i);
        double ans1=calc1();
        double ans2=calc2();
        double ans=min(ans1,ans2);
        double tmp=1;
        for(int i=1;i<=now;++i){
            tmp*=p[i];
            ans=min(ans,tmp*(now-i+total-i+1)+(1-tmp)*(now-i+total-i+1+total+1));
        }
        printf("Case #%d: %.6f\n",++cas,ans);
    }
    return 0;
}
