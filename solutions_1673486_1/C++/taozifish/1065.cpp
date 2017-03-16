#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
double p[100005], pr[100005], ans, tsum;
int main(){
    //freopen("A-large.txt", "r", stdin);
    //freopen("A-large.out", "w", stdout);
    int cas=1, m, n, T, i;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &m, &n);
        ans=2*n;
        pr[0]=1;
        for(i=1; i<=m; i++){
            scanf("%lf", &p[i]);
            pr[i]=p[i]*pr[i-1];
        }
        for(i=0; i<=m; i++){
            tsum=pr[m-i]*(n+i*2+1-m)+(1-pr[m-i])*(2*n+i*2+2-m);
            if(tsum<ans)
            ans=tsum;
        }
        if(m<n)
        tsum=n+2;
        else {
            tsum=pr[n]*1+(1-pr[n])*(n+2);
        }
        if(tsum<ans)ans=tsum;
        printf("Case #%d: %.6f\n", cas++, ans);
    }
    return 0;
}
