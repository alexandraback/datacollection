#include<iostream>
#include<cstdio>
using namespace std;

int map[105][105];
int mc[105];
int mr[105];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("codejam2.out","w",stdout);
    int T;
    cin>> T;
    for(int t = 1; t <= T; t++)
    {
        for(int i = 0; i < 105; i++)
        {    mc[i] = 0;mr[i] = 0;}

        bool ans = true;
        int m,n;
        cin >> n >> m;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >>  map[i][j];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(map[i][j] > mr[i])
                    mr[i] = map[i][j];
                if(map[i][j] > mc[j])
                    mc[j] = map[i][j];
            }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(map[i][j] < mr[i] && map[i][j] < mc[j])
                {
                    ans = false;
                    break;
                }
            }

        if(ans)
            printf("Case #%d: YES\n",t);
        else
            printf("Case #%d: NO\n",t);
    }
    return 0;
}
