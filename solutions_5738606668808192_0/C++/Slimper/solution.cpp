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
	cout << "Case #" << caseNumber << ":" << endl;
    for (const auto& coin : ans) {
        cout << coin << endl;
    }
}

vector<string> SolveTestCase() {
    int n, k;
    cin >> n >> k;

    string divisors = "3 4 5 6 7 8 9 10 11";
    vector<string> res;
    for (int i = 0; i < k; i++) {
        vector<bool> mask((n - 2) / 2);
        for (int j = 0; j < mask.size(); j++) {
            mask[j] = i & (1 << j);
        }
        string jamcoin(n, '0');
        jamcoin[0] = '1';
        jamcoin[n - 1] = '1';
        for (int j = 0; j < mask.size(); j++) {
            jamcoin[1 + 2 * j] = '0' + int(mask[j]);
            jamcoin[1 + 2 * j + 1] = '0' + int(mask[j]);
        }
        jamcoin = jamcoin + " " + divisors;
        res.push_back(jamcoin);
    }
    return res;
}

int main()
{
	freopen("input.txt", "r", stdin);
	//freopen("small.in", "r", stdin);
	//freopen("large.in", "r", stdin);

	freopen("output.txt", "w", stdout);

	int numCases;
	cin >> numCases;

	for (int caseNumber = 1; caseNumber <= numCases; caseNumber++)
		PrintAnswerToTestCase(caseNumber, SolveTestCase() );

	return 0;
}