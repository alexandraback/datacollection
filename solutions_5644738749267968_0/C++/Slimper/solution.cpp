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
	cout << "Case #" << caseNumber << ": " << ans.first << " " << ans.second << endl;
}

int Score(const vector<double>& a, const vector<double>& b) {
    int score = 0;
    int pos = 0;
    for (int i = 0; i < a.size(); i++) {
        while (pos < b.size() && b[pos] <= a[i]) {
            pos++;
        }
        if (pos == b.size()) {
            break;
        }
        else {
            score++;
            pos++;
        }
    }
    return score;
}

template <class AnswerType>
AnswerType SolveTestCase() {
    int n;
    cin >> n;
    vector<double> naomi(n);
    vector<double> ken(n);
    for (int i = 0; i < n; i++) {
        cin >> naomi[i];
    }
    sort(naomi.begin(), naomi.end());
    for (int i = 0; i < n; i++) {
        cin >> ken[i];
    }
    sort(ken.begin(), ken.end());
    pair<int, int> ans;
    ans.first = Score(ken, naomi);
    ans.second = n - Score(naomi, ken);
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
		PrintAnswerToTestCase(caseNumber, SolveTestCase< pair<int, int>>() );

	return 0;
}