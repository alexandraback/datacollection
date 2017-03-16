#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1111];
int main(int argv, char** argc)
{
    int T,t,n,sum,ans;
    if (argv > 1)
        freopen(argc[1], "r", stdin);
    if (argv > 2)
        freopen(argc[2], "w", stdout);
    scanf("%d",&T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d%s",&n,s);
        sum = ans = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += s[i]-'0';
            ans = max(ans, i-sum+1);
        }
        printf("Case #%d: %d\n", t, ans);
    }
}