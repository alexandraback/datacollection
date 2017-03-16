#include <stdio.h>
#include <string.h>

FILE * in = fopen("in.txt", "r");
FILE * out = fopen("out.txt", "w");

long long d[5][5];
char data[10006];
char ddat[10006];
long long n, k;

void pre()
{
	d[1][1] = 1;d[1][2] = 2; d[1][3] = 3; d[1][4] = 4;
	d[2][1] = 2;d[2][2] = -1;d[2][3] = 4; d[2][4] = -3;
	d[3][1] = 3;d[3][2] = -4;d[3][3] = -1;d[3][4] = 2;
	d[4][1] = 4;d[4][2] = 3; d[4][3] = -2;d[4][4] = -1;
}

bool p()
{
	long long i;
	long long x = 1;
	long long temp;
	long long s, e;

	for (i = 0; i < 10005; i++) data[i] = ddat[i] = 0;

	fscanf(in, "%lld %lld", &n, &k);

	fscanf(in, "%s", data);

	for (i = 0; i < n; i++)
	{
		if (data[i] == '1') data[i] = 1;
		if (data[i] == 'i') data[i] = 2;
		if (data[i] == 'j') data[i] = 3;
		if (data[i] == 'k') data[i] = 4;

		if (x < 0)
			x = d[-x][data[i]] * -1;
		else
			x = d[x][data[i]];
	}

	long long tt = x;

	x = 1;

	if (tt != -1)
	{
		long long kk = 1;

		if (tt < 0)
		{
			tt *= -1;
			kk = -1;
		}

		for (i = 1; i <= 8; i++)
		{
			if (x < 0)
			{
				x = d[-x][tt] * -1 * kk;
			}

			else
			{
				x = d[x][tt] * kk;
			}

			if (x == -1) break;
		}

		if (i > k || i == 9)
		{
			return false;
		}

		if (k > i)
		{
			if (k % i != 0) return false;

			if ((k / i) % 2 == 0)
			{
				return false;
			}
		}
	}

	else if (k % 2 == 0) return false;

	x = 1;

	for (i = 0; i < n; i++) ddat[i] = data[n - 1 - i];

	for (i = 0; i < 8 * n; i++)
	{
		if (x < 0)
			x = d[-x][data[i%n]] * -1;
		else
			x = d[x][data[i%n]];

		if (x == 2 || x == -2)
		{
			s = i;
			break;
		}
	}
	if (i == 8 * n) return false;

	x = 1;

	for (i = 0; i < 8 * n; i++)
	{
		if (x < 0)
			x = d[ddat[i%n]][-x] * -1;
		else
			x = d[ddat[i%n]][x];

		if (x == 4 || x == -4)
		{
			e = i;
			if (s + e + 2 <= n * k) return true;
		}
	}

	return false;
}

int main()
{
	long long i, t;

	pre();

	fscanf(in, "%lld", &t);

	for (i = 1; i <= t; i++)
	{
		bool a = p();

		if (a == true)
			fprintf(out, "Case #%lld: YES\n", i);

		else
			fprintf(out, "Case #%lld: NO\n", i);
	}
}