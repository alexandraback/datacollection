#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define N 51
#define oo 1000000000000000000LL
using namespace std;

int ans[N][N];
unsigned long long f[N];

void gen()
{
    f[1] = 1; f[2] = 1;
    for (int i = 3; i <= N; ++i)
    {
        f[i] = f[i-1] * 2;
    }
}

int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("dataB.out", "w", stdout);
    gen();
    int t, ys = 0;
    scanf("%d", &t);
    while (t--)
    {
        int b;
        unsigned long long m;
        cin >> b >> m;
        memset(ans, 0, sizeof(ans));
        unsigned long long sum = 1;
        int p = 0;
        for (int i = 1; i <= b; ++i)
            if (f[i] >= m)
            {
                p = i;
                break;
            }

        printf("Case #%d: ", ++ys);
        if (p == 0)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        printf("POSSIBLE\n");
        //cout << "p" << p << " " << f[p] << endl;
        if (f[p] == m)
        {
            for (int i = 1; i <=  p; ++i)
                for (int j = i + 1; j <= p; ++j)
                    ans[i][j] = 1;
            if (p < b) ans[p][b] = 1;
        }
        else
        {
            for (int i = 1; i < p; ++i)
                for (int j = i + 1; j < p; ++j)
                    ans[i][j] = 1;
            for (int i = 0; i < p; ++i)
                if ((1LL << i) & m)
                {
                    //cout << "i" << i <<endl;
                    ans[i + 2][b] = 1;
                }
        }
        for (int i = 1; i <= b; ++i)
        {
            for (int j = 1; j <=b; ++j)
                printf("%d", ans[i][j]);
            printf("\n");
        }
    }

    return 0;
}

