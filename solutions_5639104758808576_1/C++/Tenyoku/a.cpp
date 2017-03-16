#include <cstdio>
#include <algorithm>
using namespace std;

char str[1010];
int ss[1010];
int n;

int main()
{
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T; ++cas)
    {
        scanf("%d", &n);
        scanf("%s", str);
        int ans = 0;
        for(int i=0; i<=n; ++i)
            ss[i] = str[i]-'0';
        for(int i=1; i<=n; ++i)
        {
            ans = max(ans, i-ss[i-1]);
            ss[i] += ss[i-1];
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
