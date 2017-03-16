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
void PrintAnswerToTestCase(size_t caseNumber, AnswerType ans)
{
	cerr << "Case #" << caseNumber << endl;
	cout << "Case #" << caseNumber << ": " << ans << endl;
}

bool Match(int score, string pattern) {
    for (int i = pattern.length() - 1; i > -1; i--) {
        if (pattern[i] != '?' && ((pattern[i] - '0') != (score % 10))) {
            return false;
        }
        score = score / 10;
    }
    return true;
}

string SolveTestCase() {
    const long long INF = 1LL << 62;
    string firstString, secondString;
    cin >> firstString >> secondString;

    long long minDiff = INF;
    long long minFirstScore = INF;
    long long minSecondScore = INF;
    long long bestFirst = INF;
    long long bestSecond = INF;

    int maxVal = 1;
    for (int i = 0; i < firstString.length(); i++) {
        maxVal *= 10;
    }
    for (int first = 0; first < maxVal; first++) {
        for (int second = 0; second < maxVal; second++) {
            if (Match(first, firstString) && Match(second, secondString)) {
                if ((abs(first - second) < minDiff) || 
                    (abs(first - second) == minDiff && first < minFirstScore) ||
                    (abs(first - second) == minDiff && first == minFirstScore && second < minSecondScore))
                {
                    minDiff = abs(first - second);
                    minFirstScore = first;
                    minSecondScore = second;
                    bestFirst = first;
                    bestSecond = second;
                }
            }
        }
    }
    ostringstream oss;
    oss.width(firstString.length());
    oss.fill('0');
    oss << bestFirst;
    oss << " ";
    oss.width(secondString.length());
    oss << bestSecond;
    return oss.str();
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