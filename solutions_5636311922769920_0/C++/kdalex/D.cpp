#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
	std::ifstream in;
	std::ofstream out;

	in.open(argv[1], std::ios_base::in);
	out.open(argv[2], std::ios_base::out);

	long long T, K, C, S;
	in >> T;
	for (int ii = 1; ii <= T; ++ii)
	{
		in >> K >> C >> S;
		if (S < K)
		{
			out << "Case #" << ii << ": IMPOSSIBLE" << std::endl;
			continue;
		}
		std::vector<long long> pos(S);
		for (int j = 0; j < C; ++j)
			for (int i = 0; i < K; ++i)
				pos[i] = K * pos[i] + i;
		out << "Case #" << ii << ": ";
		for (int i = 0; i < S; ++i)
			out << pos[i] + 1 << " ";
		out << std::endl;
	}
	return 0;
}
