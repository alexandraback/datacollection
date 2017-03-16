#include <cassert>
#include <fstream>
#include <string>
#include <vector>

long long
reverse(long long K)
{
	long long ret = 0;

	while (K != 0)
	{
		ret = ret * 10 + K % 10;
		K /= 10;
	}

	return ret;
}

long long
calc(long long N)
{
	assert(N >= 1);

	long long p = N / 10;
	long long q = N % 10;

	if (p == 0)
	{
		return q;
	}
	else
	{
		int len = 1;
		long long t = p;
		while (t != 0)
		{
			len++;
			t /= 10;
		}

		long long high = N;
		long long low = 0;
		long long m_low = 1;

		for (int i = 0; i < (len + 1) / 2; i++)
		{
			low += m_low * (high % 10);
			high /= 10;

			m_low *= 10;
		}

		if (low == 1)
		{
			long long r = reverse(N);
			assert(r <= N);

			if (r < N)
			{
				return (1 + calc(r));
			}
			else
			{
				return (1 + calc(N - 1));
			}
		}
		else if (low == 0)
		{
			return (1 + calc(N - 1));
		}
		else
		{
			return ((low - 1) + calc(N - (low - 1)));
		}
	}
}

#ifdef DEBUG_CALC
long long
check(long long N)
{
	std::vector<int> c(N + 1, -1);
	std::vector<long long> path(N + 1, -1);

	for (long long i = N; i >= 1; i--)
	{
		c[i] = N - i + 1;

		if (i < N)
		{
			path[i] = i + 1;
		}
	}

	for (long long i = N; i >= 1; i--)
	{
		long long r = reverse(i);

		if (r < i
			&& reverse(r) == i)
		{
			if (c[i] + 1 < c[r])
			{
				c[r] = c[i] + 1;
				path[r] = i;
			}
		}

		if (c[i - 1] > c[i] + 1)
		{
			c[i - 1] = c[i] + 1;
			path[i - 1] = i;
		}
	}

#ifdef DEBUG_CALC_PRINT
	long long tr = 1ll;
	while (path[tr] != -1)
	{
		if (tr + 1 != path[tr])
		{
			printf("%lld -> %lld\n", path[tr], tr);
		}
		tr = path[tr];
	}
	printf("%lld\n", N);
	printf("\n");
#endif /* DEBUG_CALC_PRINT */

	return c[1];
}
#endif /* DEBUG_CALC */

int
main(int argc, char **argv)
{
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	int T;
	in >> T;
	for (int t = 0; t < T; t++)
	{
		long long N;
		in >> N;

		long long answer = calc(N);

#ifdef DEBUG_CALC
		long long checked = check(N);

#ifdef DEBUG_CALC_PRINT
		if (checked != answer)
		{
			printf("%lld %lld %lld\n", N, answer, checked);
		}
#endif /* DEBUG_CALC_PRINT */
#endif /* DEBUG_CALC */

		out << "Case #" << (t + 1) << ": " << answer << std::endl;
	}

	in.close();
	out.close();

	return 0;
}