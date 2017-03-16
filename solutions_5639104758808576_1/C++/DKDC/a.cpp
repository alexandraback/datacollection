#include<iostream>

using namespace std;

int main(void)
{
	int T, SMax, n = 1;
	int S[1001];

	cin >> T;

	while (n <= T) {
		cin >> SMax;
		for (int i = 0; i <= SMax; i++) {
			scanf("%1d", &S[i]);
		}
		int ans = 0;
		long SU = S[0];
		for (int i = 1; i <= SMax; i++) {
			if (S[i] > 0 && SU < i) {
				ans += i - SU;
				SU = i + S[i];
			} else {
				SU += S[i];
			}
		}
		cout << "Case #" << n++ << ": " << ans << endl;
	}
	return 0;
}
