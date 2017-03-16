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
		long long int A, B, K;
		cin >> B >> A >> K;
		long long int cont = 0;
		if (A <= K || B <= K){
			cout << "Case #" << k+1 << ": " << A * B << endl;
		} else {
			if (B < A){
				B ^= A;
				A ^= B;
				B ^= A;
			}
			//k < A < B
			cont += K*B;
			/*for (int i = K; i < A; ++i){
			}*/
			int v = 1;
			int aux = K;
			while (aux > 0){
				aux /= 2;
				v*= 2;
			}
			for (int i = K; i < A; ++i){//10^9
				if (i == v) v*= 2;
				if (v < B){
					int contAux = K;
					for (int j = K; j < v; ++j){//10^9
						if ((i&j) < K){
							contAux ++;
						}
					}
					cont += contAux*(B/v);
					for (int j = B/v*v; j < B; ++j){
						if ((i&j) < K){
							cont ++;
						}
					}
				} else {
					cont += K;
					for (int j = K; j < B; ++j){
						if ((i&j) < K){
							cont ++;
						}
					}

				}

				/*cont += K;
				for (int j = K; j < B; ++j){
					if ((i&j) < K){
						cont ++;
					}
				}*/
			}
			cout << "Case #" << k+1 << ": " << cont << endl;
		}
	}
	return 0;
}
