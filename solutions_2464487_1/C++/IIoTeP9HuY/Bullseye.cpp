#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <memory.h>
#include <vector>

#define DB(x) cerr << #x << ": " << x << endl;

using namespace std;

const char* inputFile = "A-large.bin";
const char* outputFile = "A-large.out1";

class Solver
{
public:
	long long solveTest(long long r, long long t)
	{
		long long L = 0;
		long long R = 200000000000LL;
		while (L + 1 < R)
		{
			long long m = (L + R) / 2;
			if (2 * r - 1 + 2 * m > t / m) 
			{
				R = m;
			}
			else
			{
				L = m;
			}
		}
		return L;
	}
};

int main()
{
	freopen(inputFile, "r", stdin);
	freopen(outputFile, "w", stdout);
	int T;
	scanf("%d", &T);

	Solver solver;
	for (int testNumber = 1; testNumber <= T; ++testNumber)
	{
		long long t, r;
		cin >> t >> r;
		long long answer = solver.solveTest(t, r);
		printf("Case #%d: %lld\n", testNumber, answer);
	}
	return 0;
}
