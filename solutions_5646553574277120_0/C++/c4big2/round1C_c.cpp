#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;


void main() {
	//freopen("B-large.in", "r", stdin);
	//freopen("B-large.out", "w", stdout);
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	//freopen("inputB.txt", "r", stdin);
	//freopen("outputB.txt", "w", stdout);
	int nCase;
	cin >> nCase;
	vector<int> pre(100, 0);
	int index = 1;
	for (int i = 0; i < 7; ++i) {
		pre[index] = 1;
		index *= 2;
		if (index > 100) break;
	}

	for (int cc = 0; cc < nCase; ++cc) {
		int c, d, v;
		cin >> c >> d >> v;
		vector<int> dd(d);
		for (int i = 0; i < d; ++i)
			cin >> dd[i];
		vector<int> input(v + 1, 0);
		for (int i = 0; i < dd.size(); ++i)
			input[dd[i]]++;
		int ret = 0;
		for (int i = 1; i <= v; ++i)
			if (pre[i] == 1)
				if (input[i] == 0)
					ret++;
		cout << "Case #" << cc + 1 << ": " << ret << endl;
	}
}