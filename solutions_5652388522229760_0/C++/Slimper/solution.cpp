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
#include <unordered_map>

using namespace std;

template <class AnswerType>
void PrintAnswerToTestCase(size_t caseNumber, AnswerType ans) {
    cerr << "Case #" << caseNumber << endl;
    if (ans != 0) {
        cout << "Case #" << caseNumber << ": " << ans << endl;
    } else {
        cout << "Case #" << caseNumber << ": " << "INSOMNIA" << endl;
    }
}

int SolveTestCase() {
    int n;
    cin >> n;
    set<int> digits;

    long long cur = 0;
    for (int i = 0; i < 1000000; i++) {
        cur += n;
        long long t = cur;
        while (t > 0) {
            digits.insert(t % 10);
            t /= 10;
        }
        if (digits.size() == 10) {
            return cur;
        }
    }
    return 0;
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