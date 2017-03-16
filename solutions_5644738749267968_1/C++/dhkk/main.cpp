#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1005;
int n;
double a1[N], a2[N];

int cal(double a1[], double a2[])
{
    int l1 = 0, l2 = 0, r2 = n-1, ans = 0;
    while (l1 < n)
    {
        if (a1[l1] < a2[l2])
        {
            l1++;
            r2--;
        }
        else
        {
            l1++;
            l2++;
            ans++;
        }
    }
    return ans;
}

int main()
{
    freopen("D-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int _, cas = 0;
    scanf("%d", &_);
    while (_--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &a1[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &a2[i]);
        }
        sort(a1, a1+n);
        sort(a2, a2+n);
        printf("Case #%d: %d %d\n", ++cas, cal(a1, a2), n-cal(a2, a1));
    }
    return 0;
}
