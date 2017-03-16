#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void Open() {
	freopen ("P2.in", "r", stdin);
	freopen ("P2.out", "w", stdout);
}

void Close() {
	fclose(stdin);
	fclose(stdout);
}

vector<pair<int, int>> levels;

bool paircomp(pair<int, int> &a, pair<int, int> &b) {
	return a.second < b.second;
}

int Work() {
	int N;
	scanf ("%d", &N);
	levels.clear();
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf ("%d %d", &a, &b);
		levels.push_back(pair<int, int>(a, b));
	}

	sort(levels.begin(), levels.end(), paircomp);

	int starNo = 0, levelNo = 0;
	bool contFlag = true, badFlag = false;
	while (contFlag) {
		contFlag = false;
		for (int i = 0; i < N; i++) {
			if (levels[i].second <= starNo && levels[i].second >= 0) {
				if (levels[i].first < 0) starNo += 1;
				else starNo += 2;
				levelNo++;
				levels[i].second = -1;
				levels[i].first = -1;
			}
			if (levels[i].second != -1)
				contFlag = true;
		}

		if (!contFlag) break;

		badFlag = true;
		int maxIndex = -1;
		for (int i = 0; i < N; i++) {
			if (levels[i].first >= 0 && levels[i].first <= starNo) {
				badFlag = false;
				if (maxIndex < 0) maxIndex = i;
				if (levels[i].second > levels[maxIndex].second)
					maxIndex = i;
			}
		}

		if (badFlag) break;
		starNo++;
		levels[maxIndex].first = -1;
		levelNo++;
	}

	if (badFlag) return -1;
	else return levelNo;
}

int main() {
	int T;
	Open();
	scanf ("%d", &T);
	for (int i = 0; i < T; i++) {
		int ans = Work();
		printf ("Case #%d: ", i + 1);
		if (ans > 0) printf ("%d\n", ans);
		else printf("Too Bad\n");
	}
	Close();
	return 0;
}