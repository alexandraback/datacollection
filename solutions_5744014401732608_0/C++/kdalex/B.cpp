#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <cassert>
#include <algorithm>
#include <string>

std::vector<std::string> solve(int B, int M)
{
	std::vector<std::string> res;
	if (1 << (B - 2) < M)
	{
		res.push_back("IMPOSSIBLE");
		return res;
	}
	int edges = (B - 1) * B / 2;
	int mm = 1 << edges;
	for (int mask = 0; mask < mm; ++mask)
	{
		int idx = 0;
		std::vector<int> cnt(B);
		cnt[0] = 1;
		for (int i = 1; i < B; ++i)
			for (int j = 0; j < i; ++j)
			{
				if (mask & (1 << idx))
					cnt[i] += cnt[j];
				idx++;
			}
		if (cnt[B - 1] == M)
		{
			int idx = 0;
			res.push_back("POSSIBLE");
			res.resize(B + 1);
			for (int i = 0; i < B; ++i)
			{
				res[i + 1].resize(B, '0');
			}
				
			for (int i = 0; i < B; ++i)
			{
				for (int j = 0; j < i; ++j)
				{
					if (j >= i)
						continue;
					if (mask & (1 << idx))
						res[j + 1][i] = '1';
					idx++;
				}
			}
			return res;
		}
	}
	assert(false);
	return res;
}

int main(int argc, char **argv)
{
	std::ios_base::sync_with_stdio(false);
	std::ifstream in;
	std::ofstream out;
	in.open(argv[1], std::ios_base::in);
	out.open(argv[2], std::ios_base::out);

	int T;
	in >> T;
	for (int i = 1; i <= T; ++i)
	{
		int M, B;
		in >> B >> M;
		auto res = solve(B, M);
		out << "Case #" << i << ": ";
		for (auto& s: res)
			out << s << std::endl;
	}
	return 0;
}
