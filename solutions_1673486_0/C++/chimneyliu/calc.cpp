#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>

using namespace std;
typedef long long int64;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (b) - 1; i >= a; --i)
#define SIZE(a) ((a).size())



int main()
{
	const char* inFile = "in.txt";
	const char* outFile = "out.txt";
	freopen(inFile, "r", stdin);
	freopen(outFile, "w", stdout);

	int T;
	cin >> T;
	for (int t=1; t<=T; t++)
	{
		int A, B;
		cin >> A >> B;
		double p[100001], q[100001];
		for (int i=1; i<=A; i++)
			cin >> p[i];
		q[1] = 1 - p[1];
		for (int i=2; i<=A; i++)
			q[i] = p[i] * q[i-1] + (1 - p[i]);
		
		double r1 = (1 - q[A]) * (B - A + 1) + q[A] * (B - A + 1 + B + 1);
		double r2 = 1 + B + 1;
		double minRes = min(r1, r2);
		for (int i=1; i<=A; i++)
		{
			double r = (1 - q[A-i]) * (i * 2 + B - A + 1) + q[A-i] * (i * 2 + B - A + 1 + B + 1);
			minRes = min(r, minRes);

		}

		printf("Case #%d: %f\n", t, minRes);
	}
	
	return 0;
}