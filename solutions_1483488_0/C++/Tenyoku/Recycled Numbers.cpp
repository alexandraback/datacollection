#include <cstdio>
#include <algorithm>
using namespace std;

int a, b;

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("Recycled Numbers.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; ++i)
    {
        scanf("%d %d", &a, &b);
        int ans = 0;
        for(int num = a; num<=b; ++num)
        {
            int now = num, p = 1;
            for(; now>=10; p*=10) now/=10;
            now = num;
            do
            {
                now = now%10*p + now/10;
                if(now>=p&&now!=num&&now>=a&&now<=b) ++ans;
            }while(now!=num);
        }
        printf("Case #%d: %d\n", i, ans/2);
    }
    return 0;
}
