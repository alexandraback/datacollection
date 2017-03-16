#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 100+5;
int T, A, B;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d", &A, &B);
        int ans = 0;
        for (int i = A; i < B; i++)
        {
            int x = i, m = 1;
            while (x /= 10)
                m *= 10;
            x = i;
            x = m*(x%10)+x/10;
            while (x != i)
            {
                if (i < x && x <= B)
                {
//                    printf("%d %d\n", i, x);
                    ans++;
                }
                x = m*(x%10)+x/10;
            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
