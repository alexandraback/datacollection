// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 110
int h[N][N],bx[N],by[N];
void solve() {
    int n,m;
    scanf("%d%d",&n,&m);
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) scanf("%d",h[i]+j);
    memset(bx,0,sizeof(bx));
    memset(by,0,sizeof(by));
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) {
        bx[i]=max(bx[i],h[i][j]);
        by[j]=max(by[j],h[i][j]);
    }
    bool ok=1;
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) if ( h[i][j]!=bx[i] && h[i][j]!=by[j] ) ok=0;
    puts(ok?"YES":"NO");
}
int main()
{
    int cas;
    scanf("%d",&cas);
    for ( int i=1; i<=cas; i++ ) {
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}


