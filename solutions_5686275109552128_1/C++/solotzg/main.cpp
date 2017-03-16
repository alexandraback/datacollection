#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int MAXN = 1005;
int num[MAXN];
int main()
{
    freopen("C:/Users/Zhigao/Downloads/B-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int _ = 1; _<= t; ++_)
    {
        printf("Case #%d: ", _);
        int n, res = -1;
        scanf("%d", &n);
        for (int i = 0; i< n; ++i)
        {
            scanf("%d", num+i);
            res = max(res, num[i]);
        }
        for (int i = 1, j = res; i<= j; ++i)
        {
            int sm = i;
            for (int k = 0; k< n; ++k)
            {
                if (num[k] > i)
                {
                    if (num[k] % i == 0)
                    {
                        sm += num[k]/i -1;
                    }
                    else
                    {
                        sm += num[k]/i;
                    }
                }
            }
            res = min(res, sm);
        }
        printf("%d\n", res);
    }
    return 0;
}
