#pragma comment(linker,"/stack:256000000")

#include <cmath> 
#include <ctime> 
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <set> 
#include <map> 
#include <cstring> 
#include <cstdlib> 
#include <queue> 
#include <cstdio> 
#include <cfloat>
#include <cassert>
#include <ctime>

using namespace std; 

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++) 
#define sz(v) (int)(v).size() 
#define all(v) (v).begin(), (v).end()

long long gcd(long long a, long long b) {
	return b? gcd(b, a % b): a;
}

void solve() {
	long long a, b;
	scanf("%I64d/%I64d", &a, &b);
	int iter = 0;
	while (2 * a < b) {
		++iter;
		a *= 2;
	}
	long long na = 2 * a - b;
	long long nb = 2 * b;
	a = na;
	b = nb;
	a *= 2;
	long long g = gcd(a, b);
	a /= g;
	b /= g;
	assert(a <= b);
	for (int i = 0; i <= 40; i++) {
		if ((1LL << i) == b) {
			if (iter + 1 + i <= 40) {
				cout << iter + 1 << endl;
				return;
			} else {
				break;
			}
		}
	}
	cout << "impossible" << endl;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long start = clock();
#endif
	int T;
	cin >> T;
	for (int tst = 1; tst <= T; tst++) {
		cout << "Case #" << tst << ": ";
		solve();
	}
	return 0;
}