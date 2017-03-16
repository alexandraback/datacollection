#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <fstream>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int v[11];
int E, R, n;
int maxSum;

void go(int z, int e, int curSum) {
	if (z >= n) {
		maxSum = max(maxSum, curSum);
		return;
	}
	if (e < 0) {
		return;
	}
	for (int i = 0; i <= e; i++) {
		go(z + 1, min(E, e - i + R), curSum + i * v[z]);
	}
}

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin >> ntests;
	for (int testnum = 0; testnum < ntests; testnum++) {
		cin >> E >> R >> n;
		for (int i = 0; i < n; i++)
			cin >> v[i];
		maxSum = 0;
		go(0, E, 0);
		cout << "Case #" << testnum + 1 << ": " << maxSum << endl;
	}
	return 0;
}
