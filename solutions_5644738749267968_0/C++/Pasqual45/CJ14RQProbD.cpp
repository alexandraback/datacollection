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
	double a[1001], b[1001];
	int n;

	int calcBad()
	{
		int ret = 0, j = 0;
		for (int i = 0; i < n; ++i)
		{
			while (j < n && b[j] < a[i])
				++j;

			if (j == n)
			{
				++ret;
			}
			else
			{
				++j;
			}
		}

		return ret;
	}

	int calcGood()
	{
		int ret = 0;
		int i = 0;
		for (int j = 0; j < n; ++j)
		{
			while (i < n && a[i] < b[j])
				++i;

			if (i < n)
				++ret, ++i;
		}

		return ret;
	}
}

//int main14RQ_D()
int main()
{
	ifstream fin("D-small-attempt0.in");
	ofstream fout("D-small-attempt0.out");
	//ifstream fin("test.in");
	//ofstream fout("test.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		fin >> n;
		for (int i = 0; i < n; ++i)
			fin >> a[i];
		for (int i = 0; i < n; ++i)
			fin >> b[i];
		
		sort(a, a + n);
		sort(b, b + n);
		int x = calcBad(), y = calcGood();

		fout << "Case #" << zz << ": " << y << " " << x << endl;
	}

	return 0;
}
