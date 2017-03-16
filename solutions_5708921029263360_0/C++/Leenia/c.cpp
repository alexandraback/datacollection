#include <iostream>
#include <cstring>

using namespace std;

void inss();

int j, p, s, k;

int dp1[11][11];
int dp2[11][11];
int dp3[11][11];

int main()
{
	int T;
	cin >> T;
	for (int z = 1; z <= T; z++) {
		
		cin >> j >> p >> s >> k;

		for (int i = 0; i <= 11; i++) {
			for (int j = 0; j <= 11; j++) {
				dp1[i][j] = 0;
			}
		}
		for (int i = 0; i <= 11; i++) {
			for (int j = 0; j <= 11; j++) {
				dp2[i][j] = 0;
			}
		}
		for (int i = 0; i <= 11; i++) {
			for (int j = 0; j <= 11; j++) {
				dp3[i][j] = 0;
			}
		}

		int count = 0;

		for (int i = 1; i <= s; i++) {
			for (int l = 1; l <= p; l++) {
				for (int w = 1; w <= j; w++) {
					if (dp1[i][l] < k && dp2[i][w] < k && dp3[l][w] < k) {
						dp1[i][l]++;
						dp2[i][w]++;
						dp3[l][w]++;
						count++;
					}
				}
			}
		}

		cout << "Case #" << z << ": " << count << endl;

		for (int i = 0; i <= 11; i++) {
			for (int j = 0; j <= 11; j++) {
				dp1[i][j] = 0;
			}
		}
		for (int i = 0; i <= 11; i++) {
			for (int j = 0; j <= 11; j++) {
				dp2[i][j] = 0;
			}
		}
		for (int i = 0; i <= 11; i++) {
			for (int j = 0; j <= 11; j++) {
				dp3[i][j] = 0;
			}
		}

		for (int i = 1; i <= s; i++) {
			for (int l = 1; l <= p; l++) {
				for (int w = 1; w <= j; w++) {
					if (dp1[i][l] < k && dp2[i][w] < k && dp3[l][w] < k) {
						dp1[i][l]++;
						dp2[i][w]++;
						dp3[l][w]++;
						cout << w << " " << l << " " << i << endl;
					}
				}
			}
		}
	}
	return 0;
}