#include <iostream>
#include <string>
using namespace std;
int T;
int n, j;
string print(int t, int bit) {
	string ret = "";
	while (t) {
		if (t % 2 == 1) ret = "11" + ret;
		else ret = "00" + ret;
		bit -= 2;
		t = t / 2;
	}
	while (bit) {
		ret = "00" + ret;
		bit -= 2;
	}
	return ret;
}
int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ":" << endl;
		cin >> n >> j;
		for (int y = 0; y < j; y++) {
			cout << "11";
			cout << print(y, n - 4);
			cout << "11";
			for (int x = 2; x <= 10; x++)
				cout << " " << x + 1;
			cout << endl;
		}
	}
}