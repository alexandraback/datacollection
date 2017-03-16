#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;

int main(){
	int tcase;
	cin >> tcase;
	vector<double> N, K, S;
	vector<int>Ni, Ki;
	for(size_t casen = 0; casen < tcase; ++casen)
	{
		int n;
		cin >> n;
		N.resize(n), K.resize(n);
		Ni.resize(n), Ki.resize(n);
		S.resize(2 * n);
		for(size_t i = 0; i < n; ++i) {
			cin >> N[i];
			S[i] = N[i];
		}
		for(size_t i = 0; i < n; ++i) {
			cin >> K[i];
			S[n+i] = K[i];
		}
		sort(N.begin(), N.end());
		sort(K.begin(), K.end());
		int sol1 = 0, sol2 = 0;
		vector<bool> NB(n, false), KB(n, false);
		for (size_t i = 0 ; i < n ; i++) { 
			for (size_t j = 0 ; j < n ; j++) {
				if (K[j] > N[i] && !KB[j]) {
					sol1++;
					KB[j] = true;
					break;
				}
				if (j == n-1) {
					for (size_t k = 0 ; k < n ; k++) {
						if (!KB[k]) {
							KB[k] = true;
							break;
						}
					}
				}
			}
		}
		
		for (size_t i = 0 ; i < n ; i++) { 
			for (size_t j = 0 ; j < n ; j++) {
				if (N[j] > K[i] && !NB[j]) {
					sol2++;
					NB[j] = true;
					break;
				}
				if (j == n-1) {
					for (size_t k = 0 ; k < n ; k++) {
						if (!NB[k]) {
							NB[k] = true;
							break;
						}
					}
				}
			}
		}
		
		
		// sort(S.begin(), S.end(), greater<double>());
		// for(size_t i = 0; i < n; ++i) {
		// 	Ni[i] = lower_bound(S.begin(), S.end(), N[i]) - S.begin();
		// 	Ki[i] = lower_bound(S.begin(), S.end(), K[i]) - S.begin();
		// 	cout << N[i] << "(" << Ni[i] ")" << " " << K[i] << "(" << K[i] << ")" << endl;
		// }	
		
		
		cout << "Case #" << casen + 1 << ": ";
		cout << sol2 << " " << n - sol1 << endl;
	}
	

	return 0;
}
