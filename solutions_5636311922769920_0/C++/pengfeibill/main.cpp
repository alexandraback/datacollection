#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int k, c, s;
		cin >> k >> c >> s;
		cout << "Case #" << i << ":";
		for (int j = 1; j <= k; j++)
			cout << " " << j;
		cout << endl;
	}
	return 0;
}