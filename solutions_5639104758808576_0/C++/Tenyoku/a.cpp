#include <cstdio>
#include <algorithm>
using namespace std;

char str[1010];
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
        for(int i=1; i<=n; ++i)
        {
            ans = max(ans, i-(str[i-1]-'0'));
            str[i] += str[i-1]-'0';
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
