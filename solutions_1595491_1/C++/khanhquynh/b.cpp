#include <iostream>
using namespace std;

int A[5000];

int main() {
	freopen("b-in.txt", "r", stdin);
	freopen("b-out.txt", "w", stdout);
	int t, tt, i, j, v, N, S, p;
	cin >> tt;
	for(t = 1; t <= tt; t++) {
		cin >> N >> S >> p;
		int cnt = 0;
		for(i = 0; i < N; i++) {
			cin >> A[i];
			
			j = A[i] % 3;
			if (j == 0) v = A[i] / 3;
			else v = A[i] / 3 + 1;
			
			if (S>0 && v+1==p && j!=1 && A[i]>=2 && A[i]<=28) {
				v++; S--;
			}
			
			if (v >= p) cnt++;
		}
		cout << "Case #" << t << ": " << cnt << endl;
	}
//	system("pause");
	return 0;
}
