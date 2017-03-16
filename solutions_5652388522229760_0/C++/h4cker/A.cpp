#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL), cout.precision(15);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		long long N; cin >> N;
		bool a[10];
		for (int i = 0; i < 10; i++) a[i] = false;
		int cnt = 0, NB = N;

		for (int i = 1; i <= 100; i++) {
			long long tmp = N;
			while(tmp) {
				long long dig = tmp%10;
				tmp /= 10;
				if (a[dig] == false) {
					a[dig] = true;
					cnt++;
				}
			}
			if (cnt == 10) break;
			N += NB;
		}
		if (cnt == 10) cout << "Case #"<< t <<": " << N << "\n";
		else cout << "Case #"<< t <<": INSOMNIA\n"; 
	}

	return 0;
}
