#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

struct seg
{
    int x;
    char key;
}s[102][102];

int t[102], tmp[102];

bool check(int n)
{
    for( int i = 1; i < n; i++ )
        if( t[i] != t[i - 1] ) return false;
    for( int i = 1; i < n; i++ )
        for( int j = 0; j < t[i]; j++ )
            if( s[i][j].key != s[i - 1][j].key ) return false;
    return true;
}

int main()
{
    int cases;
    scanf("%d", &cases);
    for( int tt = 1; tt <= cases; tt++ )
    {
        int n, ans = 0;
        char in[102];
        scanf("%d", &n);
        for( int i = 0; i < n; i++ )
        {
            scanf("%s", in);
            int cnt = 1, len = strlen(in);
            t[i] = 0;
            for( int j = 1; j < len; j++ )
            {
                if( in[j] == in[j - 1] ) cnt++;
                else
                {
                    s[i][t[i]].key = in[j - 1];
                    s[i][t[i]++].x = cnt;
                    cnt = 1;
                }
            }
            s[i][t[i]].key = in[len - 1];
            s[i][t[i]++].x = cnt;
        }
        if( !check(n) ) printf("Case #%d: Fegla Won\n", tt);
        else
        {
            for( int i = 0; i < t[0]; i++ )
            {
                for( int j = 0; j < n; j++ ) tmp[j] = s[j][i].x;
                sort(tmp, tmp + n);
                for( int j = 0; j < n; j++ ) ans += (abs(tmp[j] - tmp[n / 2]));
            }
            printf("Case #%d: %d\n", tt, ans);
        }
    }
    return 0;
}
