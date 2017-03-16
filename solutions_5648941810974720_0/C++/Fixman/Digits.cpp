#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

#define forsn(i, s, n) for (int i = s; i < n; i++)

typedef multiset <char> Chars;

vector <string> numbers = {
	"ZERO",
	"ONE",
	"TWO",
	"THREE",
	"FOUR",
	"FIVE",
	"SIX",
	"SEVEN",
	"EIGHT",
	"NINE"
};

bool properMinus(Chars &F, string s)
{
	for (char c : s)
	{
		auto h = F.find(c);
		if (h == F.end())
			return false;

		F.erase(h);
	}

	return true;
}

string solve(Chars F, int n = 0)
{
	if (n == 10)
	{
		if (F.empty())
			return "";
		else
			return "X";
	}

	Chars T = F;
	if (properMinus(T, numbers[n]))
	{
		string r = solve(T, n);
		if (r != "X")
			return to_string(n) + r;
	}

	return solve(F, n + 1);
}

int main()
{
	int t;
	cin >> t;

	forsn(z, 1, t + 1)
	{
		string s;
		cin >> s;

		Chars F(s.begin(), s.end());

		printf("Case #%d: %s\n", z, solve(F).c_str());
	}

	return 0;
}
