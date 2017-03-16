#include <functional> 
#include <iostream> 
#include <algorithm> 
#include <sstream> 
#include <string> 
#include <utility> 
#include <vector> 
#include <cmath> 
#include <queue> 
#include <map> 
#include <set>

using namespace std;

#define VT vector 
typedef VT<int> VI; 
typedef VT<VI> VVI; 
typedef VT<string> VS; 
typedef VT<double> VD; 
#define REP(i,n) for(int _n=n, i=0;i<_n;++i) 
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i) 
#define ALL(c) c.begin(),c.end() 
#define PB push_back 
#define MP make_pair 
#define FS first 
#define SC second 
#define SZ size()

enum letter {one, i, j, k };

struct quarter
{
	quarter(char ch)
	{
		negative = false;
		if (ch == 'i')
			letter = letter::i;
		else if (ch == 'j')
			letter = letter::j;
		else if (ch == 'k')
			letter = letter::k;
	}

	quarter()
	{
		negative = false;
		letter = letter::one;
	}

	letter letter;
	bool negative;
};

bool operator==(const quarter& a, const quarter& b)
{
	return a.letter == b.letter && a.negative == b.negative;
}


quarter multiply(quarter a, quarter b)
{
	quarter c;
	c.negative = a.negative ^ b.negative;

	if (a.letter == letter::one)
		c.letter = b.letter;

	if (a.letter == letter::i)
	{
		c.letter = letter::i;

		if (b.letter == letter::i)
		{
			c.letter = letter::one;
			c.negative = !c.negative;
		}
		else if (b.letter == letter::j)
		{
			c.letter = letter::k;
		}
		else if (b.letter == letter::k)
		{
			c.letter = letter::j;
			c.negative = !c.negative;
		}
	}
	else if (a.letter == letter::j)
	{
		c.letter = letter::j;

		if (b.letter == letter::i)
		{
			c.letter = letter::k;
			c.negative = !c.negative;
		}
		else if (b.letter == letter::j)
		{
			c.letter = letter::one;
			c.negative = !c.negative;
		}
		else if (b.letter == letter::k)
		{
			c.letter = letter::i;
		}
	}
	else if (a.letter == letter::k)
	{
		c.letter = letter::k;

		if (b.letter == letter::i)
		{
			c.letter = letter::j;
		}
		else if (b.letter == letter::j)
		{
			c.letter = letter::i;
			c.negative = !c.negative;
		}
		else if (b.letter == letter::k)
		{
			c.letter = letter::one;
			c.negative = !c.negative;
		}
	}

	return c;
}

bool solve_correct(long long l, long long x, string expr)
{

	string expr_;

	for (int i = 0; i < x; ++i)
	{
		expr_ += expr;
	}


	quarter q;


	for (int i = 0; i < expr_.size(); ++i)
	{
		q = multiply(q, quarter(expr_[i]));
	}

	//if (x % 4 == 0)
	//	return false;

	//for (int i = 0; i < x % 4 - 1; ++i)
	//{
	//	q = multiply(q, q);
	//}

	if (q.letter != letter::one || !q.negative)
		return false;

	long long min_i = -1;

	q = quarter();
	for (int i = 0; i < expr_.size(); ++i)
	{
		q = multiply(q, quarter(expr_[i]));

		if (q == quarter('i'))
		{
			min_i = i;
			break;
		}
	}

	long long max_k = -1;

	q = quarter();
	for (long long i = expr_.size() - 1, position = l*x - 1; i >= 0; --i, --position)
	{
		q = multiply(quarter(expr_[i]), q);

		if (q == quarter('k'))
		{
			max_k = position;
			break;
		}
	}

	if (min_i == -1LL || max_k == -1LL)
		return false;

	if (max_k > min_i + 1)
		return true;

	return false;
}

bool solve(long long l, long long x, string expr)
{
	quarter q;

	for (int i = 0; i < expr.size(); ++i)
	{
		q = multiply(q, quarter(expr[i]));
	}

	if (x % 4 == 0)
		return false;

	quarter t;
	for (int i = 0; i < x % 4; ++i)
	{
		t = multiply(t, q);
	}

	if (t.letter != letter::one || !t.negative)
		return false;


	string prefix;
	string suffix;

	for (int i = 0; i < min(4LL, x); ++i)
	{
		prefix += expr;
		suffix += expr;
	}

	long long min_i = -1;

	q = quarter();
	for (int i = 0; i < prefix.size(); ++i)
	{
		q = multiply(q, quarter(prefix[i]));

		if (q == quarter('i'))
		{
			min_i = i;
			break;
		}
	}

	long long max_k = -1;

	q = quarter();
	for (long long i = suffix.size()-1, position = l*x-1; i >= 0; --i, --position)
	{
		q = multiply(quarter(suffix[i]), q);

		if (q == quarter('k'))
		{
			max_k = position;
			break;
		}
	}

	if (min_i == -1LL || max_k == -1LL)
		return false;

	if (max_k > min_i + 1)
		return true;

	return false;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{

		long long l, x;
		cin >> l >> x;
		string expr;
		cin >> expr;


		bool result = solve(l, x, expr);

		cout << "Case #" << t << ": " << (result ? "YES" : "NO") << endl;
		cerr << "Case #" << t << ": " << (result ? "YES" : "NO") << endl;
	}
} 
