#include <stdio.h>
#include <memory.h>

#define MAXN 2000

int a[MAXN], b[MAXN];
int f[MAXN];
int n;

void init(void) 
{
    register int i;
    memset(f, 0, sizeof (f));
    scanf("%d", &n);
    for (i = 0; i < n; i++)
	scanf("%d%d", &a[i], &b[i]);
}

void solve(void) 
{
    int cnt = 0, ans = 0, last = -1;
    int i, xp, tMax;
    char flag;
    while (cnt > last) 
    {
	last = cnt;
	flag = 1;
	while (flag) 
	{
	    flag = 0;
	    for (i = 0; i < n; i++) 
	    {
		if (cnt >= a[i] && cnt >= b[i] && f[i] != 2) 
		{
		    cnt += (2 - f[i]);
		    f[i] = 2;
		    ans++;
		    flag = 1;
		}
	    }
	}
	xp = -1, tMax = 0;
	for (i = 0; i < n; i++)
	    if (f[i] == 0 && cnt >= a[i] && cnt < b[i] && b[i] > tMax) 
	    {
		tMax = b[i];
		xp = i;
	    }
	if (xp != -1) 
	{
	    f[xp] = 1;
	    cnt++;
	    ans++;
	}
    }
    if (cnt != 2 * n)
	printf("Too Bad\n");
    else
	printf("%d\n", ans);
}

int main() 
{
    int t, i;
    scanf("%d", &t);
    for (i = 0; i < t; i++) 
    {
	init();
	printf("Case #%d: ", i + 1);
	solve();
    }
    return 0;
}
