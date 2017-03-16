#include <stdio.h>

int t, tn;
int r, c, w;
int ans;

int min(int a, int b) {return a < b ? a : b;}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("result.out", "w", stdout);
    scanf("%d", &t);
    for (tn = 1; tn <= t; tn++)
    {
        scanf("%d %d %d", &r, &c, &w);
        ans = (r-1)*(c/w);
        while (c > 2*w)
        {
            c -= w;
            ans++;
        }
        ans += min(w+1, c);
        printf("Case #%d: %d\n", tn, ans);
    }
}