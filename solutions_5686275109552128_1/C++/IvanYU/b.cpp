#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int T, n, a[2000], MAX, ans;
    scanf("%d", &T);

    for (int _T = 1; _T <= T; ++_T)
    {
        scanf("%d", &n);

        MAX = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
            MAX = max(MAX, a[i]);
        }

        //bs
        ans = MAX;
        for (int i = 1; i <= MAX; ++i)
        {
            if(i >= MAX)
                continue;

            int now = 0;
            for (int j = 0; j < n; ++j)  
                if(a[j] > i)
                    now += a[j]/i - (a[j] % i == 0 ? 1:0);

            ans = min(now + i, ans);
            
        }

        printf("Case #%d: %d\n", _T, ans);
    }


}