#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Node
{
    int num, zip;
    bool operator<(const Node &nn)const
    {
        return ( zip < nn.zip );
    }
}s[52];

bool adj[52][52];
int now[52];

bool check(int n)
{
    int cnt = 1;
    now[0] = s[0].num;
    for( int i = 1; i < n; i++ )
    {
        int ff = -1;
        while(1)
        {
            for( int j = 1; j <= n; j++ )
                if( adj[now[cnt - 1]][s[i].num] )
                {
                    ff = j;
                    break;
                }
            if( ff != -1 )
            {
                now[cnt++] = s[i].num;
                break;
            }
            cnt--;
            if( cnt == 0 ) return false;
        }
    }
    return true;
}

int main()
{
    int cases;
    scanf("%d", &cases);
    for( int tt = 1; tt <= cases; tt++ )
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for( int i = 0; i < n; i++ )
        {
            scanf("%d", &s[i].zip);
            s[i].num = i + 1;
        }
        for( int i = 1; i <= n; i++ )
            for( int j = 1; j <= n; j++ ) adj[i][j] = false;
        for( int i = 0; i < m; i++ )
        {
            int x, y;
            scanf("%d %d", &x, &y);
            adj[x][y] = adj[y][x] = true;
        }
        sort(s, s + n);
        do
        {
            if( check(n) ) break;
        }while( next_permutation(s, s + n) );
        printf("Case #%d: ", tt);
        for( int i = 0; i < n; i++ ) printf("%d", s[i].zip);
        putchar('\n');
    }
    return 0;
}
