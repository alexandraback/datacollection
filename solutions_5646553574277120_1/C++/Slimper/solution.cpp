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

vector< vector<char> > field;

template<class AnswerType>
void PrintAnswerToTestCase(size_t caseNumber, AnswerType ans)
{
	cerr << "Case #" << caseNumber << endl;
    cout << "Case #" << caseNumber << ": " << ans << endl;
  
}



int SolveTestCase() {
    int maxCoins;
    int numCoins;
    int v;
    cin >> maxCoins >> numCoins >> v;
    vector<int> coins(numCoins);
    for (int& c : coins) {
        cin >> c;
    }
    coins.push_back(v + 1);
    sort(coins.begin(), coins.end());
    int ans = 0;
    long long maxCovered = 0;
    long long c = maxCoins;
    for (int i = 0; i < coins.size(); i++) {
        if (maxCovered + 1 < coins[i]) {
            long long t = maxCovered + 1;
            long long toCover = coins[i] - 1 - maxCovered;
            int deg = 1;
            long long s = c * t;
            while (s < toCover) {
                s = (c + 1) * s + c * t;
                deg++;
            }
            ans += deg;
            maxCovered += s;
        } 
        if (i + 1 < coins.size()) {
            maxCovered += c * coins[i];
        }
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