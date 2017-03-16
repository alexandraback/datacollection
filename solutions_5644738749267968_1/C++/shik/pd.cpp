// by shik {{{
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(c) begin(c),end(c)
#define REP(i,n) for ( int i=0; i<(int)(n); i++ )
#define REP1(i,a,b) for ( int i=(int)(a); i<=(int)(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
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

#define N 1010
int n;
double a[N],b[N];
void input() {
    RI(n);
    REP(i,n) scanf("%lf",a+i);
    REP(i,n) scanf("%lf",b+i);
}

int solve_1() {
    for ( int i=n; i>=1; i-- ) {
        bool good=1;
        REP(j,i) if ( b[j]>a[n-i+j] ) good=0;
        if ( good ) return i;
    }
    return 0;
}

int solve_2() {
    int ans=0;
    for ( int i=0,j=0; i<n; i++ ) {
        while ( j<n && b[j]<a[i] ) j++;
        if ( j==n ) ans++;
        else j++;
    }
    return ans;
}

void solve() {
    sort(a,a+n);
    sort(b,b+n);
    printf("%d %d\n",solve_1(),solve_2());
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

