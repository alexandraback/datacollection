#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int cases;
    scanf("%d", &cases);
    for( int tt = 1; tt <= cases; tt++ )
    {
        int a, b, c, cnt = 0;
        scanf("%d %d %d", &a, &b, &c);
        for( int i = 0; i < a; i++ )
            for( int j = 0; j < b; j++ )
                if( (i & j) < c ) cnt++;
        printf("Case #%d: %d\n", tt, cnt);
    }
    return 0;
}
