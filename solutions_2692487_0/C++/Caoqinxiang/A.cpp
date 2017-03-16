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
#include <cstring>
#include <cstdio>
#include <cassert>
#include <stdint.h>
#include <cstdarg>
#include <cstdio>
#include <fcntl.h>

using namespace std;

int a, n, x[1000];

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int __;
    scanf("%d", & __);
    for (int _ = 1; _ <= __; ++ _)
    {
        scanf("%d %d", & a, & n);
        for (int i = 0; i < n; ++ i)
            scanf("%d", x + i);
        if (a == 1)
        {
            printf("Case #%d: %d\n", _, n);
            continue;
        }
        sort(x, x + n);
        int ans = n;
        for (int i = n; i >= 0; -- i)
        {
            int now = a, cnt = n - i;
            for (int j = 0; j < i; ++ j)
            {
                while (now <= x[j])
                {
                    ++ cnt;
                    now = now + now - 1;
                }
                now += x[j];
            }
            if (cnt < ans)
                ans = cnt;
        }
        printf("Case #%d: %d\n", _, ans);
    }
}



