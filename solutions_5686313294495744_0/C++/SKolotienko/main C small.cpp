#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>

using namespace std;

void test()
{
	int N;
	cin >> N;
	vector<pair<string, string>> topics(N);
	for (int i = 0; i < N; i++) {
		cin >> topics[i].first >> topics[i].second;
	}

	int m = 1 << N;
	//map<string, int> firstWords;
	//map<string, int> secondWords;
	set<string> firstNotFakeWords;
	set<string> secondNotFakeWords;
	int bestFakeN = 0;
	for (int p = 0; p < m; p++) {
		firstNotFakeWords.clear();
		secondNotFakeWords.clear();
		for (int i = 0; i < N; i++) {
			bool isFake = (p & (1 << i)) == 0;
			if (!isFake) {
				firstNotFakeWords.insert(topics[i].first);
				secondNotFakeWords.insert(topics[i].second);
			}
		}
		int fakeN = 0;
		bool canBeFake = true;
		for (int i = 0; i < N; i++) {
			bool isFake = (p & (1 << i)) == 0;
			if (isFake) {
				fakeN++;
				if (firstNotFakeWords.find(topics[i].first) == firstNotFakeWords.end() ||
					secondNotFakeWords.find(topics[i].second) == secondNotFakeWords.end())
				{
					canBeFake = false;
					break;
				}
			}
		}
		if (canBeFake) {
			bestFakeN = max(bestFakeN, fakeN);
		}
	}

	cout << bestFakeN;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cout << "Case #" << i + 1 << ": ";
		test();
		cout << endl;
	}
	return 0;
}
