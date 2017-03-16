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
#include <climits>
#define INF 1000000007
#define MP make_pair
const int NUM = 100010;
const double EPS = 1e-10, PI = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
int n;
int d[1100], h[1100], m[1100];
int ans;
int main()
{
#ifdef ACM_TEST
 //   freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    int i, j;
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d%d%d", &d[i], &h[i], &m[i]);
        ans = 0;
        if(n == 1 && h[0] == 2)
        {
            double t1 = 1.0 * (360.0 - d[0]) * (m[0] + 1) / 360.0;
            double t2 = 1.0 * (360.0 - d[0]) * m[0] / 360.0;
            if(t1 - t2 - m[0] > -EPS)
                ans = 1;
            else
                ans = 0;
        }
        else if(n == 2)
        {
            if(m[0] == m[1])
                ans = 0;
            else
            {
                if(m[0] > m[1])
                {
                    swap(m[0], m[1]);
                    swap(d[0], d[1]);
                }
                double t1 = 1.0 * (360.0 - d[0]) * m[0] / 360.0;
                double t2 = 1.0 * (360.0 - d[1]) * m[1] / 360.0;
                if(t2 - t1 - m[0] > -EPS)
                    ans = 1;
                else
                    ans = 0;
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
