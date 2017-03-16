#include<algorithm>
#include<cstdio>
using namespace std;
int T;
long long a,ed;
double b;
double cal(double x){
    double r = (double)(a);
        return (x)*(2*r+1.0)+2.0*(x-1.0)*x;
}
long long BS(long long f,long long l,double key){
    if(f > l) return -1;
    long long m = (f+l)/2;
    if(cal((double)(m)) > key+1e-13){
        return BS(f,m-1,key);
    }
    return max(m,BS(m+1,l,key));
}
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    ed = 1LL<<50;
    scanf("%d",&T);
    for(int r = 1;r<=T;r++){
        scanf("%lld %lf",&a,&b);
        printf("Case #%d: %lld\n",r,BS(1,ed,b));
    }
    return 0;
}
//
