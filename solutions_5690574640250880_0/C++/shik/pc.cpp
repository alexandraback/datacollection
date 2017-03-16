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

#define N 55

int r,c,m;
void input() {
    RI(r,c,m);
}

char s[N][N];
void solve() {
    memset(s,0,sizeof(s));
    if ( r==1 ) {
        REP1(i,1,c) s[1][i]=(i<=m?'*':'.');
        s[1][c]='c';
    } else if ( c==1 ) {
        REP1(i,1,r) s[i][1]=(i<=m?'*':'.');
        s[r][1]='c';
    } else if ( (r==2 || c==2) && m%2==1 && r*c-m!=1 ) {
        puts("Impossible");
        return;
    } else {
        int dot=r*c-m;
        if ( dot==1 ) {
            REP1(i,1,r) REP1(j,1,c) s[i][j]='*';
            s[1][1]='c';
        } else if ( dot<4 || dot==5 || dot==7 ) {
            puts("Impossible");
            return;
        } else {
            //printf("dot = %d\n",dot);
            REP1(i,1,r) REP1(j,1,c) s[i][j]='*';
            REP1(rr,2,r) REP1(cc,2,c) if ( 2*rr+2*cc-4<=dot && dot<=rr*cc ) {
                REP1(i,1,rr) s[i][1]=s[i][2]='.';
                REP1(i,1,cc) s[1][i]=s[2][i]='.';
                int rem=dot-(2*rr+2*cc-4);
                REP1(i,1,rr) REP1(j,1,cc) if ( s[i][j]=='*' && rem>0 ) {
                    s[i][j]='.';
                    rem--;
                }
                rr=cc=N;
            }
            s[1][1]='c';
        }
    }
    REP1(i,1,r) puts(s[i]+1);
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
        printf("Case #%d:\n",i);
        solve();
        fflush(stdout);
    }
    return 0;
}

