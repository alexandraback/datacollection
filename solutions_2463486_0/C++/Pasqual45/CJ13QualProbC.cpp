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
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define mp make_pair

namespace
{
	string intToString(int x) { ostringstream ss; ss<<x; return ss.str(); }
	string longToString(ll x) { ostringstream ss; ss<<x; return ss.str(); }

	bool isPal(ll x)
	{
		static string s;
		s = longToString(x);
		for (size_t i=0; i<s.size()/2; ++i)
			if (s[i] != s[s.size()-1-i])
				return false;

		return true;
	}
}

//int main13QC()
int main()
{
	ifstream fin("C-small-attempt0.in");
	ofstream fout("C-small-attempt0.out");	

	vector<ll> pals;
	for (ll i=1; i <= 10000000; ++i)
	{
		if (isPal(i) && isPal(i*i))
			pals.push_back(i*i);
	}

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
	{
		ll A, B;
		fin >> A >> B;

		int result = 0;
		for (size_t i=0; i<pals.size(); ++i)
			if (pals[i] >= A && pals[i] <= B)
				++result;
		
		fout << "Case #" << zz << ": " << result << endl;
	}

	return 0;
}