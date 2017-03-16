#include<stdio.h>

bool X[50][50];

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("slides_large_output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    for(int _t = 1; _t <= t; _t++)
    {
        //init
        for(int i = 0; i < 50; i++) for(int j = 0; j < 50; j++) X[i][j] = false;
        int n; long long k; scanf("%d %lld", &n, &k);

        //check possible
        printf("Case #%d: %s\n", _t, ((long long)1 << (n-2) >= k)? "POSSIBLE": "IMPOSSIBLE");
        if(!((long long)1 << (n-2) >= k))
            continue;

        //table init
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n-1; j++)
                X[i][j] = true;

        //calculation
        //printf("%d %d\n", n, k);
        X[0][n-1] = true; k--;
        for(int x = 1; x < n-1; x++)
        {
            int p = x-1;
            if(k & ((long long)1 << p)) {
                X[x][n-1] = true;
                //printf("(%d)\n", x);
            }
        }

        //table print
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                printf("%d", X[i][j]);
            printf("\n");
        }

    }
}
