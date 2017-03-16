#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

#define ALL(v) v.begin(), v.end()

using namespace std;

template< typename T > T next() {  T tmp; cin >> tmp; return tmp; }

const int l = 29;

long long compare(int a, int b, int la, int lb, int k) {
	long long res = 1;
	long long sum = 0;
	for (int i = l; i >= 0; --i) {
		int bk = (k >> i) % 2;
		int ba = (a >> i) % 2;
		int bb = (b >> i) % 2;

		if (i >= la && i >= lb) {
			if ((ba & bb) < bk) {
				return sum + (res << (la + lb));
			}
			if ((ba && bb) > bk) {
				return 0;
			}
			continue;
		}
		if (i >= la || i >= lb) {
			int fixed = i < la ? bb : ba;
			if (fixed == 0 && bk == 0) {
				res *= 2;		
				continue;		
			} else if (fixed == 1 && bk == 0) {
				continue;
			} else if (fixed == 0 && bk == 1) {
				return sum + (res << (i + 1 + min(la, lb)));
			} else if (fixed == 1 && bk == 1){
				sum += res << (i + min(la, lb));
				continue;
			}
		}
		if (bk == 1) {
			sum += 3 * res * (1 << (2 * i));
		} else {
			res *= 3;
		}
	}
	return sum;
}

void solve() {
	int a = next< int >();
	int b = next< int >();
	int k = next< int >();

	
	long long sum = 0;
	for (int ba = l; ba >= 0; --ba) {
		if ((a >> ba) % 2 == 0) continue;
		for (int bb = l; bb >= 0; --bb) {
			if ((b >> bb) % 2 == 0) continue;
			sum += compare(a ^ (1 << ba), b ^ (1 << bb), ba, bb, k);
		}
	}
	//cout << tmp << "\n";
	cout << sum << "\n";
}

int main() {

//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

  int test = next< int >();
  for (int i = 1; i <= test; ++i) {
    printf("Case #%d: ", i);
    solve();
  }

  return 0;
}


