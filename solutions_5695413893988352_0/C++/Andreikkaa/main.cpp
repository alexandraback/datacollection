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
#include <ciso646>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ctgmath>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <complex>
#include <functional>
#include <iterator>
#include <limits>
#include <locale>
#include <numeric>
#include <regex>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

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

inline void operator delete(void*)
{

}
#endif

/* _______ INPUT _________*/

class Reader
{
public:
	inline Reader(const string &filename)
	{
		cin.tie(nullptr);
		ios_base::sync_with_stdio(false);
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
Reader rd(input_filename);

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
Printer pr(output_filename);

/* ________ CODE ________ */

class Solution
{
public:

	pair<ll, pair<string, string>> INF = { LLONG_MAX, {":(", ":("} };

	pair<ll, pair<string, string>> get_dif(string s, string t)
	{
		ll x = abs(atoi(s.c_str()) - atoi(t.c_str()));
		return{ x, {s, t} };
	}

	pair<ll, pair<string, string>> g(string s, string t, int pos)
	{
		if (s[pos] == '?')
		{
			if (t[pos] == '?')
			{
				s[pos] = '1';
				t[pos] = '0';
			}
			else
			{
				if (t[pos] == '9')
				{
					return INF;
				}
				else
				{
					s[pos] = t[pos] + 1;
				}
			}
		}
		else
		{
			if (t[pos] == '?')
			{
				if (s[pos] == '0')
				{
					return INF;
				}
				else
				{
					t[pos] = s[pos] - 1;
				}
			}
			else
			{
				if (s[pos] <= t[pos])
				{
					return INF;
				}
			}
		}

		for (; pos < s.size(); ++pos)
		{
			if (s[pos] == '?')
			{
				s[pos] = '0';
			}
			if (t[pos] == '?')
			{
				t[pos] = '9';
			}
		}
		return get_dif(s, t);
	}

	pair<string, string> f(string s, string t)
	{
		pair<ll, pair<string, string>> ans;
		ans.first = LLONG_MAX;
		int i;
		for (i = 0; i < s.size(); ++i)
		{
			if (not equal(s.begin(), s.begin() + i, t.begin()))
			{
				break;
			}
			auto cur = g(s, t, i);
			ans = min(ans, cur);
			cur = g(t, s, i);
			swap(cur.second.first, cur.second.second);
			ans = min(ans, cur);
			if (s[i] == '?')
			{
				if (t[i] == '?')
				{
					s[i] = t[i] = '0';
				}
				else
				{
					s[i] = t[i];
				}
			}
			else
			{
				if (t[i] == '?')
				{
					t[i] = s[i];
				}
				else
				{
					if (s[i] != t[i])
					{
						break;
					}
				}
			}
		}
		if(i == s.size())
			ans = min(ans, get_dif(s, t));
		return ans.second;
	}

	vec<string> val(string s)
	{
		vec<string> vals;
		for (int i = 0; i < pow(10, s.size()); ++i)
		{
			string tst = to_string(i);
			tst = string(s.size() - tst.size(), '0') + tst;
			bool st = true;
			for (int j = 0; j < s.size(); ++j)
			{
				if (s[j] == '?' or s[j] == tst[j])
				{

				}
				else
				{
					st = false;
					break;
				}
			}
			if (st)
			{
				vals.push_back(tst);
			}
		}
		return vals;
	}

	pair<string, string> ff(string s, string t)
	{
		auto vs = val(s);
		auto vt = val(t);
		pair<ll, pair<string, string>> ans = INF;

		for (auto i : vs)
		{
			for (auto j : vt)
			{
				ans = min(ans, { abs(atoi(i.c_str()) - atoi(j.c_str())), {i, j} });
			}
		}

		return ans.second;
	}

	inline void solve()
	{
		int n;
		rd(n);

		for (int i = 0; i < n; ++i)
		{
			string s, t;
			rd(s, t);
			pr.out("Case #", i + 1, ": ", f(s, t));
			pr();
			//pr.out("Corr #", i + 1, ": ", ff(s, t));
			//pr();
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
		cerr << "Time: " << (clock() - start) / (ld)CLOCKS_PER_SEC << endl;
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
	while (true);
#endif // _WIN32
#endif // ANDREIKKAA
}