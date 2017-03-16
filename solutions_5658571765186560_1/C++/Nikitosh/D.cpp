#include <bits/stdc++.h> 

using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;

#ifdef WIN32
#define I64 "%I64d"
#else
#define I64 "%lld"
#endif

#define FNAME "1"

int T;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        int X, R, C;
        scanf("%d%d%d", &X, &R, &C);
        printf("Case #%d: ", t + 1);
        if ((R * C) % X != 0 || X >= 7)
        {
            puts("RICHARD");
            continue;
        }
        if (X <= 2)
        {
            puts("GABRIEL");
            continue;
        }
        if (R > C)
            swap(R, C);
        if (R == 1)
        {
            puts("RICHARD");
            continue;
        }
        if (R == 2)
        {
            if (X == 3)
                puts("GABRIEL");
            else
                puts("RICHARD");
            continue;
        }
        if (X <= 4)
        {
            puts("GABRIEL");
            continue;
        }
        if (R == 3)
        {
            if (X == 5)
            {
                if (C == 5)
                    puts("RICHARD");
                else
                    puts("GABRIEL");
            }
            if (X == 6)
            {
                puts("RICHARD");
            }
            continue;
        }
            puts("GABRIEL");
            continue;
    }    
    return 0;
}