#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int list[1010];

int main()
{
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T; ++cas)
    {
        int ans=1010;
        scanf("%d", &n);
        for(int i=0; i<n; ++i)
            scanf("%d", &list[i]);
        for(int k=1; k<=1000; ++k)
        {
            int tmp = k;
            for(int i=0; i<n; ++i)
                tmp += (list[i]+k-1)/k - 1;
            ans = min(ans, tmp);
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
