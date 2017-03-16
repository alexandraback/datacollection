#include    <bits/stdc++.h>

#define     M_PI            3.14159265358979323846
#define     mod             1000000007
#define     inf             1000000000000000000
#define     mp              make_pair
#define     pb              push_back
#define     F               first
#define     S               second
#define     ll              long long
#define     pii             pair<int,int>
#define     pli             pair<ll,int>
#define     pil             pair<int,ll>
#define     pll             pair<ll,ll>
#define     si(t)           scanf("%d",&t)
#define     sii(m,n)        scanf("%d %d",&m,&n);
#define     sl(t)           scanf("%lld",&t)
#define     rep(i,n)        for(int i=0;i<n;i++)
#define     REP(i,a,b)      for(int i=a;i<=b;i++)
#define     RREP(i,a,b)     for(int i=a;i>=b;i--)
#define     N               100005

using namespace std;

int a[12][12],b[12][12],c[12][12],kk;
pair<pii,int> ans[N];

int chk(int aa,int bb,int cc){
    if(a[aa][bb] >= kk || b[bb][cc] >= kk || c[aa][cc] >= kk) return 0;
    a[aa][bb]++;
    b[bb][cc]++;
    c[aa][cc]++;
    return 1; 
}

int main(){
    int t; si(t);
    REP(T,1,t){
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(c,0,sizeof c);
        int j,p,s; sii(j,p); si(s);
        si(kk);
        int an=0;
        REP(i,1,j){
            REP(jj,1,p){
                REP(k,1,s){
                    int pp = chk(i,jj,k);
                    if(pp){
                        ans[an++] = mp(mp(i,jj),k);
                    } 
                }
            }
        }
        printf("Case #%d: %d\n",T,an );
        rep(i,an) printf("%d %d %d\n",ans[i].F.F , ans[i].F.S , ans[i].S );
    }
    return 0;   
}

