#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

char s[10002], in[10002];
int array[10002], prefix[10002];
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
        int n, m, now = 1;
        scanf("%d%d", &n, &m);
        scanf("%s", in);
        s[0] = '\0';
        for( int i = 0; i < m; i++ ) strcat(s, in);
        prefix[0] = 1;
        for( int i = 0; i < n * m; i++ )
        {
            int sa = (prefix[i] < 0) ? -1 : 1;
            array[i + 1] = s[i] - 'i' + 2;
            prefix[i + 1] = f[abs(prefix[i])][array[i + 1]] * sa;
        }
        for( int i = 1; prefix[n * m] == -1 && i <= n * m - 2; i++ )
        {
            if( prefix[i] == 2 && check(i + 1, n * m) )
            {
                flag = true;
                break;
            }
        }
        if( flag ) printf("Case #%d: YES\n", tt + 1);
        else printf("Case #%d: NO\n", tt + 1);
    }
    return 0;
}
