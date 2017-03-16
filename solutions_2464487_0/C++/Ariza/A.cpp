#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define EPS (1e-10)
#define lef(x) (x<<1)
#define rig(x) (x<<1)+1
long long sq(long long x){
     return x*x;
}
long long binsearch(long long l,long long r,long long T,long long R){
     //cout << l << "," << r << endl;
     if (l>r) return l;
     long long mid=(l+r)/2;
     long long ans=0LL;
     long long ads=1LL;
     for (long long i=0;i<mid;++i){
         ans+=(sq(R+(2*i+1))-sq(R+(2*i)));
     }
     if (ans>=T) return binsearch(l,mid-1,T,R);
     else return binsearch(mid+1,r,T,R);
}

void solve(){
     long long R,T;
     scanf("%lld %lld",&R,&T);
     long long ctr=binsearch(1,100000,T,R);
     long long ans=0LL;
     long long ads=1LL;
     for (long long i=0;i<ctr;++i){
         ans+=(sq(R+(2*i+1))-sq(R+(2*i)));
     }
     //cout << ans << endl;
     if (ans>T) printf("%lld",ctr-1);
     else printf("%lld",ctr);
}
int main(){
    int ntest;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        printf("Case #%d: ",test);
        solve();
        printf("\n");
    }
    return 0;
}
