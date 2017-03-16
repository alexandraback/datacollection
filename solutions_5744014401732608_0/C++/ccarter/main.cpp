#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int tt; cin >>tt;
    for (int tc=1;tc<=tt;tc++)
    {
        int b,m;
        cin >>b >>m;
        int c = (b*(b-1))/2;
        printf("Case #%d: ",tc);
        int flag=0;
        for (int i=0;i<(1<<c);i++)
        {
            int adj[6][6];
            memset(adj,0,sizeof(adj));
            int x=0,y=1;
            for (int j=0;j<c;j++)
            {
                adj[x][y] = ((i & (1<<j))?1:0);
                y++;
                if (y==b)
                {
                    x++;
                    y=x+1;
                }
            }
            int ways[6];
            memset(ways,0,sizeof(ways));
            ways[0] = 1;
            for (int k=0;k<b;k++)
            {
                for (int j=k+1;j<b;j++)
                    if (adj[k][j])
                    {
                        ways[j] += ways[k];
                    }
            }

            if (ways[b-1] == m)
            {
                printf("POSSIBLE\n");
                for (int j=0;j<b;j++) {
                    for (int k=0;k<b;k++)
                        printf("%d",adj[j][k]);
                    printf("\n");
                }
                flag = 1;
                break;
            }
        }
        if (!flag)
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
