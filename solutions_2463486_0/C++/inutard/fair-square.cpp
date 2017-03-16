#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef complex<ld> pt;

long long T;
long long a, b;

long long reverse(long long n) {
	long long res = 0;
	while (n > 0) {
		long long dig = n % 10;
		res = res*10 + dig;
		n /= 10;
	}
	
	return res;
}

bool is_palin(long long n) {
	return (n == reverse(n));
}

bool is_fair_square(long long n) {
	ll sn = ll(sqrt(n));
	if (is_palin(n) && is_palin(sn) && sn*sn == n) return true;
	return false;
}

int main() {
	cin >> T;
	for (long long c = 1; c <= T; c++) {
		long long cnt = 0;
		cin >> a >> b;
		for (long long i = a; i <= b; i++) {
			if (is_fair_square(i)) cnt++;
		}
		
		cout << "Case #" << c << ": " << cnt << endl;
	}
	return 0;
}