/**
 * Copyright (c) 2013 Authors. All rights reserved.
 * 
 * FileName: A.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2013-04-27
 */
#include <cstdio>
#include <cmath>

using namespace std;

typedef unsigned long long uLL;

int main()
{
        //freopen("A-small-attempt0.in", "r", stdin);
        //freopen("A-small-attempt0.out", "w", stdout);

        int T, cas = 0;
        scanf("%d", &T);

        while (T--) {
                uLL r, t;
                scanf("%llu%llu", &r, &t);

                double x = r * 2 - 1;
                uLL ans = uLL((sqrt(x * x + t * 8) - x) / 4);

                uLL p = r * 2 - 1;
                while (ans * (p + ans * 2) > t)
                        --ans;

                printf("Case #%d: %llu\n", ++cas, ans);
        }

        return 0;
}
