#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <stack>
using namespace std;

#define N 1000
int R, n, m, K;
bool used[N];
bool tmp[N];
int d[3];

int main()
{
    int cas;
    freopen("D:\\cdata.in", "r", stdin);
    freopen("D:\\cdata.out", "w", stdout);
    scanf("%d", &cas);

    printf("Case #1:\n");
    scanf("%d %d %d %d", &R, &n, &m, &K);
    while (R--)
    {
        vector<int> ans;
        ans.clear();
        memset(used, false, sizeof (used));
        for (int i = 0; i < K; i++)
        {
            int x;
            scanf("%d", &x);
            for (int i = 8; i >= 2; i--)
                while (x % i == 0)
                {
                    x /= i;
                    if (!used[i])
                    {
                        ans.push_back(i);
                        used[i] = true;
                    }
                }
        }
        int pp = 2;
        while (ans.size() < n)
        {
            ans.push_back(pp);
            pp++;
            if (pp > 8)
                pp = 2;
        }
        for (int i = 0; i < n; i++)
            printf("%d", ans[i]);
        printf("\n");
    }
    return 0;
}