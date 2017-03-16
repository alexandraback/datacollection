#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <utility>
#include <cstring>
#include <queue>

using namespace std;
typedef long long ll;
#define INF 1LL<<60
#define max(a,b) ((a) > (b) ? (a) : (b))
ll N, array[10000];
ll dp[1000][1000];
ll EMAX,R;
ll sub(int E, int index){
    
    if(index == N) return 0;
    if(dp[E][index] != -1) return dp[E][index];
    ll m = -10000;
    
    if(E == 0) return sub(min(EMAX,E+R),index+1);
    for(ll i = 0; i <= E; i++){
        
        m = max((array[index]*i)+sub(min(EMAX,E-i+R),index+1),m);
        //printf("%lld\n",m);
    }
    return dp[E][index] = m;
}

int main()
{
    int casenum = 1;
    int TC;
    ll r,t;
    ll E;
    scanf("%d\n",&TC);
    while(TC--){
        scanf("%lld %lld %lld",&E,&R,&N);
        for(int i = 0; i < N; i++){
            scanf("%lld",&array[i]);   
        }
        EMAX = E;
        memset(dp,-1,sizeof(dp));
        printf("Case #%d: %lld\n",casenum++,sub(E,0));
    }
    return 0;
}
