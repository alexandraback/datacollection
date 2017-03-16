#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;


int main()
{
    freopen("A-small-attempt1.in-2.txt","r",stdin);
    freopen("oxwer.txt","w",stdout);

    int t;
    scanf("%d", &t);

    for(int i = 1;i <= t;i++) {
        int n, d;
        scanf("%d/%d", &n, &d);
        int ans = -1;
        if(d && ((d & (d-1)) == 0)) {
            int level = (int)log2(d);
            ans = -1;

            if(n == 1) {
                ans = level;
            } else {
                ans = -1;
                long long x = 1, p = 1;
                if(n & 1) {
                    while(n > x) {
                        x = x + (long long)pow(2,p++);
                    }
                    p--;
                    ans = level - p;
                }
            }
        }

        if(ans == -1) {
            printf("Case #%d: impossible\n",i);
        } else {
            printf("Case #%d: %d\n", i, ans);
        }
    }
    return 0;
}
