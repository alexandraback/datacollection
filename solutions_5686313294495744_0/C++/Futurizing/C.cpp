#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int link[1000][1000] = {};
int slinkA[1000];
int slinkB[1000];

void testcase() {
	int i, j;

	for (i = 0; i < 1000; i++) for (j = 0; j < 1000; j++) link[i][j] = 0;
	for (i = 0; i < 1000; i++) {
		slinkA[i] = 0;
		slinkB[i] = 0;
	}

	int wordCount;
	vector<string> wordsA;
	vector<string> wordsB;

	map<string, int> wordABag;
	map<string, int> wordBBag;

	cin >> wordCount;
	wordsA.resize(wordCount);
	wordsB.resize(wordCount);

	for (i = 0; i < wordCount; i++) {
		cin >> wordsA[i] >> wordsB[i];
		
		int linkA, linkB;
		if (wordABag.find(wordsA[i]) == wordABag.end()) {
			linkA = wordABag.size();
			wordABag[wordsA[i]] = linkA;
		} else {
			linkA = wordABag[wordsA[i]];
		}
		if (wordBBag.find(wordsB[i]) == wordBBag.end()) {
			linkB = wordBBag.size();
			wordBBag[wordsB[i]] = linkB;
		} else {
			linkB = wordBBag[wordsB[i]];
		}
		link[linkA][linkB] = 1;
	}

	// for (i = 0; i < wordABag.size(); i++) {
	// 	for (j = 0; j < wordBBag.size(); j++) {
	// 		cout << link[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	queue<pair<int, bool> > q;
	int countA, countB;
	int ans = 0;
	for (i = 0; i < wordABag.size(); i++) {
		countA = countB = 0;

		q.push(make_pair(i, true));
		while (!q.empty()) {
			int node = q.front().first;
			int onA = q.front().second;
			q.pop();

			if (onA) {
				if (slinkA[node] == 0) {
					slinkA[node] = 1;
					countA++;
					for (j = 0; j < wordBBag.size(); j++) {
						if (link[node][j] == 1) {
							q.push(make_pair(j, false));
						}
					}
				}
			} else {
				if (slinkB[node] == 0) {
					slinkB[node] = 1;
					countB++;
					for (j = 0; j < wordABag.size(); j++) {
						if (link[j][node] == 1) {
							q.push(make_pair(j, true));
						}
					}
				}
			}
		}

		if (countA > countB) {
			ans += countA;
		} else {
			ans += countB;
		}
	}
	cout << (wordCount - ans) << endl;

}

int main() {
	int t, tc;

	cin >> tc;
	for (t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";
		testcase();
	}
	return 0;
}