#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int ca = 1; ca <= T; ca++) {
		int A, N;
		cin >> A >> N;
		int mini = N;
		int list[N];
		int ops_sum = 0;
		for (int i = 0; i < N; i++)
			cin >> list[i];
		if (A > 1) {
			sort(list, list + N);

			for (int i = 0; i < N; i++) {
				if (A <= list[i]) {
					int ops = 0;
					while (A <= list[i]) {
						A = A * 2 - 1;
						ops++;
					}
					ops_sum += ops;
				}
				mini = min(mini, ops_sum + N - i - 1);
				A += list[i];
			}
		}
		cout << "Case #" << ca << ": " << mini << endl;
	}
	return 0;
}
