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


int SolveTestCase() {
    int n;
    int maxPancakes = 0;
    cin >> n;
    vector<int> plates(n);
    for (int i = 0; i < n; i++) {
        cin >> plates[i];
        maxPancakes = max(maxPancakes, plates[i]);
    }
    int ans = maxPancakes;
    for (int ordinaryDays = 1; ordinaryDays <= maxPancakes; ordinaryDays++) {
        int cur = ordinaryDays;
        for (const int p : plates) {
            cur += (p - 1) / ordinaryDays;
        }
        ans = min(ans, cur);
    }
    return ans;
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