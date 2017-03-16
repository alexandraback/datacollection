#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define S_MAX 102

using namespace std;

int s[S_MAX][S_MAX], row[S_MAX], col[S_MAX], ans[S_MAX][S_MAX];

int main()
{
    int cases;
    scanf("%d", &cases);
    for( int tt = 1; tt <= cases; tt++ )
    {
        int n, m;
        bool flag = true;
        scanf("%d %d", &n, &m);
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < m; j++ ) scanf("%d", &s[i][j]);
        
        printf("Case #%d: ", tt);
        for( int i = 0; i < n; i++ )
        {
            int tmp = -1;
            for( int j = 0; j < m; j++ ) tmp = max(tmp, s[i][j]);
            row[i] = tmp;
        }
        
        for( int i = 0; i < m; i++ )
        {
            int tmp = -1;
            for( int j = 0; j < n; j++ ) tmp = max(tmp, s[j][i]);
            col[i] = tmp;
        }
        
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < m; j++ ) ans[i][j] = min(row[i], col[j]);
        
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < m; j++ )
                if( ans[i][j] != s[i][j] )
                {
                    flag = false;
                    break;
                }
        if( flag ) puts("YES");
        else puts("NO");
    }
    return 0;
}
