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

double pi = 3.14159265358979323846264338327;

template<class AnswerType>
void PrintAnswerToTestCase(size_t caseNumber, AnswerType ans)
{
	cerr << "Case #" << caseNumber << endl;
	cout << "Case #" << caseNumber << ": " << ans << endl;
}

template <class AnswerType>
AnswerType SolveTestCase() {
	long long r;
	long long t;
	cin >> r >> t;
	long long left = 0;
	long long right = sqrt((2 * (double)r - 1) * (2 * (double)r - 1)  + 8 * t) / 2  + 1;
	while (left < right) {
		long long x = (left + right + 1) >> 1;
		if ((2 * r + 2 * x - 1) <= t / x) {
			left = x;
		} else {
			right = x - 1;
		}
	}
	return left;
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
		PrintAnswerToTestCase(caseNumber, SolveTestCase<long long>() );

	return 0;
}