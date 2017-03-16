#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define EPS (1e-9)

int T, tt;
int n;
vector<int> scores;
int totalScore;
int maxScore;
int secondMax;
bool multipleMax;

bool load() {
	if (tt == T) {
		return false;
	}
	++tt;
	scores.clear();
	totalScore = 0;
	maxScore = -1;
	secondMax = -1;
	multipleMax = false;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s; cin >> s;
		scores.push_back(s);
		totalScore += s;
		if (s == maxScore) {
			multipleMax = true;
		} else if (s > maxScore) {
			multipleMax = false;
			maxScore = s;
		}
	}
	if (multipleMax) {
		secondMax = maxScore;
	} else {
		for (int j = 0; j < n; j++) {
			if (scores[j] > secondMax && scores[j] < maxScore) {
				secondMax = scores[j];
			}
		}
	}
	return true;
}

bool binarySearch(int index, double percent) {
	double thisScore = scores[index] + percent*totalScore;
	double percentLeft = 1.0 - percent;
	for (int j = 0; j < n; j++) {
		if (j == index) continue;
		if (scores[j] < thisScore) {
			percentLeft -= (thisScore - scores[j]) * 1.0 / (totalScore);
		}
	}
	if (percentLeft < EPS) {
		return true;
	} else {
		return false;
	}
}


int main() {
	cin >> T;
	tt = 0;
	while (load()) {
		printf("Case #%d:", tt);
		for (int i = 0; i < n; i++) {
			double low = 0.0, high = 100.0;
			while (abs(high - low) > EPS) {
				double percent = (high + low) / 2.0;
				if (binarySearch(i, percent)) {
					high = percent;
				} else {
					low = percent;
				}
			}
			printf(" %lf", low*100.0);
		}
		printf("\n");
	}
	return 0;
}
