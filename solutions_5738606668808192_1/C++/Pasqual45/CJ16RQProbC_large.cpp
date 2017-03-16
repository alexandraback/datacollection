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
	bool hasFactor(ll x, ll fact, ll base)
	{
		ll multModFact = 1, sumMod = 0;
		while (x)
		{
			if (x & 1)
			{
				sumMod += multModFact;
				sumMod %= fact;
			}

			x /= 2;
			multModFact *= base;
			multModFact %= fact;
		}

		return sumMod == 0;
	}

	ll divs[11];
}

//int main16RQ_C()
int main()
{
	ifstream fin("C-large.in");
	ofstream fout("C-large.out");

	vector<int> possibilities[11];
	possibilities[2] = vector<int>{3, 5};
	possibilities[3] = vector<int>{2};
	possibilities[4] = vector<int>{3, 5};
	possibilities[5] = vector<int>{2};
	possibilities[6] = vector<int>{7};
	possibilities[7] = vector<int>{2};
	possibilities[8] = vector<int>{3};
	possibilities[9] = vector<int>{2};
	possibilities[10] = vector<int>{3,5,7,11};

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
				divs[base] = -1;

				const vector<int>& v = possibilities[base];
				for (int i = 0; i < v.size() && divs[base] < 0; ++i)
				{
					if (hasFactor(x, v[i], base))
						divs[base] = v[i];
				}

				if (divs[base] < 0)
					break;
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
