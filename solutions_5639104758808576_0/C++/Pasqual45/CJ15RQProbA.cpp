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

//int main15RQ_A()
int main()
{
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		int m;
		string s;
		fin >> m >> s;

		int result = 0, standing = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (standing < i)
				++standing, ++result;

			standing += s[i] - '0';
		}

		fout << "Case #" << zz << ": " << result << endl;
	}

	return 0;
}
