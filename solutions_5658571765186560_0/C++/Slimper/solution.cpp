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
void PrintAnswerToTestCase(size_t caseNumber, AnswerType ans) {
    cerr << "Case #" << caseNumber << endl;
    string winner = "RICHARD";
    if (ans) {
        winner = "GABRIEL";
    }
    cout << "Case #" << caseNumber << ": " << winner << endl;
}

template <class AnswerType>
AnswerType SolveTestCase() {
    int x, r, c;
    cin >> x >> r >> c;
    int area = r * c;
    if ((area % x) != 0) {
        return false;
    }
    if (r > c) {
        swap(r, c);
    }
    if (x == 1) {
        return true;
    }
    if (x == 2) {
        return true;
    }
    if (x == 3) {
        return (c >= 3) && (r >= 2);
    }
    if (x == 4) {
        return (c >= 4 && r >= 3);
    }
    if (x == 5) {
        return (c >= 5 && r >= 4);
    }
    if (x == 6) {
        return (c >= 6 && r >= 4);
    }
    if (x >= 7) {
        return false;
    }
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
		PrintAnswerToTestCase(caseNumber, SolveTestCase<bool>() );

	return 0;
}