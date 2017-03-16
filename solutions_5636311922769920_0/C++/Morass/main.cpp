#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define ZERO (1e-10)
#define INF (1<<29)
#define CL(A,I) (memset(A,I,sizeof(A)))
#define DEB printf("DEB!\n");
#define D(X) cout<<"  "<<#X": "<<X<<endl;
#define EQ(A,B) (A+ZERO>B&&A-ZERO<B)
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define IN(n) int n;scanf("%d",&n);
#define FOR(i, m, n) for (int i(m); i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define F(n) REP(i, n)
#define FF(n) REP(j, n)
#define FT(m, n) FOR(k, m, n)
#define aa first
#define bb second
void ga(int N,int *A){F(N)scanf("%d",A+i);}
int K,C,S;
ll pw(ll n,ll k){
    ll r(1);
    while(k){
        if(k&1)r*=n;
        n*=n,k>>=1;
    }
    return r;
}
unordered_set<ll> T;
ll P,I,Q,J,H,W,R;
    int main(void){
        IN(tt)F(tt){
            T.clear(),I=J=W=0;
            scanf("%d%d%d",&K,&C,&S);
            if(S==K){
                printf("Case #%d:",i+1);
                F(S)printf(" %d",i+1);
                puts("");
                continue;
            }
            if(S*C<K){printf("Case #%d: IMPOSSIBLE\n",i+1);continue;}
            P=pw(K,C-1),Q=pw(K,C),R=Q-P+1;
            while(I<Q){
                H=1;
                F(C&&i<K&&H+(W+i)*pw(K,C-1-i)<=Q)H+=(W+i)*pw(K,C-1-i);
                if(H<=Q)T.insert(H);
                I+=P*C,W+=C;
            }
            while((int)T.size()<S&&R>0)T.insert(R),R-=P;
            while((int)T.size()<S)T.insert(++J);
        printf("Case #%d:",i+1);
        for(auto&h:T)printf(" %lld",h);
        puts("");
    }
    return 0;
}
