// by shik {{{
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(c) begin(c),end(c)
#define REP(i,n) for ( int i=0; i<(int)(n); i++ )
#define REP1(i,a,b) for ( int i=(int)(a); i<=(int)(b); i++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}

void WI( int x ) {
    printf("%d\n",x);
}

template<typename... Args>
void WI(int head, Args... tail) {
    printf("%d ",head);
    WI(tail...);
}
/// }}}

double c,f,x;
void input() {
    scanf("%lf%lf%lf",&c,&f,&x);
}

void solve() {
    double ans=1e9,t=0,v=2;
    while ( t<ans ) {
        ans=min(ans,t+x/v);
        t+=c/v;
        v+=f;
    }
    printf("%.9f\n",ans);
}

int main( int argc, char *argv[] ) {
    int n_case;
    RI(n_case);
    //fprintf(stderr,"n_case = %d\n",n_case);
    REP1(i,1,n_case) {
        input();
        if ( argc==2 && atoi(argv[1])!=i ) continue;
        if ( argc==3 && (atoi(argv[1])<i || atoi(argv[2])>i) ) continue;
        if ( argc!=1 ) {
            fprintf(stderr,"Running #%d...\n",i);
            fflush(stderr);
        }
        printf("Case #%d: ",i);
        solve();
        fflush(stdout);
    }
    return 0;
}

