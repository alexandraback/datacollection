#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

long long gcd(long long a,long long b){
    if(a==0 || b==0) return a+b;
    while((a%=b) && (b%=a));
    return a+b;
}

map<pair<long long,long long>,int> dp;

int calc(long long P,long long Q){
    if(P==0) return 10000;
    if(P==Q) return 0;
    long long g = gcd(P,Q);
    P/=g;
    Q/=g;
    if(dp[make_pair(P,Q)]) return dp[make_pair(P,Q)];
    dp[make_pair(P,Q)] = min(calc(P+1,Q),calc(P-1,Q))+1;
    return dp[make_pair(P,Q)];
}

int main(){
    int TT,d;
    long long P,Q,g,z;
    scanf("%d",&TT);
    for( int tt=0; tt<TT; tt++ ){
        scanf("%lld/%lld",&P,&Q);
        g = gcd(P,Q);
        P/=g;
        Q/=g;
        z = Q;
        while(z%2==0){
            z/=2;
        }
        printf("Case #%d: ",tt+1);
        if(z!=1){
            puts("impossible");
        }else{
            d = 0;
            while(Q>P){
                Q/=2;
                d++;
            }
            if(d>40){
                puts("impossible");
            }else{
                printf("%d\n",d);
            }
        }
    }
    return 0;
}
