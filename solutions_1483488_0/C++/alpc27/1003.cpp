#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int getlen(int k)
{
    int ret = 0;
    int now = k;
    while (now)
    {
        now /= 10;
        ret++;
    }
    return ret;
}

const int first[7] = {1,10,100,1000,10000,100000,1000000};

struct str{
    int num;
    int next[10];
};

str st[2000010];

int t;

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k,l;
    int a,b,now;
    for (k = 1;k <= 2000000;k++)
    {
        st[k].num = 0;
        l = getlen(k) - 1;
        now = k;
        a = k / first[l];
        b = k % first[l];
        for (i = 0;i <= l;i++)
        {
            now = b * 10 + a;
            a = now / first[l];
            b = now % first[l];
            if (a != 0 && now < k)
            {
                st[k].next[st[k].num++] = now;
            }
        }
        sort(st[k].next, st[k].next + st[k].num);
    }
    scanf("%d", &t);
    for (k = 1;k <= t;k++)
    {
        scanf("%d%d", &a, &b);
        int ans = 0;
        for (i = a + 1;i <= b;i++)
        {
            for (j = st[i].num - 1;j >= 0;j--)
            {
                if (st[i].next[j] < a)
                    break;
                ans++;
            }
        }
        printf("Case #%d: %d\n", k, ans);
    }
    return 0;
}
