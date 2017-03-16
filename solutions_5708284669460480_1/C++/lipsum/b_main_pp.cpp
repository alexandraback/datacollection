#include <iostream>
#include <sstream>
#include <iomanip>

#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <string>

#include <numeric>
#include <utility>
#include <functional>
#include <algorithm>
#include <complex>
#include <memory>

#include <cstdio>
#include <cstdlib>
#include <cassert>

#include <cmath>
#include <climits>
#include <cfloat>

#include <cctype>
#include <cstring>

using namespace std;

#define FOR(M_i, M_from, M_to)	for(int M_i = (M_from); M_i < (M_to); ++M_i)
#define REP(M_i, M_n)				FOR(M_i, 0, M_n)
#define FOREACH(M_ite, M_c) for(decltype(M_c.begin()) M_ite = M_c.begin(); M_ite != M_c.end(); ++M_ite)

template<typename CONTAINER_T>
void read(istream& in, CONTAINER_T& list, size_t n)
{
	for(size_t i = 0; i < n; ++i)
	{
		CONTAINER_T::value_type value;
		in >> value;
		list.push_back(value);
	}
};

template<typename T, typename INDEX_T = int>
struct t_indexed_value
{
	typedef t_indexed_value<T, INDEX_T> self; 
	typedef T		value_t;
	typedef INDEX_T	index_t;

	value_t value;
	index_t index;

	bool operator <(const self& obj) const { return value < obj.value; }
	bool operator ==(const self& obj) const { return value == obj.value; }
	bool operator !=(const self& obj) const { return !(*this == obj); }
};

template<typename FORWARD_ITE>
void write(ostream& out, FORWARD_ITE first, FORWARD_ITE last, const string& sep = " ")
{
	if(first != last) { out << *first; ++first; }
	while(first != last)
	{
		out << sep << *first;
		++first;
	}
	out << endl;
}

#include <fstream>

template<typename T>
void print_result(ostream& out, int index, const T& result)
{
	out << "Case #" << (index + 1) << ": " << result << endl;
}

void print_progress(int i) { cout << "solving #" << i + 1 << "..." << endl; }

typedef char				sbyte;
typedef unsigned char		byte;
typedef unsigned short		ushort;
typedef unsigned int		uint;
typedef long long			ll;
typedef unsigned long long ull;


using p_map_t = map<char, double>;
p_map_t calc_p(const string& key)
{
	map<char, int> count_map;
	for(auto ch : key)
	{
		count_map[ch]++;
	}

	p_map_t p_map;
	double len = key.size();
	for(auto& p : count_map)
	{
		p_map[p.first] = p.second / len;
	}
	return p_map;
}

int calc_max_overlap_length(const string& word)
{
	int max_overlap = 0;
	for(int from = word.size() - 1; from > 0; --from)
	{
		if(strncmp(word.c_str() + from, word.c_str(), word.size() - from) == 0)
		{
			max_overlap = word.size() - from;
		}
	}
	return max_overlap;
}

int calc_max_appearance(int s, const p_map_t& p_map, const string& word)
{
	for(auto ch : word)
	{
		if(! p_map.count(ch)) { return 0; }
	}

	int max_overlap = calc_max_overlap_length(word);
	return 1 + (s - word.size()) / (word.size() - max_overlap);
}

double solve(int k, int l, int s, string key, string word)
{
	auto p_map = calc_p(key);
	int max_apperance = calc_max_appearance(s, p_map, word);
	if(max_apperance == 0) { return 0; }

	double word_p = 1;
	for(auto ch : word)
	{
		word_p *= p_map[ch];
	}
	return max_apperance - word_p * (s - l + 1);
}

void solve(istream& in, ostream& out)
{
	int tt;
	in >> tt;
	for(int t = 0; t < tt; ++t)
	{
		print_progress(t);
		int k, l, s;
		in >> k >> l >> s;
		string key;
		string word;
		in >> key >> word;
		out.precision(8);
		out << "Case #" << (t + 1) << ": " << solve(k, l, s, key, word) << endl;
	}

}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	if(argc == 2)
	{
		ifstream in(argv[1]);
		string out_path = argv[1];
		out_path += ".result";
		ofstream out(out_path);
		solve(in, out);
	}
	else
	{
		solve(cin, cout);
	}
	return 0;
}

