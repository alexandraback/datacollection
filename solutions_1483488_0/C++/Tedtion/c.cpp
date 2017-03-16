#include <stdio.h>

int num_of_digit(int n)
{
	int num = 0;
	while (n) {
		num++;
		n/=10;
	}
	return num;
}

int main()
{
	int t, a, b, i, j, k, k10, num, n, m;

 	freopen("c-small.in", "r", stdin);
	freopen("c_small.out", "w", stdout);

	scanf("%d",&t);
	for (int cas = 1; cas <= t; cas++)
	{
		scanf("%d%d",&a,&b);
		num = 0;
		k = num_of_digit(a);
		for (j=1, k10=1; j<k; j++) k10 *= 10;

		for (i=a; i<b; i++)
		{
			n = m = i;
			do {
				m = m/10 + m%10 * k10;
				if (m > n && m <= b) num++;
			} while (m != n);
		}
		printf("Case #%d: %d\n", cas, num);
	}
	return 0;
}
