#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct str{
    int one,two;
    int now;
};

str st[1010];

bool operator <(str a, str b)
{
    if (a.two != b.two)
        return a.two < b.two;
    return a.one > b.one;
}

int t,n;
int ans,num;

int ok()
{
    int i,j,k;
    while (num < n * 2)
    {
        for (i = 0;i < n;i++)
        {
            if (st[i].now == 1 && num >= st[i].two)
            {
                st[i].now = 2;
                num++;
                ans++;
                break;
            }
        }
        if (i < n)
            continue;
        for (i = 0;i < n;i++)
        {
            if (st[i].now == 0 && num >= st[i].two)
            {
                st[i].now = 2;
                num += 2;
                ans++;
                break;
            }
        }
        if (i < n)
            continue;
        for (i = n - 1;i >= 0;i--)
        {
            if (st[i].now == 0 && num >= st[i].one)
            {
                st[i].now = 1;
                num++;
                ans++;
                break;
            }
        }
        if (i == -1)
            return -1;
    }
    return ans;
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k;
    scanf("%d", &t);
    for (k = 1;k <= t;k++)
    {
        scanf("%d", &n);
        for (i = 0;i < n;i++)
        {
            scanf("%d%d", &st[i].one, &st[i].two);
            st[i].now = 0;
        }
        sort(st,st + n);
        ans = num = 0;
        ans = ok();
        printf("Case #%d: ", k);
        if (ans == -1)
            printf("Too Bad\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
