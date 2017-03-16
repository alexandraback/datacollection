#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define S_MAX 1002

using namespace std;

char tmp[22];

bool judge(long long int n)
{
    double sq = sqrt(n);
    if( (long long int)floor(sq) * (long long int)floor(sq) != n ) return false;
    sprintf(tmp, "%lld", n);
    int len = strlen(tmp);
    for( int i = 0; i < len / 2; i++ )
    {
        if( tmp[i] != tmp[len - i - 1] ) return false;
    }
    n = (long long int)sq;
    sprintf(tmp, "%lld", n);
    len = strlen(tmp);
    for( int i = 0; i < len / 2; i++ )
    {
        if( tmp[i] != tmp[len - i - 1] ) return false;
    }
    return true;
}

int main()
{
    int cases;
    scanf("%d", &cases);
    for( int tt = 1; tt <= cases; tt++ )
    {
        long long int a, b, count = 0;
        scanf("%lld %lld", &a, &b);
        for( long long int i = a; i <= b; i++ )
            if( judge(i) ) count++;
        printf("Case #%d: %lld\n", tt, count);
    }
    return 0;
}
