// Problem 3, Round 1A, GCJ 2013
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

const int MAX_SET_NUM = 128;

int r, n, m ,k;
int set[MAX_SET_NUM][13];
double prob[MAX_SET_NUM];
int set_cnt = 0;

int cur_set[13];
double frac[13] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};

void genSet(int d) {
	if (d == n) {
		memcpy(set[set_cnt], cur_set, sizeof(cur_set));
		++ set_cnt;
	} else {
		for (int i = (d == 0 ? 2 : cur_set[d - 1]); i <= m; ++i) {
			cur_set[d] = i;
			genSet(d + 1);
		}
	}
}

void initProb() {
	for (int i = 0; i < set_cnt; ++i) {
		int cnt[10];
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < n; ++j) {
			++ cnt[set[i][j]];
		}
		double p = frac[n];
		for (int j = 0; j < 10; ++j) {
			p /= frac[cnt[j]];
		}
		prob[i] = log(p) * k;
	}
}

int prodCase(int setid, long long prod) {
	int ans = 0;
	for (unsigned int code = 0; code < (unsigned int)(1 << n); ++ code) {
		long long tmp = 1;
		for (int i = 0; i < n; ++i) {
			if ((code & (1 << i)) != 0) {
				tmp *= set[setid][i];
			}
		}
		if (tmp == prod) {
			++ans;
		}
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	cin >> r >> n >> m >> k;
	cout << "Case #1:" << endl;
	genSet(0);
	initProb();
	for (int caseNum = 0; caseNum < r; ++caseNum) {
		double tmpProb[MAX_SET_NUM];
		memcpy(tmpProb, prob, sizeof(tmpProb));
		long long prod;
		for (int i = 0; i < k; ++i) {
			cin >> prod;
			for (int j = 0; j < set_cnt; ++j) {
				tmpProb[j] += log((double)prodCase(j, prod));
			}
		}
		int max_id = 0;
		double maxProb = -1e9;
		for (int i = 0; i < set_cnt; ++i) {
			if (tmpProb[i] > maxProb) {
				maxProb = tmpProb[i];
				max_id = i;
			}
		}
		for (int i = 0; i < n; ++i) {
			cout << set[max_id][i];
		}
		cout << endl;
	}
	return 0;
}