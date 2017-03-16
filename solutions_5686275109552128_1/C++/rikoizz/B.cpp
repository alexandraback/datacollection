#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
int n;
int a[1010];
int com(int a,int b)
{
    return a > b;
}
bool judge(int x)
{
    for (int i = 0;i < x;i++)
    {
        int k = x - i;
        int tmp = i;
        for (int j = 1;j <= n;j++)
        {
            int now = a[j];
            while (now > k)
            {
                tmp--;
                now -= k;
            }
        }
        if (tmp >= 0) return 1;
    }
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int _;
    scanf("%d",&_);
    for (int __ = 1; __ <= _; __++)
    {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1,com);
        int l = 0,r = 1010;
        while (l < r - 1)
        {
            int m = (l + r)/2;
            if (judge(m)) r = m;
            else
                l = m;
        }
        printf("Case #%d: %d\n",__,r);
    }
}
