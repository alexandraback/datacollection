#include <fstream>

uint64_t powexp(uint64_t base, int exponent)
{
	uint64_t res = 1;
	uint64_t pow2val = base;
	while (exponent)
	{
		if (exponent % 2)
		{
			res *= pow2val;
		}
		pow2val *= pow2val;
		exponent /= 2;
	}
	return res;
}

int main()
{
	std::ifstream fin("fractiles.in");
	std::ofstream fout("fractiles.out");
	int T, K, C, S;
	fin >> T;
	for (auto i = 1; i <= T; ++i)
	{
		fout << "Case #" << i << ": ";
		fin >> K >> C >> S;
		const auto minS = std::max(1, K / C + ((K % C) ? 1 : 0));
		if (S < minS)
		{
			fout << "IMPOSSIBLE";
		}
		else
		{
			const auto initial_stride = powexp(K, C - 1);
			for (auto i = 0; i < minS; i++)
			{
				auto res = 1ull;
				const auto maxiter = std::min((i + 1) * C, K);
				auto stride = initial_stride;
				for (auto idx = i * C; idx < maxiter; ++idx, stride /= K)
				{
					res += idx * stride;
				}
				fout << res << " ";
			}

		}
		fout << "\n";
	}
	fin.close();
	return 0;
}