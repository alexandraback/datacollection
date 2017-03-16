#include <cstdio>
#include <cstring>
#define EPSILON 0.00000001
using namespace std;
double t,x,n,sum;
int y;
double sc[205];
double bsearch(double s, double e){
    if(s-e<EPSILON&&e-s<EPSILON) return s;
    double m=(s+e)/2.0,ans=0.0;
    for(int i=0;i<n;i++){
        if(m-sc[i]>EPSILON) ans+=m-sc[i];
    }
    if(ans-sum>EPSILON||ans-sum<EPSILON&&sum-ans<EPSILON) return bsearch(s,m);
    return bsearch(m+EPSILON,e);
}
int main(){
    scanf("%lf",&t);
    for(x=1;x<=t;x++){
        sum=0.0;
        scanf("%lf",&n);
        for(y=0;y<n;y++){
            scanf("%lf",&sc[y]);
            sum+=sc[y];
        }
        printf("Case #%.0lf:",x);
        for(y=0;y<n;y++){
            if(sc[y]>=2*sum/n) printf(" 0.000000");
            else printf(" %.6lf",(bsearch(sc[y],2*sum/n)-sc[y])*100.0/sum);
        }
        printf("\n");
    }
    return 0;
}
