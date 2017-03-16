#include <stdio.h>
#include <string.h>

int recycle(int n, int b, char* hash)
{
    int cnt = 0, tn, tm;
    int i, j, m = 0;
    char a[16], t[16];

    for (tn = n; tn > 0;)
    {
	a[m++] = tn % 10 + '0';
	tn /= 10;
    }
    t[m] = 0;
    for (i = 1; i < m; i++)
    {
	tm = 0;

	for (j = 0; j < m; j++)
	    t[j] = a[(j + i) % m];
	for (j = m - 1; j >= 0; j--)
	    tm = tm * 10 + t[j] - '0';

	if (tm > n && tm <= b && !hash[tm])
	{
	    hash[tm] = 1;
	    cnt += 1;
	}
    }
    return (int)((double)(1 + cnt) * cnt / 2);
}

int main()
{
    int a, b, t, i, j, cnt;
    char hash[2000001];
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
	cnt = 0;
	scanf("%d%d", &a, &b);
	memset(hash, 0, sizeof(hash));
	for (j = a; j < b; j++)
	    if (!hash[j])
		cnt += recycle(j, b, hash);
	printf("Case #%d: %d\n", i + 1, cnt);
    }
    return 0;
}
