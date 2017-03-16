#include<iostream>
#include<cstring>
#include<bitset>
#include "InfInt.h"

using namespace std;

int main() {
	int kases;
	cin >> kases;
	for (int kase = 1; kase <= kases; kase++) {
		cout << "Case #" << kase << ": ";
		unsigned long a, b, k;
		cin >> a >> b >> k;
		bitset<31> ab(a-1);
		bitset<31> bb(b-1);
		bitset<31> kb(k-1);
		long long dp[31][2][2][2] = {0};

		for (int i = 0; i < 31; i++) { //ith bit
			for (int al = 0; al < 2; al++) { // a is limiting
				for (int bl = 0; bl < 2; bl++) { // b is limiting
					for (int kl = 0; kl < 2; kl++) { // k is limiting
						// choose 1 1
						if ((!al || ab[i]) && (!bl || bb[i]) && (!kl || kb[i])) {
							dp[i][al][bl][kl] += (i == 0 ? 1 : dp[i-1][al][bl][kl]); // if it was limiting, it still is
						}
						// choose 1 0
						if (!al || ab[i]) {
							dp[i][al][bl][kl] += (i == 0 ? 1 : dp[i-1][al][bl && !bb[i]][kl && !kb[i]]);
						}
						// choose 0 1
						if (!bl || bb[i]) {
							dp[i][al][bl][kl] += (i == 0 ? 1 : dp[i-1][al && !ab[i]][bl][kl && !kb[i]]);
						}
						// choose 0 0
						dp [i][al][bl][kl] += (i == 0 ? 1 : dp[i-1][al && !ab[i]][bl && !bb[i]][kl && !kb[i]]);
					}
				}
			}

			if (i > 0 && dp[i][1][1][1] < dp[i-1][1][1][1]) {
				cerr << "BARF";
			}
			//cerr << i << " " << dp[i][1][1][1] << endl;
		}

		cout << dp[30][1][1][1] << endl;
	}
	return 0;
}
