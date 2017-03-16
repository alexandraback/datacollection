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

int ShootsToCheck(int c, int w) {
    return c / w;
}

int ShootsToDestroy(int c, int w) {
    return ShootsToCheck(c, w) + w - ((c % w) == 0);
}


int SolveTestCase() {   
    int rows, columns;
    int w;
    cin >> rows >> columns >> w;
    return (rows - 1) * ShootsToCheck(columns, w) + ShootsToDestroy(columns, w);
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
		PrintAnswerToTestCase(caseNumber, SolveTestCase() );

	return 0;
}