#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		int a, b, k;
		cin >> a >> b >> k;

		int res = 0;
		for(int m = 0; m < a; ++m)
			for(int n = 0; n < b; ++n) {
				res += ((m&n) < k);
			}

		cout << "Case #" << i << ": " << res << endl;
	}
	
	return 0;
}
