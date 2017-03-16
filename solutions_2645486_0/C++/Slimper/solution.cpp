#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

template<class AnswerType>
void PrintAnswerToTestCase(size_t caseNumber, AnswerType ans)
{
	cerr << "Case #" << caseNumber << endl;
	cout << "Case #" << caseNumber << ": " << ans << endl;
}

long long E, R;
vector<int> v;

long long Solve(int left, int right, int eStart, int eFinish) {
	if (left == right) return 0;
	int maxV = 0;
	int maxPos = 0;
	for (int i = left; i < right; i++) {
		if (v[i] > maxV) {
			maxV = v[i];
			maxPos = i;
		}
	}
	long long maxE = min(E, eStart + (maxPos - left) * R);
	long long spend = min(maxE, maxE - eFinish + (right - maxPos) * R);
	return spend * maxV + Solve(left, maxPos, eStart, maxE) + Solve(maxPos + 1, right, maxE - spend + R, eFinish);

}

template <class AnswerType>
AnswerType SolveTestCase() {
	int n;
	cin >> E >> R >> n;
	R = min(R, E);

	v.clear();
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	return Solve(0, n, E, 0);
	
}

int main()
{
	//freopen("input.txt", "r", stdin);
	freopen("small.in", "r", stdin);
	//freopen("large.in", "r", stdin);

	freopen("output.txt", "w", stdout);

	int numCases;
	cin >> numCases;

	for (int caseNumber = 1; caseNumber <= numCases; caseNumber++)
		PrintAnswerToTestCase(caseNumber, SolveTestCase<int>() );

	return 0;
}