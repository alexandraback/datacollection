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
using namespace std;

int t, n, m;
double a[1000000];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", & t);
    for (int ii = 1; ii <= t; ++ ii)
    {
        scanf("%d%d", & n, & m);
        for (int i =0;i<n;++i)
            scanf("%lf", a + i);
        double ans = m + 2, p;
        for (int i =0;i<=n;++i)
        {
            if (i == 0)
                p = 1;
            else
                p = p * a[i - 1];
            double res = p * (n - i + m - i + 1) + (1 - p) * (n - i + m - i + 1 + m + 1);
            ans = min(ans, res);
        }
        
        printf("Case #%d: %.6f\n", ii, ans);
    }

//    fclose(stdout);
}


