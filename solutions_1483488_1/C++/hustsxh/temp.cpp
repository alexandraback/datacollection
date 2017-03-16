#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

#define N 1000010

using namespace std;

int getBits(int x) {
	int bits = 0;
	while(x) {
		++bits, x /= 10;
	}
	return bits;
}

int pow10(int x) {
	int p = 1;
	for(int i = 0; i < x; ++i) {
		p *= 10;
	}
	return p;
}

int main() 
{
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int T;
	cin >> T;
	for(int testcase = 1; testcase <= T; ++testcase) {
		cout << "Case #" << testcase << ": ";
		int a, b, ans = 0;
		cin >> a >> b;
		int bits = getBits(a);
		int pow10bits = pow10(bits - 1);
		for(int n = a; n <= b; ++n) {
			int m = n;
			set<int> mSet;
			for(int i = 1; i < bits; ++i) {
				m = m / 10 + m % 10 * pow10bits;
				if(n < m && m <= b && mSet.find(m) == mSet.end()) {
					mSet.insert(m);
					++ans;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
