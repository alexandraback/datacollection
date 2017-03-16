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
#include <time.h>
#include <memory.h>
#include <sstream>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);

	ifstream cin("input.txt");
	ofstream cout("output.txt");

	int tests;
	cin >> tests;
	for (int t = 1; t <= tests; t++) {
		int n;
		cin >> n;
		vector<int> f(2555);
		for (int i = 0; i < n * (2 * n - 1); i++) {
			int q;
			cin >> q;
			f[q]++;
		}

		cout << "Case #" << t << ": ";
		for (int i = 1; i <= 2500; i++) {
			if (f[i] % 2 != 0) {
				cout << i << " ";
			}
		}
		cout << endl;
	}

	//system("pause");
	return 0;
}