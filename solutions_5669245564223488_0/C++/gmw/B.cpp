#include <assert.h>
#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include <boost/function.hpp>
#include <set>
#include <vector>

using std::cout; using std::cin; using std::cerr; using std::endl;
using std::string;
using std::ios;

struct Set
{
	int ord;
	bool burned;
	char first;
	char last;
	std::set<char> chars;
};

void precompute()
{
}

int burned[256];
std::vector<Set> sets;
std::vector<std::vector<Set *> > ptrs(256);

string indent(int n)
{
	string ret;
	ret.resize(n);
	for (int i = 0; i < n; i++)
		ret[i] = ' ';
	return ret;
}

long dfs(char prev, long pos)
{
	//cerr << "dfs(" << prev << "," << pos << endl;
	if (pos == sets.size())
	{
		//cerr << indent(pos * 2) << "*" << endl;
		return 1;
	}
	
	int total = 0;
	for (int i = 0; i < sets.size(); i++)
	{
		if (sets[i].burned)
			continue;
		sets[i].burned = true;

		if (sets[i].chars.count(prev) > 0 && sets[i].first != prev)
		{
			//cerr << "early " << i << sets[i].first << prev << endl;
			continue;
		}

		//cerr << indent(pos * 2);
		//cerr << "[" << i << "]";
		//for (char c: sets[i].chars)
			//cerr << c;
		//cerr << endl;

		bool ok = true;
		for (auto chr: sets[i].chars)
		{
			if (chr == prev)
				continue;

			if (burned[chr])
			{
				ok = false;
				//cerr << "break burned " << chr << " prev=" << prev << endl;
				break;
			}

			for (Set *pset: ptrs[chr])
			{
				if (pset->burned)
					continue;
				if (pset->chars.count(chr) > 0 && (pset->first != sets[i].last))
				{
					ok = false;
					//cerr << "break indirect " << chr << " " << pset->ord << endl;
					break;
				}
			}
			if (!ok)
				break;
		}
		if (!ok)
		{
			sets[i].burned = false;
			continue;
		}

		for (auto chr: sets[i].chars)
			burned[chr]++;

		total += dfs(sets[i].last, pos + 1);

		for (auto chr: sets[i].chars)
			burned[chr]--;
		sets[i].burned = false;
	}

	return total;
}

void test_case(std::istream &in, std::ostream &out, int case_num, const std::vector<std::string> &inp)
{
	std::fill(burned, burned + 256, 0);
	sets.resize(inp.size());
	for (int i = 0; i < 256; i++)
		ptrs[i].clear();

	for (int i = 0; i < inp.size(); i++)
	{
		sets[i].ord = i;
		sets[i].burned = false;
		sets[i].first = inp[i][0];
		sets[i].last = inp[i][inp[i].length() - 1];
		sets[i].chars.clear();
		for (int j = 0; j < inp[i].length(); j++)
			sets[i].chars.insert(inp[i][j]);

		for (char c: sets[i].chars)
			ptrs[c].push_back(&sets[i]);
	}

	long ans = dfs('!', 0);
	cerr << "Case #" << case_num << ": " << ans << "\n";
	out << "Case #" << case_num << ": " << ans << "\n";
}

int main(int argc, const char *argv[])
{
	try
	{
		const string problem = "B";
		string num;
		if (argc < 2 || (argv[1] != string("ex") && argc != 3) || (argv[1] == string("ex") && argc != 2))
		{
			cerr << "Usage: " << argv[0] << " ex|small <n>|large <n>" << endl;
			return 1;
		}
		if (argc == 3)
			num = string("-") + argv[2];

		const string in_filename = "source\\" + problem + "-" + argv[1] + num + ".in";
		std::ifstream in(in_filename.c_str(), ios::in);
		if (!in)
			throw std::runtime_error(in_filename + " not found");

		const string out_filename = "source\\" + problem + "-" + argv[1] + num + ".out";
		std::ofstream out(out_filename.c_str(), ios::out);
		if (!out)
			throw std::runtime_error(out_filename + " not found");

		precompute();

		int T;
		in >> T;
		std::vector<std::string> inp;
		for (int t = 1; t <= T; t++)
		{
			cerr << "TC " << t << " ";
			int N;
			in >> N;
			inp.resize(N);
			for (int i = 0; i < N; i++)
			{
				in >> inp[i];
				cerr << "(" << inp[i] << ")";
			}
			cerr << endl;
			test_case(in, out, t, inp);
		}

		out.close();
		in.close();

		return 0;
	}
	catch (std::exception &e)
	{
		cerr << "ERROR: " << e.what() << endl;
	}
	catch (...)
	{
		cerr << "UNKNOWN ERROR (...)" << endl;
	}

	return 1;
}

