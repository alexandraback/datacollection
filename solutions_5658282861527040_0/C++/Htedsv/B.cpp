#include <iostream>
#include <cstring>
using namespace std;
int T, a, b, k;
int main()
{
    scanf( "%d", &T );
    for ( int I = 1; I <= T; ++I )
    {
        scanf("%d%d%d", &a, &b, &k );
        int s = 0;
        for (int i = 0; i < a; ++i )        
            for (int j = 0; j < b; ++j)
                if ((i & j) < k )
                {
                    s++;
                }
        printf( "Case #%d: %d\n", I, s);

    }
}

