#include <iostream>
using namespace std;

int gett(int x) {
	int t;
	for(t = 1; t*10 <= x; t *= 10);
	return t;
}

int next(int x, int t) {
	return x / 10 + (x % 10) * t;
}

int main() {
	freopen("c-in.txt", "r", stdin);
	freopen("c-out.txt", "w", stdout);
	int tt, A, B, x, x1, t, t1, cnt;
	cin >> tt;
	for(t1 = 1; t1 <= tt; t1++) {
		cin >> A >> B;
		cnt = 0;
		for(x = A; x <= B; x++) {
			t = gett(x);
			for(x1 = next(x, t); x1 != x; x1 = next(x1, t)) {
//				cout << x1 << " ";
				if (t <= x1 && x < x1 && x1 <= B) cnt++;
			}
//			cout << endl;
		}
		cout << "Case #" << t1 << ": " << cnt << endl;
	}
//	system("pause");
	return 0;
}
