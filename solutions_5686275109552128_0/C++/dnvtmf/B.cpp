#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#define INF 1000000007
#define MP make_pair
const int NUM = 100010;
const double EPS = 1e-10, PI = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
int d, p[1100];
int ans;
int solve(int x)
{
    int res = x;
    for(int i = 0; i < d; i++)
    {
        res += p[i] / x - (p[i] % x == 0);
    }
    return res;
}
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
    int i, j;
    int T, cas = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &d);
        for(i = 0; i < d; i++)
        {
            scanf("%d", p + i);
        }
        sort(p, p + d);
        j = p[d - 1];
        ans = j;
        for(i = 1; i <= j; i++)
        {
            ans = min(ans, solve(i));
        }
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}
