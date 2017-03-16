#include <fstream>
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>

std::vector<long long> solve(long long K, long long C, long long S)
{
	if (C * S < K)
		return {};
	int nS = (K + C - 1) / C;
	//std::cout << nS << std::endl;
	assert(nS <= S);

	std::vector<long long> pos(nS);
	std::vector<std::vector<long long>> check(nS);
	int kS = 0;
	for (int i = 0; i < K; ++i)
		(check[kS].size() < C ? check[kS] : check[++kS]).push_back(i);

	for (int j = 0; j < C; ++j)
		for (int i = 0; i < nS; ++i)
			pos[i] = K * pos[i] + check[i][std::min(j, (int)check[i].size() - 1)];
	for (auto& p: pos)
		p++;
	return pos;
}

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
		/*
		 * We can check up to C tiles per student, resulting
		 * in C*S tiles total
		 * So C*S>=K => OK
		 */
		auto sol = solve(K, C, S);
		out << "Case #" << ii << ": "; 
		if (!sol.size())
		{
			out << "IMPOSSIBLE" << std::endl;
			continue;
		}

		for (auto& pt: sol)
			out << pt << " ";
		out << std::endl;
	}
	return 0;
}
