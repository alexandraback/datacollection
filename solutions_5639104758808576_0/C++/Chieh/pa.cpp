#include <cstdio>
#include <cstdlib>

using namespace std;

char s[2002];

int main()
{
    int cases;
    scanf("%d", &cases);
    for( int tt = 0; tt < cases; tt++ )
    {
        int n, ans = 0, now = 0;
        scanf("%d %s", &n, s);
        for( int i = 0; i <= n; i++ )
        {
            if( now < i )
            {
                ans += (i - now);
                now = i;
            }
            now += (s[i] - '0');
        }
        printf("Case #%d: %d\n", tt + 1, ans);
    }
    return 0;
}
