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
	freopen("B-large.in" , "r" , stdin);
    //freopen("input.txt" , "r" , stdin);
	freopen("B-large.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int n , x , a[1500] = {0};
        int maxL = 0;
        scanf("%d" , &n);
        for (int i = 0; i < n; i ++)
        {
            scanf("%d" , &a[i]);
            if (a[i] > maxL) maxL = a[i];
        }
        int res = maxL;
        for (int t = maxL; t >= 1; t --)
        {
            int sum = 0;
            for (int i = 0; i < n; i ++)
            {
                if (a[i] > t) sum += a[i]/t + (a[i]%t != 0) - 1;
            }
            res = min(res , sum + t);
        }
        printf("%d\n" , res);
    }
    return 0;
}