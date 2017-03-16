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

bool InKeyboard(string keyboard, string word) {
    for (char w : word) {
        int count = 0;
        for (int i = 0; i < keyboard.length(); i++) {
            count += (w == keyboard[i]);
        }
        if (count == 0) return false;
    }
    return true;
}

double GetWordProbability(string keyboard, string word) {
    int k = keyboard.length();
    double prob = 1.0;
    for (char w : word) {
        int count = 0;
        for (int i = 0; i < k; i++) {
            count += (w == keyboard[i]);
        }
        prob = (prob * count) / k;
    }
    return prob;
}

int GetMaxTimes(int s, string keyboard, string word) {
    if (!InKeyboard(keyboard, word)) {
        return 0;
    }
    for (int pos = 1; pos < word.size(); pos++) {
        if (word.substr(pos) == word.substr(0, word.length() - pos)) {
            return (s - word.length()) / pos + 1;
        }
    }
    return s / word.length();
}


double SolveTestCase() {
    int k, len, s;
    cin >> k >> len >> s;
    string keyboard;
    string word;
    cin >> keyboard >> word;

    double wordProb = GetWordProbability(keyboard, word);
    int maxTimes = GetMaxTimes(s, keyboard, word);
    return maxTimes - wordProb * (s - len + 1);
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