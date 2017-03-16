#include<cstdio>
int t, ct;
double c, f, x, ans, cur, tmp, rate;
int main(){
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    scanf("%d", &t);
    for(ct=1; ct<=t; ct++){
        scanf("%lf %lf %lf", &c, &f, &x);
        ans=0.0;
        rate=2.0;
        while(1){
            cur = x/rate;
            tmp = c/rate + x/(rate+f);
            if(cur>tmp){
                ans+=c/rate;
                rate+=f;
            }
            else{
                ans+=cur;
                break;
            }
        }
        printf("Case #%d: %.7lf\n", ct, ans);
    }
    return 0;
}
