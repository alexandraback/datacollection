// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define K 12
#define M 8
int r,n,m,k,p[K][M];
void input() {
    for ( int i=0; i<k; i++ ) {
        long long x;
        scanf("%lld",&x);
        for ( int j=2; j<=m; j++ ) {
            int c=0;
            while ( x%j==0 ) {
                c++;
                x/=j;
            }
            p[i][j]=c;
        }
    }
}
int big[M];
double avg[M];
void build() {
    memset(big,0,sizeof(big));
    for ( int i=0; i<k; i++ ) for ( int j=2; j<=m; j++ ) big[j]=max(big[j],p[i][j]);
    for ( int i=0; i<k; i++ ) for ( int j=2; j<=m; j++ ) avg[j]+=p[i][j];
    for ( int i=2; i<=m; i++ ) avg[i]/=k;
}
void predict() {
    for ( int i=0; i<big[3]; i++ ) putchar('3');
    for ( int i=0; i<big[5]; i++ ) putchar('5');
    int t=n-big[3]-big[5];
    int e=2*avg[2];
    int n4=e-t;
    if ( n4>t ) n4=t;
    if ( n4<0 ) n4=0;
    int n2=t-n4;
    for ( int i=0; i<n2; i++ ) putchar('2');
    for ( int i=0; i<n4; i++ ) putchar('4');
    puts("");
}
void solve() {
    scanf("%d%d%d%d",&r,&n,&m,&k);
    while ( r-- ) {
        input();
        build();
        predict();
    }
}
int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while ( t-- ) {
        printf("Case #%d:\n",++cas);
        solve();
    }
    return 0;
}


