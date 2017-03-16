/*
* C++11 code template for contests.
* @author: Andrey Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

/*______ DEFINES _______*/

#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
//#define ANDREIKKAA_ALLOCATOR
//#define ANDREIKKAA_UNSAFE_VECTOR

#ifdef ANDREIKKAA_UNSAFE_VECTOR
#define vec vector
#endif // ANDREIKKAA_UNSAFE_VECTOR

typedef long long ll;
typedef long double ld;

const int MEMORY_LIMIT_MB = 250;
const int TIME_LIMIT_S = 1;

const char input_filename[] =
#ifdef ANDREIKKAA
"input.txt"
#else
""
#endif
;
const char output_filename[] =
#ifdef ANDREIKKAA
"output.txt"
#else
""
#endif
;

/* ______ INCLUDES ______ */

#include <cassert>
#include <cctype>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdint>
#include <ctgmath>

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#include <array>
#include <forward_list>
#include <initializer_list>
#include <regex>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*_______ TYPES ________*/

template<typename T, typename U>
ostream &operator<<(ostream &out, const pair<T, U> &p)
{
	out << p.first << ' ' << p.second;
	return out;
}

template<typename T, typename U>
istream &operator>>(istream &in, pair<T, U> &p)
{
	in >> p.first >> p.second;
	return in;
}

#ifndef ANDREIKKAA_UNSAFE_VECTOR
template<typename T>
class vec : public vector<T>
{
public:
	using vector<T>::vector;
	inline const T operator[](size_t x) const
	{
		return this->at(x);
	}
	inline T& operator[](size_t x)
	{
		return this->at(x);
	}
};

template<>
class vec<bool> : public vector<bool>
{
	using vector<bool>::vector;
public:
	inline const_reference operator[](size_t x) const
	{
		return this->at(x);
	}
	inline reference operator[](size_t x)
	{
		return this->at(x);
	}
};

template<typename T>
inline ostream &operator<<(ostream &out, const vec<T> &v)
{
	if (v.empty())
		return out;
	out << v.front();
	for (auto it = ++v.begin(); it != v.end(); ++it)
		out << ' ' << *it;
	return out;
}

template<typename T>
inline istream &operator>>(istream &in, vec<T> &v)
{
	for (auto &i : v)
		in >> i;
	return in;
}
#endif // !ANDREIKKAA_UNSAFE_VECTOR

template<typename T>
inline ostream &operator<<(ostream &out, const vector<T> &v)
{
	if (v.empty())
		return out;
	out << v.front();
	for (auto it = ++v.begin(); it != v.end(); ++it)
		out << ' ' << *it;
	return out;
}

template<typename T>
inline istream &operator>>(istream &in, vector<T> &v)
{
	for (auto &i : v)
		in >> i;
	return in;
}

/* _____ ALLOCATION _____ */

#ifdef ANDREIKKAA_ALLOCATOR
char alloc_memory[MEMORY_LIMIT_MB * 1000 * 1000];
size_t alloc_pointer = 0;
inline void* operator new(size_t x)
{
	alloc_pointer += x;
return alloc_memory + alloc_pointer - x;
}
inline void operator delete(void* x)
{

}
#endif

/* _______ INPUT _________*/

class Reader
{
public:
	inline Reader(const string &filename)
	{
		cin.tie(nullptr);//, ios_base::sync_with_stdio(false);
		if (not filename.empty())
			assert(freopen(filename.c_str(), "r", stdin) != nullptr);
	}

	template<typename T>
	inline void operator()(T &x)
	{
		cin >> x;
	}

	template<typename T, typename... Args>
	inline void operator()(T &x, Args &... args)
	{
		operator()(x), operator()(args...);
	}
};
Reader read(input_filename);

/* _______ OUTPUT ________*/

class Printer
{
public:
	inline Printer(const string &filename)
	{
		//cout.precision(20);
		//cout << fixed;
		if (not filename.empty())
			assert(freopen(filename.c_str(), "w", stdout) != nullptr);
	}

	template<typename T>
	inline void out(const T x)
	{
		cout << x;
	}

	template<typename T, typename... Args>
	inline void out(const T x, const Args... args)
	{
		out(x), out(args...);
	}

	inline void operator()()
	{
		out('\n');
	}

	template<typename T>
	inline void operator()(const T x)
	{
		out(x), out('\n');
	}

	template<typename T, typename... Args>
	inline void operator()(const T x, const Args... args)
	{
		out(x), out(' '), operator()(args...);
	};
};
Printer print(output_filename);

/* ________ CODE ________ */

class Solution
{
public:

	vec<vec<int>> g;

	int dfs(int v, int w)
	{
		if (v == w)
			return -228228;

		int ans = 0;
		for (int i : g[v])
		{
			ans = max(ans, dfs(i, w));
		}
		return ans + 1;
	}

	int f_p(int n, vec<int> v)
	{
		g.clear();
		g.resize(n);
		for (int i = 0; i < n; ++i)
			g[v[i]].push_back(i);

		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			if (v[v[i]] == i)
			{
				ans += dfs(i, v[i]);
			}
		}
		return ans;
	}

	int f_c(int n, vec<int> v)
	{
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			vec<bool> used(n);
			if (true)
			{
				vec<int> st;
				int ptr = i;
				while (not used[ptr])
				{
					st.push_back(ptr);
					used[ptr] = true;
					ptr = v[ptr];
				}
				if (st.front() == ptr)
				{
					ans = max(ans, (int)st.size());
				}
			}
		}
		return ans;
	}

	int f(int n, vec<int> v)
	{
		return max(f_p(n, v), f_c(n, v));
	}

	inline void solve()
	{
		int t;
		read(t);

		for (int i = 0; i < t; ++i)
		{
			int n;
			read(n);
			vec<int> v(n);
			for (int j = 0; j < n; ++j)
			{
				read(v[j]);
				--v[j];
				assert(v[j] != j);
			}
			print.out("Case #", i + 1, ": ", f(n, v));
			print();
		}
	}

	Solution()
	{
#ifdef ANDREIKKAA
		start = clock();
#endif // ANDREIKKAA
	}

	~Solution()
	{
#ifdef ANDREIKKAA
		//print("Time:", (clock() - start) / (ld)CLOCKS_PER_SEC);
#endif // ANDREIKKAA
	}
private:
#ifdef ANDREIKKAA
	time_t start;
#endif // ANDREIKKAA
};

int main()
{
	auto s = new Solution;
	s->solve();
	delete s;
#ifdef ANDREIKKAA 
#ifdef _WIN32
	//while (true);
#endif // _WIN32
#endif // ANDREIKKAA
}
