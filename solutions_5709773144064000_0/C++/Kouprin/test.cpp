#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

#define plus asdplus

int t;
long double c, f, x, plus = 2, ans = 1e200, tm = 0;

void check() {
	ans = min(ans, tm + x / plus);
}

int main() {
cin >> t;
for(int T = 0; T < t; ++T) {
	plus = 2;
	ans = 1e200;
	tm = 0;
	cout << "Case #" << T + 1 << ": ";

	cin >> c >> f >> x;

	for(int j = 0; j < 1000000; ++j) {
		check();
		tm += c / plus;
		plus += f;
	}

	printf("%.9lf\n", double(ans));
	//cout << ans << endl;
}
	return 0;
}
