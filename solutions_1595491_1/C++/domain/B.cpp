#include <iostream>
#include <cstring>
using namespace std;
int T, n, s, p;
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B.out","w",stdout);
    int count = 0;
    scanf( "%d", &T );
    while ( T-- )
    {
        count++;
        scanf( "%d%d%d", &n, &s, &p );
        int level1 = p*3-2;
        int level2 = p*3-4;
        if (level2 < 0 ) level2 = p;
        int w, ans = 0;
        for ( int i = 0; i < n; ++i )
        {
            scanf( "%d", &w);
            if ( w >= level1) ans++;
            else if ( w >= level2 && s > 0 ) { ans++; s--;}
        }
        printf( "Case #%d: %d\n", count, ans);

    }
}


