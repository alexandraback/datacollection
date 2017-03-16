#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int counters[10000199];

bool is_palindrome(long long a)
{
	char buf[50] = "";
	sprintf(buf, "%I64d", a);

	int n = strlen(buf);

	for (int i = 0; i < (n) / 2; ++i)
	{
		if (buf[i] != buf[n - 1 - i])
			return false;
	}

	return true;
}

int main()
{
	freopen("C-large-1.in", "r", stdin);
	freopen("C-result.txt", "w", stdout);
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= 10000020; ++i)
	{
		long long y = i;
		y = y * y;
		if (is_palindrome(i) && is_palindrome(y))
		{
			counters[i] = counters[i-1] + 1;
			//printf("%d %lld\n", i, y);
		}
		else
			counters[i] = counters[i - 1];

	}

	for (int t = 0; t < T; ++t)
	{
		long long a, b;
		scanf("%I64d%I64d", &a, &b);

		long long start = sqrt((long double)a);
		long long end = sqrt((long double)b);

		start = std::max(start - 10, (long long)1);
		end = end + 10;

		if (a == 1)
			start = 1;
		else
		{
			while (start * start < a)
				start++;
		}

		if (b == 1)
			end = 1;
		else
		{
			while (end * end > b)
				end--;
		}

		printf("Case #%d: %d", t + 1, counters[end] - counters[start - 1]);


		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}