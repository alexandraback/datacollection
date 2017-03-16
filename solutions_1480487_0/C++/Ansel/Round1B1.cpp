#include <assert.h>
#include <string.h>
#include <stdio.h>

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

struct item {
	int		index;
	int		score;
	double  percent;
};

bool sortfun1(const item &first, const item &second) {
	if (first.score > second.score) {
		return true;
	} else if (first.score == second.score) {
		return first.index < second.index;
	} else {
		return false;
	}
}

bool sortfun2(const item &first, const item &second) {
	return first.index < second.index;
}


int main() {
	int 	T;
	int 	N;
	cin >> T;
	assert(T > 0 && T <= 100);

	for (int i = 0; i < T; i++) {
		cin	>> N;
		assert(N > 0);
		vector<item>	s(N);
		int   sum = 0;
		for (int j = 0; j < N; ++j) {
			s[j].index = j;
			cin >> s[j].score;
			sum += s[j].score;
		}

		sort(s.begin(), s.end(), sortfun1);

		int		double_sum = sum * 2;
		double  average = double_sum * 1.0 / N;
		int		num_real_average = N;

		for (int j = 0; j < N; ++j) {
			if (s[j].score > average) {
				s[j].percent = 0;
				double_sum -= s[j].score;
				num_real_average--;
				average = double_sum * 1.0/num_real_average;
			} else {
				s[j].percent = (average - s[j].score)*100/sum;
			}
		}

		sort(s.begin(), s.end(), sortfun2);

		cout << "Case #" << i+1 << ":" ;
		for (int j=0; j<N; ++j) {
			printf(" %.6f", s[j].percent);
		}
		cout << endl;
	}

	return 0;
}
