#include <iostream>
#include <set>

using namespace std;

int main() {
	int nTests, test;
	scanf("%d", &nTests);
	for (int test = 1; test <= nTests; ++test) {
		int A, B;
		scanf("%d %d", &A, &B);
		int nDigits = 0;
		int Acp = A;
		while (Acp > 0) {
			++nDigits;
			Acp /= 10;
		}
		int ans = 0;
		for (int n = A; n <= B; ++n) {
			set<int> S;
			int pot = 1;
			int pot_ = 1;
			for (int a = 1; a <= nDigits; ++a) {
				pot_ *= 10;
			}
			for (int ex = 1; ex < nDigits; ++ex) {
				pot *= 10;
				pot_ /= 10;
				int m = (n % pot) * pot_ + n / pot;
				if (A <= n && n < m && m <= B) {
					S.insert(m);
				}
			}
			ans += S.size();
		}
		printf("Case #%d: %d\n", test, ans);
	}
	return 0;
}
