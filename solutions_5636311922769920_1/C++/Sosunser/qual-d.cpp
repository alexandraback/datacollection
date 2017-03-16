#include <bits/stdc++.h>
using namespace std;

long long t,k,c,s;

int main(){
    freopen("D-large.in","r",stdin);
    freopen("D-large.out","w",stdout);
    scanf("%lld",&t);
    for(long long j = 1; j <= t; j++){
        scanf("%lld%lld%lld",&k,&c,&s);
        printf("Case #%lld: ", j);
        if(c == 1){
            if(s < k) printf("IMPOSSIBLE\n");
            else{
                for(int i = 1; i <= k; i++) printf("%d ",i);
                printf("\n");
            }
            continue;
        }
        if(s < (k+1)/2){
            printf("IMPOSSIBLE\n");
            continue;
        }
        for(long long i = 1; i <= k; i += 2){
            long long n = k;
            long long pos = i;
            for(long long p = 1; p < c; p++){
                pos = i+(pos-1)*k;
                n = n*k;
            }
            if(i != k) pos++;
            printf("%lld ",pos);
        }
        printf("\n");
    }
}