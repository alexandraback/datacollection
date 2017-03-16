#include <cstdio>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <climits>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#define INF 0x3f3f3f3f
#define eps 1e-8
using namespace std;

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}


int main()
{
    freopen("A.txt", "r", stdin);
    freopen("A-output.txt", "w", stdout);
    int cas;
    scanf("%d", &cas);
    for (int T = 1; T <= cas; T ++)
    {
        long long a, b;
        scanf("%I64d/%I64d", &a, &b);
        long long tmp = gcd(a, b);
        a /= tmp;
        b /= tmp;
        tmp = 1LL << 40;
        if (tmp % b)
        {
            printf("Case #%d: impossible\n", T);
            continue;
        }
        tmp = tmp / b * a;
        int ans;
        for (ans = 1; tmp < (1LL << (40 - ans)); ans ++)
        {
            ;
        }
        printf("Case #%d: %d\n", T, ans);
    }
    return 0;
}
