#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small-attempt0.out", "w", stdout);
    int t, Case = 0;
    scanf("%d",&t);
    while (t--)
    {
        int n,s1=0,s2=0;
        double a[1005],b[1005];
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
            scanf("%lf",&a[i]);
        for (int i = 0; i < n; i++)
            scanf("%lf",&b[i]);
        sort(a, a + n);
        sort(b, b + n);
        int l1, l2, r1, r2;
        l1 = 0; l2 = 0; r1 = n - 1; r2 = n - 1;
        for (int round = 0; round < n; round++)
        {
            if (a[l1] < b[l2]) { l1++; r2--;}
            else
            {
                l1++;l2++;
                s1++;
            }
        }
        l1 = 0; l2 = 0; r1 = n - 1; r2 = n - 1;
        for (int round = 0; round < n; round++)
        {
            if (b[r2] < a[r1])
            {
                r1--;l2++;
                s2++;
            }
            else
            {
                r1--;r2--;
            }
        }
        printf("Case #%d: %d %d\n",++Case,s1,s2);
    }
    return 0;
}