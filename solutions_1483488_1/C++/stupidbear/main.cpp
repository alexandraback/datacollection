#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int A, B; cin >> A >> B;
		int ans = 0;
		for (int j = A; j < B; ++j) {
			int k = j; int p = 1;
			while ( (k/=10) != 0 ) {
				p *= 10;
			}
			k = (j%10)*p + j/10;
			// do once;
			while (k != j) {
				if (k > j && k <= B)
					ans++;
				k = (k%10)*p + k/10;
			}
		}
		cout << "Case #" << i+1 << ": " << ans << endl;
	}
}