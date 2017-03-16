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

//int main14RQ_B()
int main()
{
	ifstream fin("B-large.in");
	ofstream fout("B-large.out");
	//ifstream fin("test.in");
	//ofstream fout("test.out");
	fout << fixed << setprecision(7);

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		double C, F, X;
		fin >> C >> F >> X;

		double ret = X, t = 0.0, rate = 2.0;;
		while (true)
		{
			double newRet = t + X / rate;
			if (newRet > ret + 0.01)
				break;

			ret = min(ret, newRet);
			t += C / rate;
			rate += F;
		}

		fout << "Case #" << zz << ": " << ret << endl;
	}

	return 0;
}
