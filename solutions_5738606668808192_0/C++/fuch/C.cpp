#define _SCL_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS 

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

//const int N = 6, J = 100;
const int N = 16, J = 50;
//const int N = 32, J = 500;

std::vector<int> primes;
void gen_prime()
{
	const int M = (int)(pow(10, N / 2)) + 1;
	bool *used = new bool[M];
	std::fill(used, used + M, true);
	for (int i = 2; i * i <= M; ++i)
	{
		if (!used[i]) continue;
		for (int j = i * 2; j < M; j += i) used[j] = false;
	}
	primes.clear();
	for (int i = 2; i <= M; ++i)
	{
		if (used[i]) primes.push_back(i);
	}
	delete[] used;
}

int check_div(long long n)
{
	for (int i = 0; i < (int)primes.size() && primes[i] < n; ++i)
	{
		if (n % primes[i] == 0) return primes[i];
	}
	return 0;
}

void solve_brute()
{
	int left = J;
	for (unsigned i = 0; i < (1 << (N - 2)); ++i)
	{
		unsigned num = (1 << (N - 1)) | (i << 1) | 1;
		int divs[9];
		divs[0] = check_div(num);
		if (divs[0] == 0) continue;
		bool ok = true;
		for (int b = 3; b <= 10; ++b)
		{
			long long tmp = 0, p = 1;
			for (int j = 0; j < N; ++j)
			{
				if (num & (1 << j)) tmp += p;
				p *= b;
			}
			divs[b - 2] = check_div(tmp);
			if (divs[b - 2] == 0)
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			for (int j = N - 1; j >= 0; --j)
			{
				putchar((num & (1 << j)) ? '1' : '0');
			}
			for (int b = 2; b <= 10; ++b)
			{
				printf(" %d", divs[b - 2]);
			}
			puts("");
			if (--left == 0) break;
		}
	}
}

int main()
{
	gen_prime();
	printf("%d primes\n", (int)primes.size());
	//for (int i = 0; i < 10; ++i) printf("%d\n", primes[i]);
	solve_brute();
	return 0;
}