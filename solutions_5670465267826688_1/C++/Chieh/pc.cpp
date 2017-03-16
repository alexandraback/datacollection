#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

char s[1000002], in[10002];
int array[1000002];
int f[5][5];

bool check(int l, int n)
{
    int now = 1;
    for( int i = l; i < n; i++ )
    {
        int sa = (now < 0) ? -1 : 1;
        now = f[abs(now)][array[i]] * sa;
        if( now == 3 )
            return true;
    }
    return false;
}

int main()
{
    int cases;
    scanf("%d", &cases);
    f[1][1] = 1;
    f[1][2] = 2;
    f[1][3] = 3;
    f[1][4] = 4;

    f[2][1] = 2;
    f[2][2] = -1;
    f[2][3] = 4;
    f[2][4] = -3;

    f[3][1] = 3;
    f[3][2] = -4;
    f[3][3] = -1;
    f[3][4] = 2;

    f[4][1] = 4;
    f[4][2] = 3;
    f[4][3] = -2;
    f[4][4] = -1;
    for( int tt = 0; tt < cases; tt++ )
    {
        bool flag = false;
        int n;
        long long int m;
        scanf("%d%lld", &n, &m);
        scanf("%s", in);
        s[0] = '\0';
        if( m < 9ll )
        {
            int now, idx1 = n * m + 1, idx2 = 0;
            for( int i = 0; i < m; i++ ) strcat(s, in);
            for( int i = 0; i < n * m; i++ ) array[i + 1] = s[i] - 'i' + 2;
            now = 1;
            for( int i = 1; i <= n * m; i++ )
            {
                int sa = (now < 0) ? -1 : 1;
                now = f[abs(now)][array[i]] * sa;
                if( now == 2 )
                {
                    idx1 = i;
                    break;
                }
            }
            now = 1;
            for( int i = n * m; i >= 1; i-- )
            {
                int sa = (now < 0) ? -1 : 1;
                now = f[array[i]][abs(now)] * sa;
                if( now == 4 )
                {
                    idx2 = i;
                    break;
                }
            }
            now = 1;
            for( int i = 1; i <= n * m; i++ )
            {
                int sa = (now < 0) ? -1 : 1;
                now = f[abs(now)][array[i]] * sa;
            }
            flag = (now == -1 && idx1 < idx2);
        }
        else
        {
            bool f1 = false, f2 = false;
            int now;
            for( int i = 0; i < 4; i++ ) strcat(s, in);
            for( int i = 0; i < n * 4; i++ ) array[i + 1] = s[i] - 'i' + 2;
            now = 1;
            for( int i = 1; i <= n * 4; i++ )
            {
                int sa = (now < 0) ? -1 : 1;
                now = f[abs(now)][array[i]] * sa;
                if( now == 2 )
                {
                    f1 = true;
                    break;
                }
            }
            now = 1;
            for( int i = 4 * n; i >= 1; i-- )
            {
                int sa = (now < 0) ? -1 : 1;
                now = f[array[i]][abs(now)] * sa;
                if( now == 4 )
                {
                    f2 = true;
                    break;
                }
            }
            int re = m % 4ll;
            now = 1;
            for( int i = 1; i <= n * re; i++ )
            {
                int sa = (now < 0) ? -1 : 1;
                now = f[abs(now)][array[i]] * sa;
            }
            flag = (f1 && f2 && (now == -1));
        }
        if( flag ) printf("Case #%d: YES\n", tt + 1);
        else printf("Case #%d: NO\n", tt + 1);
    }
    return 0;
}
