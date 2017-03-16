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
typedef long long ll;

//int main12R1PA()
int main()
{
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");
	fout << std::setprecision(20);

	unsigned int numberOfCases;
	fin >> numberOfCases;

	int A,B;
	double P;

	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
	{
		fin >> A >> B;
		
		double goodProb(1.0);
		double result = 2.0 + double(B);

		for (int i=1; i<=A; ++i)
		{
			fin >> P;
			goodProb *= P;

			double thisResult = 1.0 + B - i + (A-i) + (1.0 - goodProb) * (1.0 + B);
			result = min(result, thisResult);
		}

		fout << "Case #" << zz << ": " << result << endl;
	}

	return 0;
}