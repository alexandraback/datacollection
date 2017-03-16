#include <iostream>
#include <math.h>
using namespace std;

void solve_case(int T){
	int B, M;
	cin >> B >> M;

	cout << "Case #" << T << ": ";
	if (M > pow(2, B - 2)){
		cout << "IMPOSSIBLE" << endl;
		return;
	} else {
		cout << "POSSIBLE" << endl;
	}

	if (B == 2 && M == 1){
		cout << "01" << endl;
		cout << "00" << endl;
		return;
	}

	if (M == pow(2, B - 2)){
		for (int i = 0; i < B; i++){
			for (int j = 0; j <= i; j++){
				cout << '0';
			}
			for (int j = i + 1; j < B; j++){
				cout << '1';
			}
			cout << endl;
		}
		return;
	}

	int d = 0, tmp = 1;
	while (tmp <= M){
		tmp *= 2;
		d++;
	}
	d--;

	for (int i = 0; i < B - d - 2; i++){
		cout << '0';
	}
	for (int i = B - d - 2; i < B; i++){
		cout << '1';
	}
	cout << endl;

	for (int j = 1; j < B - d - 2; j++){
		for (int i = 0; i < B; i++){
			cout << '0';
		}
		cout << endl;
	}

	for (int i = 0; i < B - d - 1; i++){
		cout << '0';
	}
	for (int i = B - d - 1; i < B - 1; i++){
		if (((M >> (B - i - 2)) & 1) == 1){
			cout << '1';
		} else {
			cout << '0';
		}
	}
	cout << '0' << endl;

	for (int j = B - d - 1; j < B; j++){
		for (int i = 0; i <= j; i++){
			cout << '0';
		}
		for (int i = j + 1; i < B; i++){
			cout << '1';
		}
		cout << endl;
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