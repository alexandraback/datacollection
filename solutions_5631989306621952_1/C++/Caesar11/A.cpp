#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define N 10000
using namespace std;

void solve(char *str, char *ans, int left, int right, int start)
{
    if (left >= right)
       return;
    int min_pos = left;
    for (int i = left; i < right; ++i)
        if (str[min_pos] <= str[i])
            min_pos = i;

    ans[start] = str[min_pos];
    solve(str, ans, left, min_pos, start + 1);
    //solve(str, ans, min_pos + 1, right, start + min_pos - left + 1);
    int left_start = start + min_pos - left + 1;
    for (int i = min_pos + 1; i < right; ++i)
        ans[left_start++] = str[i];
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("dataA.out","w",stdout);

    int t, ys = 0;
    char str[N], ans[N];

    scanf("%d",&t);
    while (t--)
    {
        scanf("%s",str);
        int n = strlen(str);
        solve(str, ans, 0, n, 0);
        ans[n] = 0;
        printf("Case #%d: %s\n", ++ys, ans);
    }

    return 0;
}
