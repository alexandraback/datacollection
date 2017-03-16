#include <iostream>
#include <cstdlib>
#include <vector>

uint64_t firstDivisor(uint64_t x, const std::vector<uint64_t>& primes)
{
	for (const auto& prime : primes)
	{
		if (prime >= x)
			return 1;
		if ((x % prime) == 0)
		{
			return prime;
		}
	}
	return 1;
}

uint64_t From2toBase(uint64_t num, int base)
{
	if (base == 2)
	{
		return num;
	}
	uint64_t ret = 0ull;
	uint64_t currExp = 1;
	while (num)
	{
		if (num % 2)
		{
			ret += currExp;
		}
		currExp *= base;
		num /= 2;
	}
	return ret;
}

int main(int argc, char** argv)
{
	uint32_t N, J;

	N = 16;
	J = 50;

	// N = std::atoi(argv[1]);
	// J = std::atoi(argv[2]);

	// const auto maxVal = 1111111111111111ull;

	const auto sqrtMaxVal = 33333334ull;

	std::vector<bool> sieve(sqrtMaxVal, false);
	std::vector<uint64_t> primes;
	for (auto i = 2u; i < sqrtMaxVal; ++i)
	{
		if ((i % 2) == 0 && i != 2)
			continue;
		if (!sieve[i])
		{
			primes.push_back(i);
			for (auto j =  2 * i; j < sqrtMaxVal; j += i)
			{
				sieve[j] = true;
			}
		}
	}

	auto current = (1ull << (N - 1)) + 1ull;

	std::cout << "Case #1:\n";
	while (J)
	{
		std::vector<uint64_t> nums;
		current += 2;
		for (auto base = 2; base <= 10; ++base)
		{
			const auto num = From2toBase(current, base);
			const auto divisor = firstDivisor(num, primes);
			if (divisor == 1)
				break;
			nums.push_back(divisor);
		}
		if (nums.size() == 9)
		{
			--J;
			std::cout << From2toBase(current, 10) << " ";
			for (auto it = nums.begin(); it != nums.end(); ++it)
			{
				std::cout << *it << " ";
			}
			std::cout << "\n";
		}
	}
	return 0;
}