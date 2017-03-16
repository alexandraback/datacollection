#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;
long long int reverse(long long int num)
{
	long long int result = 0;
	while (1)
	{
		result += num % 10;
		num /= 10;
		if (num == 0) break;
		result *= 10;
	}
	return result;
}
void main()
{
	FILE *fs = fopen("input.txt", "r");
	FILE *fp = fopen("output.txt", "w");

	int testcase;
	fscanf(fs, "%d", &testcase);

	for (int t = 0; t < testcase; t++)
	{
		fprintf(fp, "Case #%d:", t + 1);

		long long int n;
		long long int time=10;
		long long int num=10, renum;
		int ll,a,b,ln;
		fscanf(fs,"%lld", &n);

		ll = log10(n);

		if (ll == 0)
		{
			fprintf(fp," %lld\n", n);
			continue;
		}
		renum = reverse(n);
		if (t == 17)
		{
			t = t;
		}
		while (ll!=log10(num))
		{
			ln = log10(num);
			a = num / powl(10,(ln + 2) / 2);
			b = num % (int)(powl(10, (ln + 2) / 2));
			
			if (b == powl(10, (ln + 2) / 2) - 1)
			{
				num = reverse(num);
				ln = log10(num);
				time++;
				while (1){
					if ((int)log10(num) > ln) break;
					num++;
					time++;
				}
			}
			else{
				num++;
				time++;
			}
		}
		a = renum % (int)(powl(10, (ll + 2) / 2));
		b = n % (int)(powl(10, (ll + 2) / 2));
		if (a == 1) a--;
		if (a != 0 && b != 0)
			fprintf(fp, " %d\n", time + a + b);
		else
			fprintf(fp, " %d\n", time + a + (int)powl(10,ll));
	}
	fclose(fs);
	fclose(fp);
}