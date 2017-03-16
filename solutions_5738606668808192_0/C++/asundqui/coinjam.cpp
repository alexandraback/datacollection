#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long Digits(int coin, int base)
{
	long long value = 0;
	long long mult = 1;
	for (int i = 0; i < 16; ++i)
	{
		if (coin & (1 << i))
			value += mult;
		mult *= base;
	}
	return value;
}

int FindFactor(long long value)
{
	int limit = floor(sqrt(value));
	for (int factor = 2; factor <= limit; ++factor)
		if ((value % factor) == 0)
			return factor;
	return 0;
}

int main() {
	cout << "Case #1:" << endl;
	int N = 16;
	int J = 50;
	int num_found = 0;

	int first_coin = (1 << (N - 1)) + 1;
	int last_coin = (1 << N) - 1;
	vector<int> factors(11);
	for (int coin = first_coin; coin <= last_coin; coin += 2)
	{
		bool found_prime = false;
		for (int base = 2; base <= 10; ++base)
		{
			long long value = Digits(coin, base);
			factors[base] = FindFactor(value);
			if (factors[base] == 0)
			{
				found_prime = true;
				break;
			}
		}
		if (!found_prime)
		{
			cout << Digits(coin, 10);
			for (int base = 2; base <= 10; ++base)
				cout << " " << factors[base];
			cout << endl;
			if (++num_found == J)
				break;
		}
	}
	return 0;
}
