#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MaxN 10000010

bool palin( long long n )
{
    string s = "";
    while ( n > 0 ) {
        s += char( int('0') + (n % 10) );
        n /= 10;
    }

    int len = s.length();
    for (int i = 0; i < len/2; ++i) {
        if ( s[i] != s[len-1-i] ) return false;
    }

    return true;
}

long long p[200];
int pp = 0;

int Find( long long n )
{
    int ret = 0;
    for (int i = 0; i < pp; ++i)
        ret += p[i] <= n;
    return ret;
}

int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);

    for (int i = 1; i < MaxN; ++i) {
        if ( palin(i) && palin( (long long)i * (long long)i ) ) {
            p[ pp++ ] = (long long)i * (long long)i;
        }
    }

    int T;
    scanf("%d",&T);
    for (int t = 1; t <= T; ++t) {
        long long a,b;
        scanf("%lld %lld",&a,&b);
        int p1, p2;
        p1 = Find( a-1LL );
        p2 = Find( b );
        printf("Case #%d: %d\n",t,p2-p1);
    }

    return 0;
}
