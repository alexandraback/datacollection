#include <cstdio>
#include <cstring>
#define EPSILON 0.00000001
using namespace std;
double mind(double a, double b){
    if(a-b>EPSILON) return b;
    return a;
}
int t;
double x,y,a,b;
double cnt2,ans,p,temp;
int main(){
    scanf("%d",&t);
    for(x=1;x<=t;x++){
        scanf("%lf %lf",&a,&b);
        cnt2=2*b+a+2;
        ans=b+2;
        p=b+1;
        for(y=1;y<=a;y++){
            scanf("%lf",&temp);
            p*=temp;
            cnt2-=2;
            ans=mind(ans,cnt2-p);
        }
        printf("Case #%.0lf: %.6lf\n",x,ans);
    }
    return 0;
}
