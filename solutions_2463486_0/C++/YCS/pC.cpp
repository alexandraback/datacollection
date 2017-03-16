#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define S_MAX 1002

using namespace std;

int dp[S_MAX];
char tmp[12];

bool judge(int n)
{
    double sq = sqrt(n);
    if( floor(sq) * floor(sq) != n ) return false;
    sprintf(tmp, "%d", n);
    int len = strlen(tmp);
    for( int i = 0; i < len / 2; i++ )
    {
        if( tmp[i] != tmp[len - i - 1] ) return false;
    }
    n = (int)sq;
    sprintf(tmp, "%d", n);
    len = strlen(tmp);
    for( int i = 0; i < len / 2; i++ )
    {
        if( tmp[i] != tmp[len - i - 1] ) return false;
    }
    return true;
}

int main()
{
    dp[0] = 0;
    for( int i = 1; i < S_MAX; i++ )
    {
        dp[i] = dp[i - 1];
        if( judge(i) ) dp[i]++;
    }
    int cases;
    scanf("%d", &cases);
    for( int tt = 1; tt <= cases; tt++ )
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d\n", tt, dp[b] - dp[a - 1]);
    }
    return 0;
}
