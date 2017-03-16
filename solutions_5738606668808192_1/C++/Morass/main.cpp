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
struct big{
    static const long long MM=999999999;
    long long l,a[10];
    big(int A=0):l(1){a[0]=A;}
    bool eq(int h){return l==1&&a[0]==h;}
    void operator=(int h){
        a[0]=h;
        l=1;
    }/*Care - if used on itself, remove '&'!*/
    void operator+=(big &b){
        for(int i(0);i<b.l;++i)
            add(b.a[i],i);
    }
    void add(long long s,int nd){
        if(nd==l)
            a[l++]=0;
        a[nd]+=s;
        if(a[nd]>MM)
            a[nd]-=MM+1,add(1,nd+1);
    }
    void prt(void){
        printf("%lld",a[l-1]);
        for(int i(l-2);~i;--i)
            printf("%09lld",a[i]);
    }
    void operator*=(unsigned k){
        for(int i(0);i<l;++i)
            a[i]*=k;
        for(int i(l-1);~i;--i)
            if(a[i]>MM)
                add(a[i]/(MM+1),i+1),a[i]%=MM+1;
    }
    ll rem(int u,ll r,ll d){
        return ~u?rem(u-1,(a[u]+(MM+1)*r)%d,d):r;
    }
    ll operator%(ll d){
        return rem(l-1,0,d);
    }
    bool operator<(const big&r)const{
        if(r.l!=l)return l<r.l;
        F(l)if(a[l-i-1]!=r.a[l-i-1])return a[l-i-1]<r.a[l-i-1];
        return 0;
    }
    bool operator>(const big&r)const{
        if(r.l!=l)return l>r.l;
        F(l)if(a[l-i-1]!=r.a[l-i-1])return a[l-i-1]>r.a[l-i-1];
        return 0;
    }
    bool operator==(const big&r)const{
        if(r.l!=l)return 0;
        F(l)if(a[l-i-1]!=r.a[l-i-1])return 0;
        return 1;
    }
}H,A;
#define MX (1<<14)
#define pc(C) putchar_unlocked(C)
int P[MX],L,cn[MX]={1,1};
void gen(void){
    for(int i(2);i<MX;++i)
        if(!cn[i]){
            P[L++]=i;
            for(int j(i<<1);j<MX;j+=i)
                cn[j]=1;
        }
}
int N,J,C[64],d[64];
bool cps(int b){
    H=1,A=0;
    F(N){
        if(C[N-i-1])A+=H;
        H*=b;
    }
    F(L&&A>P[i])if(!(A%P[i]))return d[b]=P[i],1;
//    F(L)if(!(A%P[i]))return d[b]=P[i],1;
    return 0;
}
bool tst(){
    FT(2,11)if(!cps(k))return 0;
    return 1;
}
void rec(int p){
    if(!J)return;
    if(p==N-1){
        if(tst()){
            F(N)pc(C[i]+48);
            FT(2,11)printf(" %d",d[k]);
            pc(10),--J;
        }
        return;
    }
    C[p]=0,rec(p+1),C[p]=1,rec(p+1);
}
int main(void){
    gen();
    IN(tt)F(tt){
        scanf("%d%d",&N,&J);
        printf("Case #%d:\n",i+1);
        *C=C[N-1]=1;
        rec(1);
    }
    return 0;
}
