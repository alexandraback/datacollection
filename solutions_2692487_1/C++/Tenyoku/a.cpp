#include <cstdio>
#include <algorithm>
using namespace std;

int n, a;
int list[110];

int main()
{
    int T;
    scanf("%d", &T);
    for(int cnt=1; cnt<=T; ++cnt)
    {
        scanf("%d %d", &a, &n);
        for(int i=0; i<n; ++i) scanf("%d", &list[i]);
        sort(list, list+n);
        int ans = n;
        int now = 0;
        for(int i=0; i<n; ++i)
        {
            while(a<=list[i])
            {
                if(a==1)
                {
                    now = 1000;
                    break;
                }
                ++now;
                a = a*2-1;
            }
            a+=list[i];
            ans = min(ans, now+n-i-1);
        }
        printf("Case #%d: %d\n", cnt, ans);
    }
    return 0;
}
