#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

const double eps = 1e-9;
const int inf = 1e9 + 23;

const int size = 1000;

int main (void){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	int t;
	
	cin >> t;
	
	for (int it = 1; it <= t; it++) {
		int k, c, s;
		cin >> k >> c >> s;
		cout << "Case #" << it << ": ";
		if (k > c * s) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		for (int i = 0; i < (k + c - 1) / c; i++) {
			long long a = i * c + 1;
			long long b = i * c + 1;
			for (int j = 1; j < c; j++) {
				if (b < k)
					b++;
				a = (a - 1) * k + b;
			}
			cout << a;
			if (i < (k - 1) / c) {
				cout << " ";
			}
		}
		cout << endl;
//		if (k % c != 0) {
//			int a = k;
//			for (int j = 1; j < c; j++)
//				a *= k;
//			cout << a << endl;
//		} else
//			cout << endl;
	}
	
	
	return 0;
}