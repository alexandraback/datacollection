#include <stdio.h>

#define MAXN 100100

int main() 
{
    int t, a, b, i, j;
    double tmp, ans;
    double p[MAXN];
    double f[MAXN];
    scanf("%d", &t);
    f[0] = 1;
    for (i = 0; i < t; i++)
    {
	scanf("%d%d", &a, &b);
	for (j = 1; j <= a; j++) 
	{
	    scanf("%lf", &p[j]);
	    f[j] = f[j - 1] * p[j];
	}
	ans = b + 2;
	for (j = 0; j <= a; j++) 
	{
	    tmp = a - j + f[j] * (b - j + 1) + (1 - f[j])*(2 * b - j + 2);
	    ans = tmp < ans ? tmp : ans;
	}
	printf("Case #%d: %.6lf\n", i + 1, ans);
    }
    return 0;
}
