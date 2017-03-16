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
    cout << "Case #" << caseNumber << ": ";
    for (int d : ans) {
        cout << d;
    }
    cout << endl;
}

vector<int> SolveTestCase() {
    string s;
    cin >> s;
    map<char, int> counts;
    for (char ch : s) {
        counts[ch]++;
    }

    vector<string> names = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

    vector<int> digits;
    string keys = "ZWUXGSVTIO";
    vector<int> keyDigits = { 0, 2, 4, 6, 8, 7, 5, 3, 9, 1 };
    for (int i = 0; i < 10; i++) {
        int t = counts[keys[i]];
        for (int j = 0; j < t; j++) {
            digits.push_back(keyDigits[i]);
        }
        for (char ch : names[keyDigits[i]]) {
               counts[ch] -= t;
        }
    }
    sort(digits.begin(), digits.end());

    return digits;
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