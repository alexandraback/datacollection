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

bool IsValid(const vector<string>& cars, const vector<int>& p) {
    string train;
    for (size_t i = 0; i < cars.size(); i++) {
        train += cars[p[i]];
    }
    vector<bool> finished(26, false);
    vector<bool> started(26, false);
    for (int i = 0; i < train.length(); i++) {
        started[train[i] - 'a'] = true;
        if (i > 0) {
            if (train[i - 1] != train[i]) {
                finished[train[i - 1] - 'a'] = true;
            }
        }
        if (finished[train[i] - 'a']) {
            return false;
        }
    }
    return true;
}
template <class AnswerType>
AnswerType SolveTestCase() {
    int n;
    cin >> n;
    vector<string> cars(n);
    for (int i = 0; i < n; i++) {
        cin >> cars[i];
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    int ans = 0;
    ans += IsValid(cars, p);
    while (next_permutation(p.begin(), p.end())) {
        ans += IsValid(cars, p);
    }
	return ans;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	freopen("B-small.in", "r", stdin);
	//freopen("large.in", "r", stdin);

	freopen("output.txt", "w", stdout);

	int numCases;
	cin >> numCases;

	for (int caseNumber = 1; caseNumber <= numCases; caseNumber++)
		PrintAnswerToTestCase(caseNumber, SolveTestCase<int>() );

	return 0;
}