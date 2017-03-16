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

void dfs(bool first, int index, const string& s1, const string& s2, int cur_value1, int cur_value2, int& v1, int& v2)
{
	int len = s1.length();
	auto& s = first ? s1 : s2;
	if(index == len)
	{
		if(first)
		{
			dfs(false, 0, s1, s2, cur_value1, cur_value2, v1, v2);
		}
		else
		{
			int cur_diff = abs(cur_value1 - cur_value2);
			int diff = abs(v1 - v2);
			if(cur_diff < diff)
			{
				v1 = cur_value1;
				v2 = cur_value2;
			}
			else if(cur_diff == diff)
			{
				if(cur_value1 < v1 || cur_value2 < v2)
				{
					v1 = cur_value1;
					v2 = cur_value2;
				}
			}
		}
	}
	else
	{
		if(s[index] == '?')
		{
			for(int i = 0; i < 10; ++i)
			{
				dfs(first, index + 1, s1, s2, first ? cur_value1 * 10 + i : cur_value1, first ? cur_value2 : cur_value2 * 10 + i, v1, v2);
			}
		}
		else
		{
			int num = s[index] - '0';
			dfs(first, index + 1, s1, s2, first ? cur_value1 * 10 + num : cur_value1, first ? cur_value2 : cur_value2 * 10 + num, v1, v2);
		}
	}
}

void solve_small(int index, istream& in, ostream& out)
{
	out << "Case #" << (index + 1) << ": ";
	string s1, s2;
	in >> s1 >> s2;
	int len = s1.length();

	int v1 = 1000, v2 = 0;
	dfs(true, 0, s1, s2, 0, 0, v1, v2);

	char format[128] = {0};
	sprintf(format, "%%0%dd %%0%dd", len, len);
	char buf[128] = {0};

	sprintf(buf, format, v1, v2);
	out << buf << endl;
}

void solve(istream& in, ostream& out)
{
	int tt;
	in >> tt;
	for(int t = 0; t < tt; ++t)
	{
		print_progress(t);
		solve_small(t, in, out);
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

