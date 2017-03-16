#include <iostream>
#include <fstream>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <thread>

using namespace std;

int denoms[200][100];


int ans[200];


int counter = 0;

void singleGo(int num, int c, int d, int v, int denom) {
	int curAns = v - d;

	for (int mask = 0; mask < (1 << v); mask++) {
		int nonZero = 0;
		for (int i = 0; i < v && (mask >= (1 << i)); i++) {
			if ((mask & (1 << i)) != 0) {
				denoms[num][d + nonZero++] = i + 1;
				if ((denom & (1 << (i + 1))) != 0) {
					nonZero = curAns * 2;
					break;
				}
			}
		}

		if (nonZero >= curAns)
			continue;

		int can = 1;
		for (int j = 0; j < d + nonZero && can != (1 << (v + 1)) - 1; j++) {
			for (int i = v - 1; i >= 0; i--) {
				if ((can & (1 << i)) != 0 && i + denoms[num][j] <= v) {
					can |= 1 << (i + denoms[num][j]);
					if (can == (1 << (v + 1)) - 1)
						break;
				}
			}
		}

		bool allCan = (can == (1 << (v + 1)) - 1);

		if (allCan) {
			curAns = min(curAns, nonZero);
		}
	}

	ans[num] = curAns;

	cout << counter++ << endl;
}


void go(int n, int nums[], int c[], int d[], int v[], int denom[]) {
	for (int i = 0; i < n; i++) {
		singleGo(nums[i], c[i], d[i], v[i], denom[i]);
	}
}

int main() {
	//ios_base::sync_with_stdio(false);
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	int tests;
	cin >> tests;
	int *nums = new int[tests + 1];
	int *c = new int[tests + 1];
	int *d = new int[tests + 1];
	int *v = new int[tests + 1];
	int *denom = new int[tests + 1];
	for (int i = 0; i < tests + 1; i++) {
		denom[i] = 0;
	}

	for (int test = 1; test <= tests; test++) {
		nums[test] = test;
		cin >> c[test] >> d[test] >> v[test];

		for (int i = 0; i < d[test]; i++) {
			int q;
			cin >> q;
			denom[test] |= (1 << q);
			denoms[test][i] = q;
		}
	}

	int threads = 10;
	int perThread = tests / threads;
	
	vector<thread*> thrs;
	for (int i = 0; i < threads; i++) {
		int l = i * perThread;
		int r = (i + 1) * perThread;
		if (i == threads - 1)
			r = tests;
		thread *th = new thread(go, r - l, &nums[l + 1], &c[l + 1], &d[l + 1], &v[l + 1], &denom[l + 1]);
		thrs.push_back(th);
	}

	for (int i = 0; i < thrs.size(); i++)
		(*(thrs[i])).join();

	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": " << ans[test] << endl;
	}

	//system("pause");
	return 0;
}