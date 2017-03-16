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
	bool seen[10];
	int numSeen;

	void go(ll x)
	{
		if (!seen[x])
			++numSeen;
		seen[x] = true;
	}

	void see(ll x)
	{
		while (x)
		{
			go(x % 10);
			x /= 10;
		}
	}
}

//int main16RQ_A()
int main()
{
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		ll x;
		fin >> x;

		numSeen = 0;
		fill(seen, seen + 10, false);
		
		ll mult = 1;
		see(x);
		
		while (mult < 1000000 && numSeen < 10)
		{
			++mult;
			see(x*mult);
		}

		if (numSeen < 10)
		{
			fout << "Case #" << zz << ": " << "INSOMNIA" << endl;
			cout << "Failed for " << x << endl;
		}
		else
		{
			fout << "Case #" << zz << ": " << x*mult << endl;
		}
	}

	return 0;
}
