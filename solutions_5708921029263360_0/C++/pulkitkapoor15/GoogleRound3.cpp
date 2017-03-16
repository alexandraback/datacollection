#include <bits/stdc++.h>
using namespace std;


int main() {
	int T, N, num1, num2, num3, num4, counts;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		cin >> num1 >> num2 >> num3 >> num4;
		cout << num1*num2*min(num3, num4) << "\n";
		for (int j=0; j<num1; j++) {
			for (int p=0; p<num2; p++) {
				for (counts = 0; counts < min(num4, num3); counts++) {
					cout << j+1 << " " << p+1 << " " << counts+1 << endl;
				}
			}
		}
	}
	return 0;
}
