#include<stdio.h>
#include<map>
#include<queue>
#include<string>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
typedef long long LL;
#define PB push_back

LL A, B, K, ans;

int main(){
    int ca; scanf("%d", &ca);
    FOR(tt,0,ca){
        scanf("%lld%lld%lld", &A, &B, &K);
        ans = 0;
        FOR(i,0,A){
            FOR(j,0,B){
                if ((i & j) < K) ans += 1;
            }
        }
        printf("Case #%d: %lld\n", tt+1, ans);
    }
    return 0;
}
