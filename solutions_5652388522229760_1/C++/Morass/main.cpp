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
    long long l,a[1024];
    big(int A=0):l(1){a[0]=A;}
    bool eq(int h){return l==1&&a[0]==h;}
    void operator=(int h){
        a[0]=h,l=1;
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
    void add(long long s,int nd){
        if(nd==l)
            a[l++]=0;
        a[nd]+=s;
        if(a[nd]>MM)
            a[nd]-=MM+1,add(1,nd+1);
    }
    ll rem(int u,ll r,ll d){
        return ~u?rem(u-1,(a[u]+(MM+1)*r)%d,d):r;
    }
    ll operator%(ll d){
        return rem(l-1,0,d);
    }
    void st(int u,char *c,int L){
        a[u]=0;l=u+1;
        F(L)a[u]*=10,a[u]+=c[i]-'0';
    }
    void scan(void){
        static char c[1024];
        scanf("%s",c);
        int L(strlen(c)),I(0);
        while(L>0)
            st(I++,c+L-(L>=9?9:L),(L>=9?9:L)),L-=9;
    }
    void div(int u,ll r,ll d){
        if(!~u)return;
        ll h(a[u]+(MM+1)*r);
        div(u-1,h%d,d);
        a[u]=h/d;
    }
    void operator/=(ll d){
        div(l-1,0,d);
        while(l>1&&!a[l-1])--l;
    }
    void operator+=(big &b){
        for(int i(0);i<b.l;++i)
            add(b.a[i],i);
    }
}A,B,C;
int cn[10],H(0);
bool no(){
    F(10)if(!cn[i])return 1;
    return 0;
}
int main(void){
    IN(tt)F(tt){
        CL(cn,0);
        A.scan(),C=A;
        if(A.eq(0)){printf("Case #%d: INSOMNIA\n",i+1);continue;}
        while(666){
            B=A;
            while(!B.eq(0))++cn[B%10],B/=10;
            if(!no())break;
            A+=C;
        }
        printf("Case #%d: ",i+1),A.prt(),puts("");
    }
    return 0;
}
