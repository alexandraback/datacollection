#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stack>
#include <cassert>
#include <algorithm>
#include <memory.h>
#include <vector>

#define DB(x) cerr << #x << ": " << x << endl;

using namespace std;

const char* inputFile = "B-large.bin";
const char* outputFile = "B-large.out";

class Solver
{
public:
	long long solveTest()
	{
		int E, R, N;
		cin >> E >> R >> N;
		vector<int> v(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> v[i];
		}
		stack< pair<int, int> > S;
		vector<int> nextBigger(N);
		for (int i = 0; i < N; ++i)
		{
			while (!S.empty() && S.top().first < v[i])
			{
				nextBigger[S.top().second] = i;
				S.pop();
			}
			S.push(make_pair(v[i], i));
		}
		while (!S.empty())
		{
			nextBigger[S.top().second] = N;
			S.pop();
		}

		int currentEnergy = E;
		long long profit = 0;
		
		for (int i = 0; i < N; ++i)
		{
			int next = nextBigger[i];
			int dist = next - i;
			int get = dist * R;
			if (next == N)
			{
				profit += currentEnergy * 1LL * v[i];
				currentEnergy = 0;
			}
			else
			if (currentEnergy + get > E)
			{
				int canHave = max(E - get, 0);
				int canUse = currentEnergy - canHave;
				profit += canUse * 1LL * v[i];
				currentEnergy -= canUse;
			}
			currentEnergy = min(currentEnergy + R, E);
		}
		return profit;
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
		long long answer = solver.solveTest();
		printf("Case #%d: %lld\n", testNumber, answer);
	}
	return 0;
}
