#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define eps 1e-8
int t,T;
double C,F,X;
double bST(double l,double r){
    double m;
    int i,j;
    double buildTime;
    double ans=r;
    while(l+eps<=r){
        m = (l+r)/2;
        for(j=0;;++j){
            for(i=buildTime=0;i<j;++i){
                buildTime += C/(2.0+F*i);
            }
            if( (buildTime>=m)||(m-buildTime)*(2.0+F*j)>=X ){
                break;
            }
        }
        if(buildTime>=m){
            l=m+eps;
        }else {
            if(m<ans)ans=m;
            r = m-eps;
        }
    }
    return ans;
}

int main(){
    scanf("%d",&T);
    for(t=1;t<=T;++t){
        scanf("%lf %lf %lf",&C,&F,&X);
        printf("Case #%d: %.7lf\n",t,bST(0.0,X/2.0));

    }

    return 0;
}
