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
	//freopen("B-small-attempt0.in" , "r" , stdin);
	//freopen("A-large.out" , "w" , stdout);
    freopen("B-large.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        double C , F , X;
        double ans = 0.0;
        double money = 0.0;
        double p = 2.0;
        double target;
        scanf("%lf %lf %lf" , &C , &F , &X);
        if (C >= X)
        {
            ans = X / p;
        }
        else
        {
            ans = C / p;
            money = C;
            while (1)
            {
                double t1 = (X - money) / p;
                double t2 = X / (p + F);
                if (t1 <= t2)
                {
                    ans += t1; break;
                }
                else
                {
                    p += F;
                    money = C;
                    ans += C / p;
                }
            }
        }
        printf("%lf\n" , ans);
    }
    return 0;
}