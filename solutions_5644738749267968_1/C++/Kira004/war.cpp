#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int casenum;
	cin >> casenum;

	for (int i = 1; i <= casenum; ++i) {
		int N;
		cin >> N;
		vector<double> Naomi(N, 0);
		vector<double> Ken(N, 0);
		for (int j = 0; j < N; ++j)
			cin >> Naomi[j];
		for (int j = 0; j < N; ++j)
			cin >> Ken[j];
		sort(Naomi.begin(), Naomi.end());
		sort(Ken.begin(), Ken.end());
		int D_points = 0;
		int W_points = 0;
		int K_count = 0, N_count = 0;
		int m = 0, n = 0;
		//Deceiful War
		while (m < N && n < N) {
			if (Naomi[m] < Ken[n]) {
				if (K_count > 0) {
					K_count--;
					D_points++;
				}	
				m++;
			}
			else {
				K_count++;
				n++;
			}
		}
		D_points += N - m;
		//War
		m = N - 1;
		n = N - 1;
		while (m >= 0 && n >= 0) {
			if (Naomi[m] > Ken[n]) {
				N_count++;
				m--;
			}
			else {
				N_count--;
				n--;
			}
			if (N_count > W_points)
				W_points = N_count;
		}
		cout << "Case #" << i << ": " << D_points <<" " << W_points << endl;
	}
}
