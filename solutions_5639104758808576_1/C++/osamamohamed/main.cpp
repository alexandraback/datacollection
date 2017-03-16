#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

char s[1040];

int main()
{
    freopen("A-large.in" , "r" , stdin);
    freopen("out.in" , "w" , stdout);
    int T , c = 0;
    scanf("%d" , &T);
    while(T--)
    {
        ++c;
        int n;
        scanf("%d" , &n);
        scanf("%s" , s);

        long long cnt = 0;
        long long ans = 0;
        for(int i = 0;i < n + 1;++i)
        {
            if(cnt >= i)
                cnt += s[i] - '0';

            else
            {
                ans += i - cnt;
                cnt = i + s[i] - '0';
            }
        }
        printf("Case #%d: %d\n" , c , ans);
    }
    return 0;
}
