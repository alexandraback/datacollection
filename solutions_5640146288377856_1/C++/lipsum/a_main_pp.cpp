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

int solve_1d(int c, int w)
{
	if(c <= w) { return w; }
	if(c >= 2 * w) { return 1 + solve_1d(c - w, w); }
	else { return w + 1; }
}

int calc_no_match(int c, int w)
{
	if(c >= 2 * w) { return 1 + calc_no_match(c - w, w); }
	else { return 1; }
}

int solve(int r, int c, int w)
{
	return calc_no_match(c, w) * (r - 1) + solve_1d(c, w);
}

void solve(istream& in, ostream& out)
{
	int tt;
	in >> tt;
	for(int t = 0; t < tt; ++t)
	{
		print_progress(t);
		int r, c, w;
		in >> r >> c >> w;
		print_result(out, t, solve(r, c, w));
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

