#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include<cstring>

using namespace std;
int mainB_large() {
	int T;
	int N;
	int S;
	int P;
	int maxCount;
	int forConsideration;
	int marks;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> N >> S >> P;
		maxCount = 0;
		forConsideration = 0;
		for (int j = 0; j < N; j++) {
			cin >> marks;
			if (marks / 3 >= P) {
				++maxCount;
			} else {
				if (marks % 3 == 0 && (marks / 3 + 1) == P && marks/3>0) {
					++forConsideration;
				}
				if (marks % 3 == 1 && (marks / 3 + 1) == P) {
					++maxCount;
				}
				if (marks % 3 == 2 && (marks / 3 + 1) == P) {
					++maxCount;
				}
				if (marks % 3 == 2 && (marks / 3 + 2) == P) {
					++forConsideration;
				}
			}
		}
		if (S <= forConsideration) {
			maxCount += S;
		} else {
			maxCount += forConsideration;
		}
		cout << "Case #" << i << ": " << maxCount << endl;
	}
	return 0;
}
