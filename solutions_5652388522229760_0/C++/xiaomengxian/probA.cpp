#include <iostream>
using namespace std;
int testcases;

bool al[10];
int cnt;
long long m, n;
long long ans;

void process(long long n) {
	while (n != 0) {
		int d = n % 10;
		if (!al[d]) {
			al[d] = true;
			cnt ++;
		}
		n /= 10;
	}
}

int main() {
	cin >> testcases;
	for (int testcase = 0; testcase < testcases; testcase ++) {
		memset(al, 0, sizeof(al));
		cnt = 0;
		cin >> m;
		ans = 0;
		if (m == 0) {
			ans = -1;
		} else {
			n = m;
			process(n);
			while (cnt < 10) {
				n += m;
				process(n);
			}
			ans = n;
		}


		cout << "Case #" << testcase + 1 << ": ";
		if (ans < 0) {
			cout << "INSOMNIA";
		} else {
			cout << ans;
		}
		cout << endl;
	}
	return 0;
}