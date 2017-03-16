#include "bind.h"
const int p[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
int l[2000000];
int main()
{
	bind("C-large");
	int n, t, i, t1, t2;
	inf >> n;
	for (int k = 0; k < n; k++)
	{
		memset(l, 0, sizeof(l));
		inf >> t1 >> t2;
		int number = 0;
		for (i = t1; i <= t2; i++)
		{
			t = i;
			int top = 0;
			while (p[top] <= t)
				top++;
			int a = t, b = 0;
			for (int j = 0; j < top; j++)
			{
				b = b + a % 10 * p[j];
				a /= 10;
				int t3 = b * p[top - 1 - j] + a;
				if (t3 <= t2 && t3 > t && l[t3] != t)
				{
					number++;
					l[t3] = t;
				}
			}
		}
		ouf << "Case #" << k + 1 << ": " << number << "\n";
	}
	return 0;
}
