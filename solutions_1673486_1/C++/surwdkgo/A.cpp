#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n, m;
double inp[100010], crr[100010];
inline double Min(double a, double b){
    return a<b?a:b;   
}
int main(){
    int cas;   
    scanf("%d",&cas);
    for(int iii=0;iii<cas;iii++){
        scanf("%d%d",&n,&m);
        crr[0]=1;
        for(int i=0;i<n;i++){
            scanf("%lf",&inp[i]);
            crr[i+1] = crr[i]*inp[i];
        }
        double ans = m+2;
        for(int i=0;i<=n;i++){
            ans = Min(ans, n-i + m-i + 1 + (1-crr[i])*(m+1));   
        }
        printf("Case #%d: %.8lf\n", iii+1, ans);
    }
    scanf(" ");
}
