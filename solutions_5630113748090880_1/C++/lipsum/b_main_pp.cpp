#include <iostream>
#include <fstream>
#include <string>

#include <sstream>
#include <iomanip>

#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <bitset>

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
#define REP(M_i, M_n)			FOR(M_i, 0, M_n)
#define FOREACH(M_ite, M_c)		for(decltype(M_c.begin()) M_ite = M_c.begin(); M_ite != M_c.end(); ++M_ite)

#define DUMP(x)			cerr << #x << " = " << (x) << endl
#define DUMP_C(M_c)		FOREACH(ite, M_c){ cerr << *ite << ", "; } cerr << endl
#define DUMP_CS(M_c)	FOREACH(ite, M_c){ cerr << *ite << " "; } cerr << endl
#define DUMP_CN(M_c)	FOREACH(ite, M_c){ cerr << *ite << endl; } cerr << endl

typedef char				sbyte;
typedef unsigned char		byte;
typedef unsigned short		ushort;
typedef unsigned int		uint;
typedef long long			ll;
typedef unsigned long long ull;

#ifdef _DEBUG
#ifndef ASSERT
#define ASSERT(M_expr) if(! (M_expr) ) {DebugBreak();}
#endif

#ifndef VERIFY
#define VERIFY(M_expr) ASSERT(M_expr)
#endif

#else 

#ifndef ASSERT
#define ASSERT(M_expr) (void)0
#endif

#ifndef VERIFY
#define VERIFY(M_expr) (M_expr)
#endif

#endif

template<typename T>
void print_result(ostream& out, int index, const T& result)
{
	out << "Case #" << (index + 1) << ": " << result << endl;
}

void print_progress(int i) { cout << "solving #" << i + 1 << "..." << endl; }

void solve(int index, istream& in, ostream& out)
{
	out << "Case #" << (index + 1) << ":";
	int n; in >> n;
	vector<vector<int>> list(2 * n - 1, vector<int>(n));
	for(int y = 0; y < 2 * n - 1; ++y)
	{
		auto& v = list[y];
		for(int x = 0; x < n; ++x)
		{
			in >> v[x];
		}
	}

	map<int, int> m;
	for(auto& v : list)
	{
		for(auto i : v)
		{
			m[i]++;
		}
	}

	vector<int> missing;
	for(auto p : m)
	{
		if(p.second % 2 != 0)
		{
			missing.push_back(p.first);
		}
	}

	ASSERT(missing.size() == n);

	sort(missing.begin(), missing.end());
	for(auto i : missing)
	{
		out << " " << i;
	}
	out << endl;
}

void solve(istream& in, ostream& out)
{
	int tt;
	in >> tt;
	for(int t = 0; t < tt; ++t)
	{
		print_progress(t);
		solve(t, in, out);
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

