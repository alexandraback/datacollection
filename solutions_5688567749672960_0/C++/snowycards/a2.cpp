#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

#define rep(i,n) for(int i = 0, _##i = n; i < _##i; ++i)
#define dwn(i,n) for(int i = n; i >= 0; --i)
#define itr(v, it) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define max(a,b) (a>b?a:b)

#define vi vector<int>

#define INF (int) 1e9
#define EPS 1e-9

long long reverse(long long num) {
	long long ret = 0;
	while(num != 0) {
		ret *= 10;
		ret += num % 10;
		num /= 10;
	}
	return ret;
}

int digits(long long num) {
	int digs = 0;
	while(num != 0) {
		digs++;
		num /= 10;
	}
	return digs;
}

int firstDigit(long long num) {
	while(num >= 10) {
		num /= 10;
	}
	return num;
}

long long tenpower(long long num) {
	int base = 1;
	while(num > 0) {
		num--;
		base *= 10;
	}
	return base;
}

void solve() {
	long long target;
	cin >> target;

	long long current = 10;
	long long ops = 10;


	long long revMax = 0;
	long long opsChangeMax = 0;
	if(target <= 19) {
		ops = target;
	} else {
	while(target != current) {
		revMax = 0;
		long long rev = reverse(current);
		int digitsCurrent = digits(current);
		int halfDigits = digitsCurrent/2;
		//cout << "halfdigits: " << halfDigits << endl;
		rep(i, tenpower(halfDigits)) {
			long long tempRev = reverse(current+i);
			if(tempRev <= target)
				revMax = max(revMax, tempRev);
		}
		if(revMax != 0 && revMax > current && revMax > (current + tenpower(halfDigits))) {
		long long unRev = reverse(revMax);
		ops += unRev - current;
		ops++;
		current = revMax;
		//cout << "just switcharooed to rev " << current << endl;
	}
		
		if(digits(current) == digits(target)) {
			ops += target-current;
			break;
		} else {
			long long tens = tenpower(digitsCurrent);
			ops += tens-current;
			current = tens;
		}

		//cout << current << " " << target << endl;
	}
	}

	printf("%d\n", ops);
}

int main() {

	int cases;
	cin >> cases;

	rep(current, cases) {

		printf("Case #%d: ", current+1);
		solve();
	}

	return 0;
}