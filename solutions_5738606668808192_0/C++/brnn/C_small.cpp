#include <iostream> 
using namespace std;

int eval(int k){
	int a = k * k;
	int b = a * a;
	return b * b + 1;
}

int main(){
	cout << "Case #1:" << endl;

	int div[9];
	for (int i = 2; i <= 10; i++){
		div[i-2] = eval(i);
	}

	for (int i = 0; i < 50; i++){
		cout << 1;
		for (int k = 5; k >= 0; k--){
			cout << ((i & (1 << k)) >> k);
		}
		cout << 1 << 1;
		for (int k = 5; k >= 0; k--){
			cout << ((i & (1 << k)) >> k);
		}
		cout << 1 << " ";

		for (int i = 0; i < 9; i++){
			cout << div[i] << " ";
		}
		cout << endl;
	}
}