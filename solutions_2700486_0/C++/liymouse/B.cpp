#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

typedef long long i64d;

using namespace std;

int C[20][20] = {0};
void calc()
{
    C[0][0] = 1;
    for (int i = 1; i < 20; i ++)
    {
        C[i][0] = 1;
        for (int j = 1; j < i; j ++) C[i][j] = C[i-1][j-1] + C[i-1][j];
        C[i][i] = 1;
    }
}
int main()
{
	freopen("B-small-attempt2.in" , "r" , stdin);
	freopen("B-small-attempt2.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int n , x , y;
        scanf("%d %d %d" , &n , &x , &y);
        if (x == 0 && y == 0)
        {
            double res = 1.0;
            printf("%lf\n" , res);
            continue;
        }
        if (x < 0) x = -x;
        if (x + y > 10)
        {
            double res = 0.0;
            printf("%lf\n" , res);
            continue;
        }
        int t = (x + y) / 2;
        int k = t * 2 + 1;
        int tot = 0;
        for (int i = 1; i < k; i += 2)
        {
            tot = tot + i * 2 - 1;
        }
        int tot2 = tot + 2 * k - 1;
        double res = 0.0;
        if (n <= tot)
        {
            res = 0.0;
        }
        else if (n >= tot2)
        {
            res = 1.0;
        }
        else
        {
            int r = n - tot;
            if (x == 0 && y == k-1)
            {
                if (r < 2*k-1) res = 0.0;
                else res = 1.0;
            }
            else
            {
                calc();
                int tot = 0;
                int ok = 0;
                for (int left = 0; left <= r; left ++)
                {
                    int right = r - left;
                    if (right > k-1 || left > k-1) continue;
                    int p = C[r][right];
                    tot += p;
                    if (right > y) ok += p;
                }
                res = (double)ok / (double)tot;
            }
        }
        printf("%lf\n" , res);
    }
    return 0;
}