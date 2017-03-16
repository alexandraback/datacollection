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
	freopen("B-small-attempt0.in" , "r" , stdin);
	freopen("B-small-attempt0.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int k , L , s;
        scanf("%d %d %d" , &k , &L , &s);
        int a[26] = {0};
        double p[26] = {0};
        char key[150];
        char target[150];
        scanf("%s" , key);
        scanf("%s" , target);
        for (int i = 0; i < k; i ++)
        {
            a[key[i]-'A'] ++;
        }
        for (int i = 0; i < 26; i ++)
        {
            p[i] = 1.0 * a[i] / k;
        }
        int can = 1;
        for (int i = 0; i < L; i ++)
            if (a[target[i]-'A'] == 0) {can = 0; break;}
        double res = 0.0;
        if (can != 0)
        {
            int re = L;
            //get max
            for (int i = 1; i < L; i ++)
            {
                int x = 0 , y = i;
                while (y < L)
                {
                    if (target[x] != target[y]) break;
                    x ++; y ++;
                }
                if (y == L) {re = i; break;}
            }
            res = 1 + (s - L)/re;
            double pa = 1.0;
            for (int i = 0; i < L; i ++)
                pa *= p[target[i]-'A'];
            res -= (s-L+1) * pa;
        }
        printf("%lf\n" , res);
    }
    return 0;
}