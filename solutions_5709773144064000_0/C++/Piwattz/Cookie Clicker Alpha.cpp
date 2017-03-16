#include<stdio.h>
#define inf 2000000000
double x,c,f;
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d", &t);
    for(int tt=1; tt<=t; tt++){
        int i, j, k;
        scanf("%lf %lf %lf",&c,&f,&x);
        double mn=x/2.0, pass=0, r=2.0;
       // printf("%lf %lf\n", x, mn);
        while(1){
            double m=pass+c/r+x/(r+f);
            if(mn<m)break;
            mn=m;pass+=c/r;r+=f;
        }
        printf("Case #%d: %lf\n",tt, mn);
    }
    return 0;
}
