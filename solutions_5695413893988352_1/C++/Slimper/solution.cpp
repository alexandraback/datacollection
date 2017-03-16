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

void SolveSimple(const string& firstString, const string& secondString, long long& bestFirst, long long & bestSecond) {
    const long long INF = 1LL << 62;
    long long minDiff = INF;
    long long minFirstScore = INF;
    long long minSecondScore = INF;

    int maxVal = 1;
    for (int i = 0; i < firstString.length(); i++) {
        maxVal *= 10;
    }
    for (int first = 0; first < maxVal; first++) {
        for (int second = 0; second < maxVal; second++) {
            if (Match(first, firstString) && Match(second, secondString)) {
                if ((abs(first - second) < minDiff) ||
                    (abs(first - second) == minDiff && first < minFirstScore) ||
                    (abs(first - second) == minDiff && first == minFirstScore && second < minSecondScore)) {
                    minDiff = abs(first - second);
                    minFirstScore = first;
                    minSecondScore = second;
                    bestFirst = first;
                    bestSecond = second;
                }
            }
        }
    }
}

void Rec(int n, const string& first, const string& second, long long f, long long s, long long& bestFirst, long long& bestSecond) {
    if (n < first.length()) {
        int fd = (first[n] - '0');
        int sd = (second[n] - '0');
        f = 10 * f;
        s = 10 * s;
        if (first[n] != '?' && second[n] != '?') {
            Rec(n + 1, first, second, f + fd, s + sd, bestFirst, bestSecond);
        } else if (first[n] == second[n]) {
            if (f == s) {
                Rec(n + 1, first, second, f, s, bestFirst, bestSecond);
                Rec(n + 1, first, second, f, s + 1, bestFirst, bestSecond);
                Rec(n + 1, first, second, f + 1, s, bestFirst, bestSecond);
            } if (f < s) {
                Rec(n + 1, first, second, f + 9, s, bestFirst, bestSecond);
            } else {
                Rec(n + 1, first, second, f, s + 9, bestFirst, bestSecond);
            }
        } else if (first[n] == '?') {
            if (f == s) {
                Rec(n + 1, first, second, f + sd, s + sd, bestFirst, bestSecond);
                if (sd != 0) {
                    Rec(n + 1, first, second, f + sd - 1, s + sd, bestFirst, bestSecond);
                }

                if (sd != 9) {
                    Rec(n + 1, first, second, f + sd + 1, s + sd, bestFirst, bestSecond);
                }
            }
            if (f < s) {
                Rec(n + 1, first, second, f + 9, s + sd, bestFirst, bestSecond);
            }
            if (f > s) {
                Rec(n + 1, first, second, f + 0, s + sd, bestFirst, bestSecond);
            }

        } else {
            if (f == s) {
                Rec(n + 1, first, second, f + fd, s + fd, bestFirst, bestSecond);
                if (fd != 0) {
                    Rec(n + 1, first, second, f + fd, s + fd - 1, bestFirst, bestSecond);
                }

                if (fd != 9) {
                    Rec(n + 1, first, second, f + fd, s + fd + 1, bestFirst, bestSecond);
                }
            }
            if (s < f) {
                Rec(n + 1, first, second, f + fd, s + 9, bestFirst, bestSecond);
            }
            if (s > f) {
                Rec(n + 1, first, second, f + fd, s + 0, bestFirst, bestSecond);
            }
        }
    } else {
        if ((abs(f - s) < abs(bestFirst - bestSecond)) ||
            (abs(f - s) == abs(bestFirst - bestSecond) && f < bestFirst) ||
            (abs(f - s) == abs(bestFirst - bestSecond) && f == bestFirst && s < bestSecond))
        {
                bestFirst = f;
                bestSecond = s;
        }
    }
}

string SolveTestCase() {

    string firstString, secondString;
    cin >> firstString >> secondString;

    long long bestFirst = -1;
    long long bestSecond = 1LL << 62;

    int n = 0;
    
    Rec(0, firstString, secondString, 0, 0, bestFirst, bestSecond);

    if (firstString.length() <= 4) {
        long long bestFirstSimple, bestSecondSimple;
        SolveSimple(firstString, secondString, bestFirstSimple, bestSecondSimple);
        if (bestFirst != bestFirstSimple || bestSecond != bestSecondSimple) {
            cerr << "ERROR!!!" << endl;
            cerr << firstString << " " << secondString << endl;
            cerr << bestFirst << " " << bestSecond << endl;
            cerr << bestFirstSimple << " " << bestSecondSimple << endl;
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
	//freopen("small.in", "r", stdin);
	freopen("large.in", "r", stdin);

	freopen("output.txt", "w", stdout);

	int numCases;
	cin >> numCases;

	for (int caseNumber = 1; caseNumber <= numCases; caseNumber++)
		PrintAnswerToTestCase(caseNumber, SolveTestCase() );

	return 0;
}