// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char b[5][5];
bool check( char ch ) {
    for ( int i=0; i<4; i++ ) {
        bool w=1;
        for ( int j=0; j<4; j++ ) if ( b[i][j]!=ch && b[i][j]!='T' ) w=0;
        if ( w ) return 1;
    }
    for ( int i=0; i<4; i++ ) {
        bool w=1;
        for ( int j=0; j<4; j++ ) if ( b[j][i]!=ch && b[j][i]!='T' ) w=0;
        if ( w ) return 1;
    }
    bool w=1;
    for ( int i=0; i<4; i++ ) if ( b[i][i]!=ch && b[i][i]!='T' ) w=0;
    if ( w ) return 1;
    w=1;
    for ( int i=0; i<4; i++ ) if ( b[i][3-i]!=ch && b[i][3-i]!='T' ) w=0;
    return w;
}
void solve() {
    for ( int i=0; i<4; i++ ) scanf("%s",b[i]);
    bool full=1;
    for ( int i=0; i<4; i++ ) for ( int j=0; j<4; j++ ) if ( b[i][j]=='.' ) full=0;
    bool wx=check('X');
    bool wo=check('O');
    if ( wx ) puts(" X won");
    else if ( wo ) puts(" O won");
    else if ( full ) puts(" Draw");
    else puts(" Game has not completed");
}
int main()
{
    int cas;
    scanf("%d",&cas);
    for ( int i=1; i<=cas; i++ ) {
        printf("Case #%d:",i);
        solve();
    }
    return 0;
}


