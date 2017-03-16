#include<stdio.h>
#include<math.h>
double C,F,X;
double calc(double k){
    return C/(2+(k-1)*F) + (X/(2+k*F) - X/(2+(k-1)*F));
}
int main(){
    int T;
    scanf("%d",&T);
    for(int _ = 0 ; _ < T ; _++){

        scanf("%lf%lf%lf",&C,&F,&X);
        printf("Case #%d: ",_+1);
        if(calc(1) >=1){
            printf("%.7f\n",X/2);
            continue;
        }
        double l = 0, r = 1e20;
        while((r-l) > 1e-6){
            double mid = (l+r)/2.0;
            if(calc(mid) > 0){
                r = mid;
            }else{
                l = mid;
            }
        }
        double k = floor(l+1e-6);
        double ans = 0;
        for(int i = 0 ; i <k ;i++){
            ans += C/(2+i*F);
        }
        ans += X/(2+k*F);
        printf("%.7f\n", ans);
    }
    return 0;
}
