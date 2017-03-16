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

int t, n;
int a[10000], b[10000];
bool flaga[10000], flagb[10000];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", & t);
    for (int ii = 1; ii <= t; ++ ii)
    {
        scanf("%d", & n);
        for (int i =0;i<n;++i)
            scanf("%d%d", a + i, b+i);
        int ans = 0, now = 0;
        memset(flaga, 0, sizeof(flaga));
        memset(flagb, 0, sizeof(flagb));
        while (now != n * 2)
        {
            bool ff = 0;
            for (int i =0;i<n;++i)
                if (! flagb[i])
                    if (b[i] <= now)
                    {
                        ++ ans;
                        now += 2 - flaga[i];
                        flaga[i] = 1;
                        flagb[i] = 1;
                        ff = 1;
                    }
            if (! ff && now != n * 2)
            {
                int target = -1, best = -1;
                for(int i=0;i<n;++i)
                    if (! flaga[i])
                        if (a[i] <= now)
                            if (best <= b[i])
                            {
                                target = i;
                                best = b[i];
                            }
                if (target == -1)
                {
                    printf("Case #%d: Too Bad\n", ii);
                    break;
                }
                flaga[target] = 1;
                now ++;
                ans ++;
            }
        }
        if (now == 2 * n)
            printf("Case #%d: %d\n", ii, ans);
    }

//    fclose(stdout);
}


