#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <fstream>


using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

typedef pair<int, int> PII;
typedef long long LL;
typedef vector<vector<int> > VII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef vector<vector<double> > VVD;


void runCase(int caseNum) {
	int A, B;

	cin >> A >> B;
	double correct = 1.0;

	double best = B + 2;

	for (int i = 1; i <= A; ++i) {
		double p;
		cin >> p;
		correct *= p;
		double expected = correct * (A + B - 2 * i + 1) + (1.0 - correct) * (A + 2 * B - 2 * i + 2);
		best = min(best, expected);
	}
	
	cout.precision(10);
	cout << "Case #" << caseNum << ": " << best << endl;;
}

int main(int argc, char* argv[])
{
#ifdef __TSUN
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
		runCase(i + 1);

//	runCase(0);

#ifdef __TSUN
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}

