#include<fstream>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
#include<numeric>
#include<bitset>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define mp make_pair

namespace
{
	void advance(char& c, bool& neg, char next)
	{
		if (c == '1')
		{
			c = next;
		}
		else
		{
			int diff = (next + 3 - c) % 3;
			if (diff == 1)
			{
				c += (c == 'i' ? 2 : -1);
			}
			else if (diff == 2)
			{
				neg = !neg;
				c += (c == 'k' ? -2 : 1);
			}
			else if (diff == 0)
			{
				neg = !neg;
				c = '1';
			}
		}

	}

	bool can(string s, int n)
	{
		string ss;
		for (int i = 0; i < 160 && i < n; ++i)
			ss += s;

		n = max(n - 160, 0);
		while (n % 4)
		{
			ss += s;
			--n;
		}

		char target = 'i';
		char c = '1';
		bool neg = false;
		for (int i = 0; i < ss.size(); ++i)
		{
			advance(c, neg, ss[i]);

			if (!neg && c == target)
			{
				++target;
				c = '1';
			}
		}

		return target == 'l' && c == '1' && !neg;
	}
}

//int main15RQ_C()
int main()
{
	ifstream fin("C-small-attempt1.in");
	ofstream fout("C-small-attempt1.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		int l, x;
		fin >> l >> x;
		string s;
		fin >> s;

		bool result = can(s, x);
		fout << "Case #" << zz << ": " << (result ? "YES" : "NO") << endl;
	}

	return 0;
}
