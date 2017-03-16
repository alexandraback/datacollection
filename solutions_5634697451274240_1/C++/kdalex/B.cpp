#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <random>
#include <unordered_set>

//    len   F  L
/*
 * F[0][*][*] = 0
 * F[x][*][0] = F[x - 1][*][1]
 * F[x][0][1] = F[x - 1][1][1] + 1
 * F[x][1][1] = min(F[x - 1][0][1], F[x - 1][0][0]) + 1
 */
const int MAXLEN = 1000000;
int F[MAXLEN][2][2];

void fill()
{
	for (int i = 1; i < MAXLEN; ++i)
	{
		F[i][0][0] = F[i - 1][0][1];
		F[i][1][0] = F[i - 1][1][0];
		F[i][0][1] = F[i - 1][1][1] + 1;
		F[i][1][1] = F[i - 1][0][1] + 1;
	}
}

std::string strip(std::string s)
{
	std::string res(s);
	int lastOk = 0;
	for (auto& c: s)
		if (!lastOk || res[lastOk - 1] != c)
			res[lastOk++] = c;
	res.resize(lastOk && *res.rbegin() == '+' ? lastOk - 1 : lastOk);
	return res;
}

int getSwaps2(std::string s)
{
	s = strip(s);
	return s.size() ? F[s.size()][s[0] == '-' ? 1 : 0][*s.rbegin() == '-' ? 1 : 0] : 0;
}

int getSwaps(std::string s)
{
	std::unordered_set<std::string> visited = {s};
	std::vector<std::string> ss[2] = {{s}, {}};
	for (int i = 0; ; ++i)
	{
		for (auto& s: ss[i % 2])
		{
			bool currOk = true;
			for (auto& c: s)
				if (c == '-')
				{
					currOk = false;
					break;
				}
			if (currOk)
				return i;
		}
		int curr = i % 2;
		int next = 1 - curr;
		ss[next].clear();
		for (auto& s_: ss[curr])
		{
			std::string s = strip(s_);
			for (int i = 1; i <= s.size(); ++i)
			{
				std::string sss = s;
				for (int j = 0; j < i; ++j)
					sss[j] = s[i - j - 1] == '+' ? '-' : '+';
				if (visited.count(sss))
					continue;
				visited.insert(sss);
				ss[next].emplace_back(std::move(sss));
			}
		}
	}
	return -1;
}

int main(int argc, char **argv)
{
	std::ifstream in;
	std::ofstream out;
	in.open(argv[1], std::ios_base::in);
	out.open(argv[2], std::ios_base::out);

	fill();

	int T;
	std::string S;
	in >> T;

	for (int i = 1; i <= T; ++i)
	{
		in >> S;
		out << "Case #" << i << ": " << getSwaps2(S) << std::endl;
	}
	return 0;
}
