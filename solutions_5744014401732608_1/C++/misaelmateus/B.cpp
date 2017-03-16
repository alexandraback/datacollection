#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    for(int k = 1; k <= T; k++)
    {
        printf("Case #%d: ", k);
        int B;
        ll M;
        cin >> B >> M;
        if(M > (ll)(1 << B-2) )
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        printf("POSSIBLE\n");
        int m[B+1][B+1];
        memset(m, 0, sizeof(m));
        ll f[B+1];
        memset(f, 0, sizeof(f));
        f[1] = 1LL;
        for(int l = 2; l <= B; l++)
        {
            m[B - l][B - l + 1] = 1;
            f[l] = f[l-1];
            for(int i = l-2; i >= 1; i--)
            {
                if(M - f[l] >= f[i])
                {
                    f[l] += f[i];
                    m[B-l][B - i] = 1;
                }
            }
        }

        for(int i = 0; i < B; i++)
        {
            for(int j = 0; j < B; j++)
            {
                printf("%d", m[i][j]);
            }
            printf("\n");
        }
    }
}
