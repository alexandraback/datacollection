#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compara (const int c1, const int c2) {
	return c1<c2;
}

int main(void){
	int T;
	cin >> T;
	for (int k = 0; k < T; ++k){
		int A, B, K;
		cin >> B >> A >> K;
		int cont = 0;
		/*if (A <= K || B <= K){
			cout << "Case #" << k+1 << ": " << A * B << endl;
		} else {
			if (B < A){
				B ^= A;
				A ^= B;
				B ^= A;
			}
			//k < A < B
			cont += K*B;
			for (int i = K; i < A; ++i){
			}

		}*/
		for (int i = 0; i < A; ++i){
			for (int j = 0; j < B; ++j){
				if ((i&j) < K){
					cont ++;
				}
			}
		}


		cout << "Case #" << k+1 << ": " << cont << endl;
	}
	return 0;
}
