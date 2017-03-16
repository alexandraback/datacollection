#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

typedef long double LD;
typedef long long LL;

using namespace std;

#define sz(A) (int)(A).size()
#define mp make_pair
#define pb push_back

const int N = int(1e5 + 5);

LD c, f, x, timer[N];

LD val(int farms) {
	return timer[farms] + x / (2 + f * farms);
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {	
		cin >> c >> f >> x;

		LD rate = 2;
		for (int j = 1; j < N; j++) {
			timer[j] = timer[j - 1] + c / rate;
			rate += f;									
		}

		int l = 0, r = int(1e5 + 1);
		while (l + 2 < r) {
			int lb = (2 * l + r) / 3;
			int rb = (l + 2 * r) / 3;
			if (val(lb) < val(rb)) 
				r = rb;
			else
				l = lb;
		}
		LD res = val(r);
		for (int j = l; j < r; j++)
			res = min(res, val(j));

		cout.precision(7);
		cout << "Case #" << i + 1 << ": " << fixed << res << endl;
	}
	return 0;
}
