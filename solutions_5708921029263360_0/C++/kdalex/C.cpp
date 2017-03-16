#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <cassert>
#include <algorithm>
#include <string>

std::ifstream in;
std::ofstream out;

void print_jps(long long J, long long P, long long S, long long K)
{
	out << J * P * S << std::endl;
	for (long long j = 0; j < J; ++j)
		for (long long p = 0; p < P; ++p)
			for (long long s = 0; s < S; ++s)
				out << j + 1 << " " << p + 1 << " " << s + 1 << std::endl;
}
void print_jp(long long J, long long P, long long S, long long K)
{
	out << J * P * K << std::endl;
	for (long long j = 0; j < J; ++j)
		for (long long p = 0; p < P; ++p)
			for (long long s = 0; s < K; ++s)
				out << j + 1 << " " << p + 1 << " " << s + 1 << std::endl;
}
void print_js(long long J, long long P, long long S, long long K)
{
	out << J * K * S << std::endl;
	for (long long j = 0; j < J; ++j)
		for (long long p = 0; p < K; ++p)
			for (long long s = 0; s < S; ++s)
				out << j + 1<< " " << p + 1 << " " << s + 1<< std::endl;
}
void print_ps(long long J, long long P, long long S, long long K)
{
	out << K * P * S << std::endl;
	for (long long j = 0; j < K; ++j)
		for (long long p = 0; p < P; ++p)
			for (long long s = 0; s < S; ++s)
				out << j + 1<< " " << p + 1 << " " << s + 1 << std::endl;
}

void solve(long long J, long long P, long long S, long long K)
{
#if 0
	std::pair<long long, decltype(&print_js)> foo[] = {
		std::make_pair(J * P * S, &print_jps),
		std::make_pair(J * P * K, &print_jp),
		std::make_pair(J * S * K, &print_js),
		std::make_pair(P * S * K, &print_ps)
	};
	std::sort(std::begin(foo), std::end(foo));
	J = std::min(J, K);
	P = std::min(P, K);
	S = std::min(S, K);
	foo[0].second(J, P, S, K);
#else
	std::vector<std::tuple<long long, long long, long long>> foo;
	for (long long j = 0; j < J; ++j)
		for (long long p = 0; p < P; ++p)
			for (long long s = 0; s < S; ++s)
				foo.emplace_back(j + 1, p + 1, s + 1);
	std::map<std::pair<long long, long long>, long long> jp, ps, js;
	std::vector<std::tuple<long long, long long, long long>> sel;
	for (auto& tt: foo)
	{
		long long j = std::get<0>(tt), p = std::get<1>(tt), s = std::get<2>(tt);
		if (jp[std::make_pair(j, p)] == K)
			continue;
		if (js[std::make_pair(j, s)] == K)
			continue;
		if (ps[std::make_pair(p, s)] == K)
			continue;
		sel.push_back(tt);
		jp[std::make_pair(j, p)]++;
		js[std::make_pair(j, s)]++;
		ps[std::make_pair(p, s)]++;
	}
	out << sel.size() << std::endl;
	for (auto& tt: sel)
		out << std::get<0>(tt) << " " << std::get<1>(tt) << " " << std::get<2>(tt) << std::endl;
#endif
}

int main(int argc, char **argv)
{
	std::ios_base::sync_with_stdio(false);
	in.open(argv[1], std::ios_base::in);
	out.open(argv[2], std::ios_base::out);

	int T;
	in >> T;
	for (int i = 1; i <= T; ++i)
	{
		long long J, P, S, K;
		in >> J >> P >> S >> K;
		out << "Case #" << i << ": ";
		solve(J, P, S, K);
	}
	return 0;
}
