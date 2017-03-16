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
    if (ans.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (auto pos : ans) {
            cout << pos << " ";
        }
        cout << endl;
    }
}

vector<long long> SolveTestCase() {
    int k, c, s;
    cin >> k >> c >> s;
    vector<long long> ans;
    if (s * c < k) {
        return ans;
    }
    for (int i = 0; i < k; i += c) {
        long long pos = 0;
        for (int j = 0; j < c; j++) {
            pos = k * pos;
            if (i + j < k) {
                pos += i + j;
            }
        }
        ans.push_back(pos + 1);
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
		PrintAnswerToTestCase(caseNumber, SolveTestCase() );

	return 0;
}