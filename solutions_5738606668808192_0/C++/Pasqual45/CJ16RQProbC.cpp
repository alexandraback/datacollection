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
typedef unsigned long long ull;
#define mp make_pair

namespace
{
	ll firstDiv(ll x)
	{
		for (ll i = 2; i*i <= x; ++i)
			if ((x%i) == 0)
				return i;
		return -1;
	}

	ll getNum(ll binary, ll base)
	{
		ll ret = 0, mult = 1;
		while (binary > 0)
		{
			if (binary & 1)
				ret += mult;

			binary /= 2;
			mult *= base;
		}

		return ret;
	}

	ll divs[11];
}

//int main16RQ_C()
int main()
{
	ifstream fin("C-small-attempt0.in");
	ofstream fout("C-small-attempt0.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		int N, J;
		fin >> N >> J;

		fout << "Case #" << zz << ":" << endl;

		for (ull x = (1ULL << (N - 1)) + 1; J > 0 && x < (1ULL << N); x += 2)
		{
			for (int base = 2; base <= 10; ++base)
			{
				ll num = getNum(x, base);
				divs[base] = firstDiv(num);
			}

			if (*min_element(divs + 2, divs + 11) > 0)
			{
				--J;

				string s = bitset<64>(x).to_string();
				fout << s.substr(s.size() - N);
				
				for (int base = 2; base <= 10; ++base)
				{
					fout << " " << divs[base];
				}

				fout << endl;
			}
		}
	}

	return 0;
}
