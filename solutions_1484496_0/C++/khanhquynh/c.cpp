#include <iostream>
using namespace std;
int N, B[1000], A[1000];
bool go(int pos, int sum1, int sum2) {
	if (pos == N) {
		if (sum1 == sum2) {
			int i;
			for(i = 0; i < N; i++) {
				if (B[i] == 0) cout << A[i] << " ";
			}
			cout << endl;
			for(i = 0; i < N; i++) {
				if (B[i] == 1) cout << A[i] << " ";
			}
			cout << endl;
			return true;
		} else return false;
	} else {
		B[pos] = 0;
		if (go(pos+1, sum1 + A[pos], sum2)) return true;
		B[pos] = 1;
		if (go(pos+1, sum1, sum2 + A[pos])) return true;
		B[pos] = 2;
		return go(pos+1, sum1, sum2);
	}
}
int main() {
	freopen("c-in.txt", "r", stdin);
	freopen("c-out.txt", "w", stdout);
	int ttt, tt, i;
	cin >> ttt;
	for(tt = 1; tt <= ttt; tt++) {
		cout << "Case #" << tt << ":" << endl;
		cin >> N;
		for(i = 0; i < N; i++) {
			cin >> A[i];
		}
		if (!go(0, 0, 0)) cout << "Impossible" << endl;
	}
//	system("pause");
}
