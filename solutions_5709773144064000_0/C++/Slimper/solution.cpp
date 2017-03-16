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
    cout.precision(20);
	cout << "Case #" << caseNumber << ": " << ans << endl;
}

template <class AnswerType>
AnswerType SolveTestCase() {
    const int maxFarms = 1 << 25;
    const double r = 2;

    double C;
    double F;
    double X;

    cin >> C >> F >> X;
    double ans = X / r;
    double cur = ans;
    for (int i = 1; i <= maxFarms; i++) {
        cur = cur + C / ((i - 1) * F + r) - X / ((i - 1) * F + r) + X / (i * F + r);
        if (ans > cur) {
            ans = cur;
        }
    }
	return ans;
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
		PrintAnswerToTestCase(caseNumber, SolveTestCase<double>() );

	return 0;
}