#include <iostream> 
using namespace std;

void solve_case(int T){
	int J, P, S, K;
	cin >> J >> P >> S >> K;

	cout << "Case #" << T << ": ";

	if (K >= S){
		cout << J * P * S << endl;
		for (int i = 0; i < J; i++){
			for (int j = 0; j < P; j++){
				for (int k = 0; k < S; k++){
					cout << (i+1) << " " << (j+1) << " " << (k+1) << endl;
				}
			}
		}
		return;
	}

	if (K == 2 && S == 3){
		cout << J * P * 2 << endl;
		for (int i = 0; i < J; i++){
			for (int j = 0; j < P; j++){
				for (int k = 0; k < S; k++){
					if ((i + j) % 3 != k - 1){
						cout << (i+1) << " " << (j+1) << " " << (k+1) << endl;
					}
				}
			}
		}
	}

	if (K == 1 && S == 3){
		cout << J * P << endl;
		for (int i = 0; i < J; i++){
			for (int j = 0; j < P; j++){
				for (int k = 0; k < S; k++){
					if ((i + j) % 3 == k - 1){
						cout << (i+1) << " " << (j+1) << " " << (k+1) << endl;
					}
				}
			}
		}
	}

	if (K == 1 && S == 2){
		cout << J * P << endl;
		for (int i = 0; i < J; i++){
			for (int j = 0; j < P; j++){
				for (int k = 0; k < S; k++){
					if ((i + j) % 2 == k - 1){
						cout << (i+1) << " " << (j+1) << " " << (k+1) << endl;
					}
				}
			}
		}
	}
}

int main() {
  	int t;
  	cin >> t; 
  	for (int i = 1; i <= t; i++) {
  	  solve_case(i);
  	}
  	return 0;
}