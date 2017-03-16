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
	//freopen("D-large.in" , "r" , stdin);
	freopen("D-small-attempt0.in" , "r" , stdin);
	//freopen("D-large.out" , "w" , stdout);
    freopen("D-small-attempt0.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int n , i;
        scanf("%d" , &n);
        double a[1500] , b[1500];
        int ans1 , ans2;
        for (i = 0; i < n; i ++) scanf("%lf" , &a[i]);
        for (i = 0; i < n; i ++) scanf("%lf" , &b[i]);
        sort(a , a + n);
        sort(b , b + n);
        int p = 0;
        int numb = n;
        ans1 = 0;
        for (i = 0; i < n; i ++)
        {
            if (p >= numb) break;
            if (a[i] < b[p]) numb --;
            else {p ++; ans1 ++;}
        }
        p = 0;
        for (i = 0; i < n; i ++)
        {
            while (p < n && b[p] < a[i]) p ++;
            if (p >= n) break;
            p ++;
        }
        ans2 = n - i;
        printf("%d %d\n" , ans1 , ans2);
    }
    return 0;
}