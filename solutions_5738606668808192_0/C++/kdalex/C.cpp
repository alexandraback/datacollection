#include <iostream>
#include <random>
#include <sstream>
#include <unordered_set>
#include <fstream>

std::string generateRandom(int bits)
{
	std::mt19937 rng = std::mt19937(std::random_device()());
	std::stringstream ss;
	for (int i = 0; i < bits; ++i)
		ss << (rng() % 2);
	return ss.str();
}

// ~ 1/2*2/3*4/5*6/7=20% of non-primes will not be caught
std::vector<int> primes = {2, 3, 5, 7};

int main(int argc, char **argv)
{
	std::ios_base::sync_with_stdio(0);
	int T, N, J;
	
	std::ifstream in;
	std::ofstream out;

	in.open(argv[1], std::ios_base::in);
	out.open(argv[2], std::ios_base::out);

	in >> T;
	for (int ii = 1; ii <= T; ++ii)
	{
		in >> N >> J;
		std::unordered_set<std::string> used;
		out << "Case #" << ii << ":" << std::endl;

		for (int i = 0; i < J;)
		{
			auto a = generateRandom(N);
			a[0] = a[N - 1] = '1';
			if (used.count(a))
				continue;
			used.insert(a);

			int D[11];
			bool allOk = true;
			for (int j = 2; j <= 10; ++j)
			{
				bool isOk = false;
				for (auto& p: primes)
				{
					int rem = 0;
					int pow = 1;
					for (int i = N - 1; i >= 0; --i)
					{
						rem = (rem + pow * (a[i] == '0' ? 0 : 1)) % p;
						pow = (pow * j) % p;
					}
					if (rem == 0)
					{
						isOk = true;
						D[j] = p;
						break;
					}
				}
				if (!isOk)
				{
					allOk = false;
					break;
				}
			}
			if (!allOk)
				continue;
			out << a << " ";
			for (int j = 2; j <= 10; ++j)
				out << D[j] << " ";
			out << std::endl;
			++i;
		}
	}
	return 0;
}
