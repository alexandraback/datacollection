#include <cstdio>
#include <algorithm>
using namespace std;

int a, n, s[100];
int main()
{
    int mt; scanf("%d", &mt);
    for(int t = 1; t <= mt; t++)
    {
        scanf("%d %d", &a, &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &s[i]);
        sort(s, s + n);
        printf("Case #%d: ", t);
        if(a == 1)
            printf("%d\n", n);
        else
        {
            int ans = n;
            int add = 0;
            for(int i = 0; i < n; i++)
            {
                while(a <= s[i])
                {
                    a = 2 * a - 1;
                    add++;
                }
                a += s[i];
                ans = min(ans, add + n - 1 - i);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
