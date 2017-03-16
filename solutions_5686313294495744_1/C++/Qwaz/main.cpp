#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>

const int MAX = 1020;
using namespace std;

int fCount, sCount;
map < string, int > fWord, sWord;

int n, crossS[MAX];
bool visitS[MAX];
vector < int > edges[MAX];

bool dfs(int f) {
	for (int s : edges[f]) {
		if (!visitS[s]) {
			visitS[s] = 1;

			if (crossS[s] < 0 || dfs(crossS[s])) {
				crossS[s] = f;
				return true;
			}
		}
	}

	return false;
}

int bipartiteMatch() {
	int ret = 0;

	memset(crossS, -1, sizeof(crossS));

	for (int f = 0; f < fCount; f++) {
		memset(visitS, 0, sizeof(visitS));

		if (dfs(f)) {
			ret++;
		}
	}

	return ret;
}

int main() {
	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(true);

	int numCase, nowCase;
	scanf("%d", &numCase);
	for (nowCase = 1; nowCase <= numCase; nowCase++) {
		fWord.clear();
		sWord.clear();
		for (int i = 0; i < fCount; i++)
			edges[i].clear();
		fCount = sCount = 0;

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			string fStr, sStr;
			cin >> fStr >> sStr;

			int fIndex, sIndex;
			if (fWord.find(fStr) == fWord.end()) {
				fWord[fStr] = fCount;
				fIndex = fCount;
				fCount++;
			} else {
				fIndex = fWord[fStr];
			}
			if (sWord.find(sStr) == sWord.end()) {
				sWord[sStr] = sCount;
				sIndex = sCount;
				sCount++;
			} else {
				sIndex = sWord[sStr];
			}

			edges[fIndex].push_back(sIndex);
		}

		int numMatch = bipartiteMatch();

		printf("Case #%d: %d\n", nowCase, n - (fCount + sCount - numMatch));
	}

	return 0;
}