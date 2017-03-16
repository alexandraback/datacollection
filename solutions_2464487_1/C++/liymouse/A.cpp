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

int main()
{
	freopen("A-large.in" , "r" , stdin);
	freopen("A-large.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        i64d r , t;
        scanf("%lld %lld" , &r , &t);
        i64d low = 1;
        i64d high = t;
        i64d res = 0;
        while (low <= high)
        {
            i64d mid = (low + high) / 2;
            double x = 2 * (double)mid * (double)mid + (double)(2 * r - 1) * (double)mid;
            i64d y = 2 * mid * mid + (2 * r - 1) * mid;
            if (x <= t + 1)
            {
                if (y == t) {res = mid ; break;}
                else if (y < t) {res = max(res , mid); low = mid + 1;}
                else high = mid - 1;
            }
            else high = mid - 1;
        }
        printf("%lld\n" , res);
    }
    return 0;
}