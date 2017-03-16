#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef long long LL;

struct solution
{
	LL p;
	LL q;
	LL diff;
	
	solution() {}
	solution(LL p_, LL q_, LL diff_) { p = p_, q = q_, diff = diff_; }
	
	bool operator<(const solution& rhs) const
	{
		if (diff != rhs.diff)
			return diff < rhs.diff;
		if (p != rhs.p)
			return p < rhs.p;
		return q < rhs.q;
	}
};

inline LL extend(LL n, char d)
{
	return 10 * n + d - '0';
}

inline int update_comparison(int comparison, char a, char b)
{
	if (comparison != 0) return comparison;
	if (a == b) return 0;
	return (a < b) ? -1 : 1;
}

inline char inc_digit(char d)
{
	return ((d - '0' + 1) % 10) + '0';
}

inline char dec_digit(char d)
{
	return ((d - '0' + 9) % 10) + '0';
}

solution min(const solution& a, const solution& b, const solution& c)
{
	return min(a, min(b, c));
}

struct state
{
	LL p;
	LL q;
	int index;
	int comparison;
	const string& a;
	const string& b;
	
	state(const string& a_, const string& b_) : a(a_), b(b_)
	{
		p = 0;
		q = 0;
		index = 0;
		comparison = 0;
	}
	
	state(const state& original, char x, char y) : a(original.a), b(original.b)
	{
		index = original.index + 1;
		comparison = update_comparison(original.comparison, x, y);
		p = extend(original.p, x);
		q = extend(original.q, y);
	}
	
	state advance(char x, char y) const
	{
		return state(*this, x, y);
	}
	
	bool a_quest() const { return a[index] == '?'; }
	bool b_quest() const { return b[index] == '?'; }
	char a_curr() const { return a[index]; }
	char b_curr() const { return b[index]; }
};

solution solve(const state& s)
{
	if (s.index < s.a.size())
	{
		if (!s.a_quest() && !s.b_quest())
		{
			return solve(s.advance(s.a_curr(), s.b_curr()));
		}
		if (s.comparison == 0)
		{
			if (s.a_quest() && s.b_quest())
			{
				return min(
					solve(s.advance('0', '0')),
					solve(s.advance('1', '0')),
					solve(s.advance('0', '1')));
			}
			else if (s.a_quest())
			{
				return min(
					solve(s.advance(dec_digit(s.b_curr()), s.b_curr())),
					solve(s.advance(s.b_curr(), s.b_curr())),
					solve(s.advance(inc_digit(s.b_curr()), s.b_curr())));
			}
			else
			{
				return min(
					solve(s.advance(s.a_curr(), dec_digit(s.a_curr()))),
					solve(s.advance(s.a_curr(), s.a_curr())),
					solve(s.advance(s.a_curr(), inc_digit(s.a_curr()))));
			}
		}
		else if (s.comparison < 0)
		{
			if (s.a_quest() && s.b_quest())
			{
				return solve(s.advance('9', '0'));
			}
			else if (s.a_quest())
			{
				return solve(s.advance('9', s.b_curr()));
			}
			else
			{
				return solve(s.advance(s.a_curr(), '0'));
			}
		}
		else
		{
			if (s.a_quest() && s.b_quest())
			{
				return solve(s.advance('0', '9'));
			}
			else if (s.a_quest())
			{
				return solve(s.advance('0', s.b_curr()));
			}
			else
			{
				return solve(s.advance(s.a_curr(), '9'));
			}
		}
	}
	else
	{
		return solution(s.p, s.q, llabs(s.p - s.q));
	}
}

int main()
{
	int cases;
	cin >> cases;
	for (int c = 1; c <= cases; c++)
	{
		cout << "Case #" << c << ": ";
		string a;
		string b;
		cin >> a >> b;
		solution sol = solve(state(a, b));
		string ps = to_string(sol.p);
		string qs = to_string(sol.q);
		ps.insert(ps.begin(), a.size() - ps.size(), '0');
		qs.insert(qs.begin(), a.size() - qs.size(), '0');
		cout << ps << " " << qs << endl;
	}
}
