#include <iostream>
#include <math.h>
using namespace std;

#define RT freopen("a.in", "r", stdin)
#define WT freopen("b.out", "w", stdout)
#define MAX 101

bool isPalndirom(int num) {
	int n = num, rev = 0, dig;
	while(num > 0) {
		dig = num % 10;
		rev = rev * 10 + dig;
		num = num / 10;
	}
	return n == rev;
}

void PreCalc() {
	for(int i = 1; i < 1001; ++i) {
		if(isPalndirom(i) && i == (int)sqrt(i) * (int)sqrt(i) && isPalndirom(sqrt(i)))
			cout << i << " ";
	}
}

int main() {
	RT, WT;
	//PreCalc();
	int FairAndSquar[] = {1, 4, 9, 121, 484};
	int A, B, cases; cin >> cases;
	for(int c = 0; c < cases; ++c) {
		cin >> A >> B;
		int res = 0;
		for(int i = 0; i < 5; ++i)
			if(FairAndSquar[i] >= A && FairAndSquar[i] <= B)
				++res;
		cout << "Case #" << c + 1 << ": " << res << endl;
	}
	return 0;
}