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


template<typename T>
void print_result(ostream& out, int index, const T& result)
{
	out << "Case #" << (index + 1) << ": " << result << endl;
}

void print_progress(int i) { cout << "solving #" << i + 1 << "..." << endl; }

int find_longest_list_to(vector<bool>& used, const vector<int>& list, int prev_pos)
{
	int n = list.size();
	int max_length = 0;
	for(int i = 0; i < n; ++i)
	{
		if(used[i]) { continue; }
		if(list[i] == prev_pos)
		{
			used[i] = true;
			max_length = max(max_length, 1 + find_longest_list_to(used, list, i));
			used[i] = false;
		}
	}
	return max_length;
}

void dfs(vector<bool>& used, const vector<int>& list, const int start_pos, int prev_pos, int cur_pos, int length, int& max_value, bool can_loop)
{
	const int n = list.size();
	used[cur_pos] = true;
	if(can_loop && list[cur_pos] == start_pos)
	{
		max_value = max(max_value, length);
	}

	if(list[cur_pos] == prev_pos)
	{
		int value1 = length + find_longest_list_to(used, list, cur_pos);
		int line_max_length = 0;
		for(int i = 0; i < n; ++i)
		{
			if(used[i]) { continue; }
			dfs(used, list, i, -1, i, 1, line_max_length, false);
		}
		int value2 = length + line_max_length;
		int value = max(value1, value2);
		max_value = max(max_value, value);
	}

	if(! used[list[cur_pos]])
	{		
		dfs(used, list, start_pos, cur_pos, list[cur_pos], length + 1, max_value, can_loop);
	}
	used[cur_pos] = false;
}

void solve(int index, istream& in, ostream& out)
{
	out << "Case #" << (index + 1) << ": ";
	int n; in >> n;
	vector<int> list(n);
	for(int i = 0; i < n; ++i) { in >> list[i]; --list[i]; }

	int max_value = 0;	
	for(int i = 0; i < n; ++i)
	{
		vector<bool> used(n, false);
		dfs(used, list, i, -1, i, 1, max_value, true);
	}

	out << max_value << endl;

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

