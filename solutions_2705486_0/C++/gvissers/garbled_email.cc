#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <set>

template <typename Container>
void readN(std::istream& is, Container& cont, size_t n)
{
	std::copy_n(std::istream_iterator<typename Container::value_type>(is), n,
		std::inserter(cont, cont.end()));
}

int countErrors(const std::string& w, const std::string &s, int n)
{
	int c = n;
	for (unsigned int i = 0; i < w.size(); ++i)
		if (w[i] != s[i] && --c == 0) return n;
	return n - c;
}

int match(const std::set<std::string>& words, const std::string& s, int n)
{
	if (words.find(s) != words.end())
		return 0;

	for (const std::string& w: words)
	{
		int m = countErrors(w, s, n);
		if (m < n)
			n = m;
	}

	return n;
}

int findOpt(const std::map<int, std::set<std::string>>& ldict, const std::string& S)
{
	std::vector<int> minupto(S.size()+1, S.size()+1);
	minupto[0] = 0;
	for (unsigned int i = 1; i <= S.size(); ++i)
	{
		// 'a' is in the dictionary
		minupto[i] = minupto[i-1] + (S[i-1] == 'a' ? 0 : 1);

		for (unsigned int j = 0; j < i; ++j)
		{
			unsigned int l = i-j;
			if (ldict.find(l) == ldict.end())
				continue;
			int m = minupto[j] + match(ldict.at(l), S.substr(j, l), minupto[i]);
			if (m < minupto[i])
			{
				minupto[i] = m;
				if (m == 0) break;
			}
		}
	}

	return minupto[S.size()];
}

int findOpt2(const std::map<int, std::set<std::string>>& ldict, const std::string& S,
	std::map<std::string, int>& cache)
{
	if (cache.find(S) != cache.end())
		return cache[S];

	if (ldict.find(S.size()) != ldict.end() && ldict.at(S.size()).count(S) > 0)
	{
		cache[S] = 0;
	}
	else if (S.size() == 1)
	{
		cache[S] = 1;
	}
	else
	{
		int n = S.size();
		if (ldict.find(S.size()) != ldict.end())
			n = match(ldict.at(S.size()), S, n);
		for (unsigned int i = 1; i < S.size(); ++i)
		{
			int m = findOpt2(ldict, S.substr(0, i), cache)
				+ findOpt2(ldict, S.substr(i), cache);
			if (m < n) n = m;
		}
		cache[S] = n;
	}

	return cache[S];
}

int main(int argc, const char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input-file>\n";
		return 1;
	}

	std::map<int, std::set<std::string>> ldict;
	std::ifstream dis("garbled_email_dictionary.txt");
	std::string s;
	while (true)
	{
		dis >> s;
		if (!dis.good())
			break;
		ldict[s.size()].insert(s);
	}
	dis.close();

	std::ifstream is(argv[1]);
	if (!is.good())
	{
		std::cerr << "Unable to open input file " << argv[1] << "\n";
		return 1;
	}

	int nr_cases;
	is >> nr_cases;
	if (!is.good())
	{
		std::cerr << "Failed to read number of test cases\n";
		return 1;
	}

	std::map<std::string, int> cache;
	for (int icase = 1; icase <= nr_cases; ++icase)
	{
		std::string S;
		is >> S;

		std::cout << "Case #" << icase << ": " << findOpt2(ldict, S, cache) << '\n';
//		std::cout << "Case #" << icase << ": " << findOpt(ldict, S) << '\n';
	}

	return 0;
}
