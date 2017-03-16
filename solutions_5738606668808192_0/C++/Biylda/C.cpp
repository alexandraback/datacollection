#include <stdio.h>
#include <math.h>

typedef unsigned long long ULL;

ULL divisor (ULL num)
{
    if (num <= 1)
        return 1;
    else if (num % 2 == 0)
        return 2;
    else
    {
        ULL d = 3;
        double num_d = static_cast<double>(num);
        ULL upperLimit = static_cast<ULL>(sqrt(num_d)+1);
        while (d < upperLimit)
        {
            if (num % d == 0)
                return d;
            d += 2;
        }
        return num;
    }
}

ULL convert(ULL x, int from, int to)
{
	ULL y = 0;
	ULL pow = 1;
	for (; x > 0; x /= from)
	{
		y += (x % from) * pow;
		pow *= to;
	}
	return y;
}

void print_binary(int x, int N)
{
	for (; N > 0; --N)
	{
		printf("%d", (x >> (N-1)) & 1);
	}
}

void jamcoins(int N, int J)
{
	int mul = 1;
	while (N > 16 && N % 2 == 0)
	{
		mul *= 2;
		N /= 2;
	}
	int min = 1<<(N-1);
	int max = 1<<N;
	ULL ib[11];
	ULL divb[11];
	for (int i = min+1; i < max && J > 0; i += 2)
	{
		bool isJam = true;
		for (int b = 2; b <= 10; ++b)
		{
			ib[b] = convert(i, 2, b);
			divb[b] = divisor(ib[b]);
			if (divb[b] == ib[b])
			{
				isJam = false;
				break;
			}
		}
		if (isJam)
		{
			for (int m = 1; m <= mul; ++m)
				print_binary(i, N);
			printf(" ");
			for (int b = 2; b <= 10; ++b)
			{
				printf("%llu%c", divb[b], b == 10 ? '\n' : ' ');
			}
			--J;
		}
	}
}

int main(int argc, char **argv)
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
	{
		int N, J;
		scanf("%d %d", &N, &J);
		printf("Case #%d:\n", t+1);
		jamcoins(N, J);
	}
	return 0;
}
