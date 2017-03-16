#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <numeric>
#include <functional>
#include <utility>
#include <bitset>
#include <iostream>
#include <cmath>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <stdint.h>
#include <cstdarg>
#include <cstdio>
#include <fcntl.h>

using namespace std;

int n, x, y;

long long tot(long long k)
{
    k = k * 2 + 1;
    return k * (k + 1) / 2;
}

double psb(int all, int s)
{
}

#define N 3600

double dp[N][N];

int main()
{
    dp[0][0] = 1;
    for (int i = 1; i < N - 1; ++ i)
    {
        dp[i][0] = dp[i][i] = dp[i - 1][0] / 2;
        for (int j = 1; j < i; ++ j)
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) / 2;
    }
    for (int i = 1; i < N - 1; ++ i)
    {
        for (int j = i; j; -- j)
            dp[i][j - 1] += dp[i][j];
    }
    
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int __;
    scanf("%d", & __);
    for (int _ = 1; _ <= __; ++ _)
    {
        scanf("%d %d %d", & n, & x, & y);
        int k = (abs(x) + abs(y)) / 2;
        if (tot(k - 1) >= n)
        {
            printf("Case #%d: 0.0\n", _);
            continue;
        }
        if (tot(k) <= n)
        {
            printf("Case #%d: 1.0\n", _);
            continue;
        }
        if (x == 0)
        {
            printf("Case #%d: 0.0\n", _);
            continue;
        }
        
        int res = n - tot(k - 1);
        
        if (k + k + abs(y) < res)
        {
            printf("Case #%d: 1.0\n", _);
            continue;
        }
        if (abs(y) >= res)
        {
            printf("Case #%d: 0\n", _);
            continue;
        }
            
        printf("Case #%d: %.6f\n", _, dp[res][abs(y) + 1]);
    }
}



