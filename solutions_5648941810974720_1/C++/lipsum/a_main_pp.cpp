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

void solve(int index, istream& in, ostream& out)
{
	out << "Case #" << (index + 1) << ": ";
	string s;
	in >> s;
	int count[26] = {0};
	for(auto ch : s)
	{
		++count[ch - 'A'];
	}

	int digit_count[10] = {0};
	enum
	{
		A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
	};
	if(count[Z] > 0)
	{

		int n = count[Z];
		digit_count[0] += n;
		count[Z] = 0;
		count[E] -= n;
		count[R] -= n;
		count[O] -= n;
	}

	if(count[W] > 0)
	{
		int n = count[W];
		digit_count[2] += n;
		count[T] -= n;
		count[W] = 0;
		count[O] -= n;
	}

	if(count[U] > 0)
	{
		int n = count[U];
		digit_count[4] += n;
		count[F] -= n;
		count[O] -= n;
		count[U] = 0;
		count[R] -= n;
	}

	if(count[X] > 0)
	{
		int n = count[X];
		digit_count[6] += n;
		count[S] -= n;
		count[I] -= n;
		count[X] = 0;
	}

	if(count[G] > 0)
	{
		int n = count[G];
		digit_count[8] += n;
		count[E] -= n;
		count[I] -= n;
		count[G] = 0;
		count[H] -= n;
		count[T] -= n;
	}

	if(count[R] > 0)
	{
		int n = count[R];
		digit_count[3] += n;
		count[T] -= n;
		count[H] -= n;
		count[R] = 0;
		count[E] -= 2 * n;
	}

	if(count[F] > 0)
	{
		int n = count[F];
		digit_count[5] += n;
		count[F] = 0;
		count[I] -= n;
		count[V] -= n;
		count[E] -= n;
	}

	if(count[S] > 0)
	{
		int n = count[S];
		digit_count[7] += n;
		count[S] = 0;
		count[E] -= 2 * n;
		count[V] -= n;
		count[N] -= n;
	}

	if(count[O] > 0)
	{
		int n = count[O];
		digit_count[1] += n;
		count[O] = 0;
		count[N] -= n;
		count[E] -= n;
	}

	if(count[E] > 0)
	{
		int n = count[E];
		digit_count[9] += n;
		count[N] -= n;
		count[I] -= n;
		count[N] -= n;
		count[E] = 0;
	}

	if(count[I] > 0)
	{
		int n = count[I];
		digit_count[6] += n;
		count[S] -= n;
		count[I] = 0;
		count[X] -= n;
	}

	string r;
	for(int i = 0; i < 10; ++i)
	{
		if(digit_count[i] > 0) { r += string(digit_count[i], '0' + i); }
	}
	sort(r.begin(), r.end());

	out << r << endl;
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

