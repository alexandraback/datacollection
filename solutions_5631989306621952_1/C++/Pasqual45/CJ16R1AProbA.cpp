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

//int main16R1A_A()
int main()
{
	ifstream fin("A-large.in");
	ofstream fout("A-large.out");
	//ifstream fin("test.in");
	//ofstream fout("test.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		string s;
		fin >> s;

		string start, end;
		for (char c = 'Z'; c >= 'A'; --c)
		{
			int idx = 5000;
			for (int i = 0; i<s.size(); ++i)
			{
				if (s[i] == c)
				{
					if (idx == 5000)
						idx = i;

					start += c;
				}
			}

			for (int i = s.size() - 1; i > idx; --i)
			{
				if (s[i] != c)
					end = string(1, s[i]) + end;
			}

			s = s.substr(0, idx);
		}

		string result = start + end;
		fout << "Case #" << zz << ": " << result << endl;
	}

	return 0;
}
