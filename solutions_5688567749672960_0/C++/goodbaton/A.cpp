#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>

typedef long long ll;
using namespace std;
#define INF (int)2e9
#define LLINF (ll)4e18
#define mod 1000000007
#define SIZE 100000

ll rev(ll n){
    int k=0;
    ll nn=n,ret=0;
    
    
    while(nn>0){
        nn/=10;
        k++;
    }
    
    for(int i=0;i<k;i++){
        ret+=(n%10)*pow(10,k-i-1);
        n/=10;
    }
    
    return ret;
}

int calc(){
    ll ans=0,N,n=1;
    bool kaku[1000001]={0};
    queue<ll> qu;
    
    qu.push(1);
    
    scanf("%lld",&N);
    
    for(ans=1;;ans++){
        queue<ll> qu2;
        
        while(!qu.empty()){
            
            n = qu.front();
            
            if(n==N) return (int)ans;
            
            qu.pop();
            
            ll rn = rev(n);
            
            if(!kaku[n+1]){
                qu2.push(n+1);
                kaku[n+1]=true;
            }
            
            if(!kaku[rn]){
                qu2.push(rn);
                kaku[rn]=true;
            }
            
            
            
        }
        qu=qu2;
    }
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    for(int i=1;i<=T;i++){
        printf("case #%d: %d\n",i,calc());
    }
    
    return 0;
}
