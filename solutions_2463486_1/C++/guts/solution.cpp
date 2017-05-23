#include <iostream>
#include <math.h>
using namespace std;

#define RT freopen("a.in", "r", stdin)
#define WT freopen("b.out", "w", stdout)
#define MAX 101
#define LL long long

LL FairAndSquar[MAX], sz;

bool isPalndirom(LL num) {
	int n = num, rev = 0, dig;
	while(num > 0) {
		dig = num % 10;
		rev = rev * 10 + dig;
		num = num / 10;
	}
	return n == rev;
}

void PreCalc() {
	sz = 0;
	for(LL i = 1; i < 10000000; ++i) {
		if(isPalndirom(i) && isPalndirom(i * i))
			FairAndSquar[sz++] = i * i;
	}
}

int main() {
	RT, WT;
	PreCalc();
	LL A, B, cases; cin >> cases;
	for(int c = 0; c < cases; ++c) {
		cin >> A >> B;
		int res = 0;
		for(int i = 0; i < sz; ++i)
			if(FairAndSquar[i] >= A && FairAndSquar[i] <= B)
				++res;
		cout << "Case #" << c + 1 << ": " << res << endl;
	}
	return 0;
}