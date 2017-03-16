#include <cstdio>

int q[8][8] = 
{
    {0, 1, 2, 3},
    {1, 4, 3, 6},
    {2, 7, 4, 1},
    {3, 2, 5, 4},
};

int main()
{
    for(int i=0; i<4; i++)
    for(int j=0; j<4; j++)
    {
        q[i+4][j] = q[i][j]^4;
        q[i][j+4] = q[i][j]^4;
        q[i+4][j+4] = q[i][j];
    }
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        int L;
        long long X;
        scanf("%d %lld", &L, &X);
        char buf[10005];
        scanf("%s", buf);
        while (X > 1000000016) X-= 1000000000;
        while (X > 100016) X-= 100000;
        while (X > 16) X-= 4;
        int status = 0;
        int cur = 0;
        for(int x=0; x<X; x++)
        {
            for(int i=0; buf[i]; i++)
            {
                cur = q[cur][buf[i]-'h'];
                if ((status == 0 && cur == 1) || (status == 1 && cur == 2))
                {
                    status++;
                    cur=0;
                }
            }
        }
        bool ans = (status == 2 && cur == 3);
        printf("Case #%d: %s\n", t, ans ? "YES" : "NO");
    }
}
