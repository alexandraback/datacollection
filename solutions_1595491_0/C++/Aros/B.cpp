#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 100+5;
int T, N, S, p, t;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d%d", &N, &S, &p);
        int ans = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &t);
            int x = t/3;
            if (t%3 == 0)
            {
                if (x >= p)
                    ans++;
                else if (x && x+1 >= p && S)
                {
                    ans++;
                    S--;
                }
            }
            else if (t%3 == 1)
            {
                if (x+1 >= p)
                    ans++;
            }
            else
            {
                if (x+1 >= p)
                    ans++;
                else if (x+2 >= p && S)
                {
                    ans++;
                    S--;
                }
            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
