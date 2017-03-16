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
typedef unsigned long long ull;
#define mp make_pair

//int main13R1APA()
int main()
{
	ifstream fin("A-large.in");
	ofstream fout("A-large.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	ull r,t;
	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
	{
		fin >> r >> t;

		ull smallest = 2*r + 1;
		ull lo= 0, hi = (t/smallest) + 2;
		while (hi-lo > 1)
		{
			ull mid = (lo + hi) / 2;

			ull firstTerm = 2 * mid * r;
			if ((firstTerm / (2*mid)) != r || firstTerm > t)
			{
				hi = mid; continue;
			}

			ull middleTerm = 2 * mid * (mid-1);
			if ((middleTerm / (2*mid)) != (mid-1) || middleTerm > t)
			{
				hi = mid; continue;
			}

			ull req = firstTerm + middleTerm + mid;

			if (req > t) hi = mid;
			else lo = mid;
		}

		fout << "Case #" << zz << ": " << lo << endl;
	}

	return 0;
}