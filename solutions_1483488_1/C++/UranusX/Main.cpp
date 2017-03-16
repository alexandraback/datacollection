#include <cstdio>

int A, B;

int Work()
{
	scanf("%d%d", &A, &B);
	int Ans = 0;
	for (int i = A; i <= B; i ++)
	{
		int t = i;
		int Base = 1;
		while (Base * 10 <= i)
			Base *= 10;
		do
		{
			int F = t / Base;
			t -= Base * F;
			t *= 10;
			t += F;
			if (t > i && t <= B)
				Ans ++;
		}
		while (t != i);
	}
	return Ans;
}

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int Cases;
	scanf("%d", &Cases);
	for (int Case = 1; Case <= Cases; Case ++)
		printf("Case #%d: %d\n", Case, Work());
	return 0;
}