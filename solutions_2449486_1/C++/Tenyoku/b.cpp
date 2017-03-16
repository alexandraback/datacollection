#include <cstdio>
#include <algorithm>
using namespace std;

int input[100][100];
int now[100][100];
int n, m;

int main()
{
    int T;
    scanf("%d", &T);
    for(int cnt=1; cnt<=T; ++cnt)
    {
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
            {
                scanf("%d", &input[i][j]);
                now[i][j] = 100;
            }
        for(int i=0; i<n; ++i)
        {
            int cut = 0;
            for(int j=0; j<m; ++j) cut = max(cut, input[i][j]);
            for(int j=0; j<m; ++j) now[i][j] = min(now[i][j], cut);
        }
        for(int j=0; j<m; ++j)
        {
            int cut = 0;
            for(int i=0; i<n; ++i) cut = max(cut, input[i][j]);
            for(int i=0; i<n; ++i) now[i][j] = min(now[i][j], cut);
        }
        bool ans = 1;
        for(int i=0; i<n&&ans; ++i)
            for(int j=0; j<m&&ans; ++j)
                if(now[i][j] != input[i][j]) ans = 0;
        printf("Case #%d: %s\n", cnt, ans?"YES":"NO");
    }
    return 0;
}
