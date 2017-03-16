#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <vector>
#include <map>
#include <string>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)

void openFiles() {
	freopen("test_small.in", "rt", stdin);
	freopen("test_small.out", "wt", stdout);	
}



int rightmost(int n) {
	for (int i = 0; n > 0; i++) {
		if (n & 1) return i;
		n >>= 1;
	}
	return -1;
}

void printset(int* v, int idx) {
	vector<int> out;

	for (int i = 0; i < 20; i++) {
		if ((idx >> i) & 1) {
			out.push_back(v[i]);
		}
	}

	for (int i = 0; i < out.size(); i++) {
		if (i) printf(" ");
		cout << out[i];
	}

	cout << endl;
}


void solve() {

	int n; scanf("%d ", &n);
	int v[20];

	vector<vector<int>> sums(2000010);
	vector<int> dp(1 << n);
	for (int i = 0; i < n; i++) {
		scanf("%d ", &v[i]);
	}

	for (int i = 1; i < (1 << n); i++) {
		// remove right most bit

		int rightbitidx = rightmost(i);
		int prev = i ^ (1 << rightbitidx);
		int sum = dp[prev] + v[rightbitidx];
		dp[i] = sum;

		sums[dp[i]].push_back(i);
	}

	static int ntest = 0;
	printf("Case #%d:\n", ++ntest);
	for (int i = 0; i < sums.size(); i++) {
		for (int ii = 0; ii < sums[i].size(); ii++) {
			for (int jj = ii + 1; jj < sums[i].size(); jj++) {
				if ((sums[i][ii] & sums[i][jj]) == 0) {

					//cout << sums[i][ii] << " " << sums[i][jj] << endl;

					printset(v, sums[i][ii]);
					printset(v, sums[i][jj]);

					return;
				}
			}
		}
	}

}

int main()
{
	openFiles();

	int n; scanf("%d ", &n);
	for (int i = 0; i < n; i++) {		
		solve();
	}
	
	return 0;
}