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
int n, a[1100];
char s[1100];

bool solve(int add)
{
    int sum = add + a[0];
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > 0 && sum < i)
            return false;
        else
            sum += a[i];
    }
    return true;
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
        scanf("%d", &n);
        scanf("%s", s);
        for(i = 0; i <= n; i++)
            a[i] = s[i] - '0';
        int l = 0, r = 11 * n + 11, mid;
        while(l + 1 < r)
        {
            mid = (l + r) >> 1;
            if(solve(mid))
                r = mid;
            else
				l = mid + 1;
        }
        int ans = 0;
        for(ans = l; ans <= r; ans++)
            if(solve(ans))
                break;
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}
