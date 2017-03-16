#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef vector<string> VS;
bool can_square_without_carry(const string &number, string &result)
{
	result.assign(2 * number.size() - 1, '0');
	for (int i=0; i<(int)number.size(); i++)
	{
		for (int j=0; j<(int)number.size(); j++)
		{
			int tmp = result[i + j] - '0';
			tmp += (int)(number[i] - '0') * (int)(number[j] - '0');
			if (tmp >= 10)
			{
				return false;
			}
			result[i + j] = tmp + '0';
		}
	}
	return true;
}
void doit(int pos, string &number, VS &squared_palindromes)
{
	string squared_number;
	if (!can_square_without_carry(number, squared_number))
	{
		return;
	}
	if (2 * pos >= (int)number.size())
	{
		squared_palindromes.push_back(squared_number);
	}
	else
	{
		int first = pos == 0;
		for (int d=first; d<10; d++)
		{
			int pos2 = number.size() - 1 - pos;
			number[pos] = number[pos2] = '0' + d;
			doit(pos + 1, number, squared_palindromes);
			number[pos] = number[pos2] = '0';
		}
	}
}
void init(VS &squared_palindromes)
{
	for (int len=1; len<=51; len++)
	{
		string number(len, '0');
		doit(0, number, squared_palindromes);
	}
}
struct cmp_numerical
{
	bool operator()(const string &a, const string &b) const
	{
		if (a.size() != b.size())
		{
			return a.size() < b.size();
		}
		return a < b;
	}
};
int main()
{
	VS squared_palindromes;
	init(squared_palindromes);
	int n_case;
	cin >> n_case;
	for (int tc=0; tc<n_case; tc++)
	{
		string a, b;
		cin >> a >> b;
		VS::iterator lower = lower_bound(squared_palindromes.begin(), squared_palindromes.end(), a, cmp_numerical());
		VS::iterator upper = upper_bound(squared_palindromes.begin(), squared_palindromes.end(), b, cmp_numerical());
		cout << "Case #" << tc + 1 << ": " << upper - lower << endl;
	}
	return 0;
}
