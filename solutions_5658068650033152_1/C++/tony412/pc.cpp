#include <stdio.h>
#include <algorithm>

int n, m;

int maxNum(int x)
{
	int i, j;
	int v = x / 2, len;
	int ans = 0;

	for (i = 1; i <= n - 2; i++)
	{
		len = std::min(v-i, m-2);	
		ans = std::max(std::min(x+i*len, n*m), ans);
	}
	if (x & 1)
		return std::max(ans, maxNum(x+1)-2);
	else
		return ans;
}

int bs(int l, int r, int v)
{
/*
	int m;

	while (l < r)
	{
		m = (l + r) / 2;
		if (maxNum(m) < v)
			l = m + 1;
		else
			r = m;
	}
	return l;	
*/
	int i;
	for (i = l; i < r; i++)
		if (maxNum(i) >= v)
			return i;
	return i;

}



int main()
{
	int T, C;
	int i, j;
	int k;
	
	scanf("%d", &T);
	for (C = 1; C <= T; C++)
	{
		scanf("%d %d %d", &n, &m, &k);
		if (n > m) std::swap(n, m);
		printf("Case #%d: ", C);
		if (n <= 2)
			printf("%d\n", k);
		else
			printf("%d\n", bs(0, n*m, k));
	}
	return 0;
}
