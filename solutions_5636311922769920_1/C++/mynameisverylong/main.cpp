#include <stdio.h>
#include <stdlib.h>

long long ans[110];

int main() {
    long t,tt;
    long long k,c,s,i,j;
    //freopen("D-large.in.txt", "r", stdin);
    //freopen("D-large.out.txt", "w", stdout);
    scanf("%ld",&t);
    for (tt=1;tt<=t;tt++){
        scanf("%lld%lld%lld",&k,&c,&s);
        printf("Case #%ld: ",tt);
        if (s<((k-1)/c+1)){
            printf("IMPOSSIBLE\n");
        }
        else {
            int p=0;
            for (i=0;i<k;i+=c){
                ans[p]=0;
                for (j=0;j<c&&i+j<k;j++){
                    ans[p]*=k;
                    ans[p]+=i+j;
                }
                ans[p]++;
                p++;
            }
            printf("%lld",ans[0]);
            for (i=1;i<p;i++){
                printf(" %lld",ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
