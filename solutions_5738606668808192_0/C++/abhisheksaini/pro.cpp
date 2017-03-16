/*input
5
-
-+
+-
+++
--+-

*/
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
long long mod=1e9+7;
 
typedef long long unsigned llu;
typedef long long int lld;
typedef long ld;
#define rep(i,a,n) for(long long int i = (a); i <= (n); ++i)
#define repI(i,a,n) for(int i = (a); i <= (n); ++i)
#define repD(i,a,n) for(long long int i = (a); i >= (n); --i)
#define repDI(i,a,n) for(int i = (a); i >= (n); --i)
 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sc(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define scd(a) scanf("%d",&a)
#define scd2(a,b) scanf("%d%d",&a,&b)
#define scd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scf(a) scanf("%lf",&a)
#define scf2(a,b) scanf("%lf%lf",&a,&b)
#define scf3(a,b,c) scanf("%lf%lf%lf",&a,&b,&c)
#define prL(a) printf("%lld\n",a)
#define prS(a) printf("%lld ",a)
#define prdL(a) printf("%d\n",a)
#define prdS(a) printf("%d ",a)
#define prfL(a) printf("%lf\n",a)
#define prfS(a) printf("%lf ",a)
#define popcount __builtin_popcountll
#define swap(a,b,t) t=a;a=b;b=t
typedef pair<lld,lld> PA;
 
#define lim 100003
#define lim2 1003
inline lld sqr(lld x) { return x * x; }
// map<pair<PA,PA>,lld> M;
// map<string,lld> M,My;
// map<PA,lld> Ms;
// deque<PA> Q;
// map<lld,lld>::iterator it;
// std::ios::sync_with_stdio(false);
 
// multiset<lld> S;
// set<lld> S;
// vector<lld> V[lim];
 
// bool dp[1002][12][12];
// priority_queue<PA> Q;
// lld A[lim],B[lim],C[lim];
lld A[lim],B[lim];
// lld X[lim],Y[lim];
// PA P[lim];
// lld dp[1<<18];
lld one,zero,ansR,numNodes;

lld findGcd(lld a,lld b){
    if(a==0) return b;
    else return findGcd(b%a,a);
}
lld powP(lld a,lld b){
    if(b==0) return 1%mod;
    lld k;
    k=powP(a,b/2);
    k=k*k%mod;
    if(b%2==0) return k;
    else return a*k%mod;
}

bool find(lld base,lld m,lld n){
    lld sum=0;
    rep(i,0,n-1){
        sum=(sum*base+A[i])%m;
    }
    if(sum==0) return true;
    else return false;
}


bool check(lld c){
    rep(i,2,10){
        if(find(i,3,c)) B[i]=3;
        else if(find(i,5,c)) B[i]=5;
        else if(find(i,7,c)) B[i]=7;
        else if(find(i,11,c)) B[i]=11;
        else return false;
    }
    return true;
}

int main(){
    // std::ios::sync_with_stdio(false);
    lld T,i,j,h,l,r,k,s,b,c,a,d,q,p,n,m,w,x,y,v,z,t,curr,prev,sum,ans,pos,val,countA,secondMin,indicator;
    // sc(T);
    T=1;
    rep(testCase,1,T){
        printf("Case #%lld:\n",testCase);
        n=16;
        p=50;
        A[0]=1;
        A[n-1]=1;
        t=(1<<(n-2))-1;
        countA=0;
        rep(i,0,t){
            x=i;
            rep(j,1,n-2) A[j]=0;
            k=n-2;
            while(x>0){
                A[k]=x%2;
                k--;
                x/=2;
            }
            if(check(n)){
                rep(ro,0,n-1) printf("%lld",A[ro]);
                rep(ro,2,10) printf(" %lld",B[ro]);
                printf("\n");
                countA++;
                if(countA==p) break;
            }
        }
        // printf("Case #%lld: %lld\n",testCase,ans);
    }
    return 0;
}
