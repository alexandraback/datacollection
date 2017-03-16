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

//int main16RQ_B()
int main()
{
	ifstream fin("B-large.in");
	ofstream fout("B-large.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		string s;
		fin >> s;

		int result = s.back() == '-';
		for (int i = 1; i < s.size(); ++i)
			if (s[i] != s[i - 1])
				++result;

		fout << "Case #" << zz << ": " << result << endl;
	}

	return 0;
}
