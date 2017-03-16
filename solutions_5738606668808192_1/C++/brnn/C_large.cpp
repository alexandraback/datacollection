#include <iostream> 
using namespace std;

unsigned long long eval(unsigned long long k){
	unsigned long long a = k * k;
	unsigned long long b = a * a;
	unsigned long long c = b * b;
	return c * c + 1;
}

int main(){
	cout << "Case #1:" << endl;

	unsigned long long div[9];
	for (int i = 2; i <= 10; i++){
		div[i-2] = eval(i);
	}

	for (int i = 0; i < 500; i++){
		cout << 1;
		for (int k = 13; k >= 0; k--){
			cout << ((i & (1 << k)) >> k);
		}
		cout << 1 << 1;
		for (int k = 13; k >= 0; k--){
			cout << ((i & (1 << k)) >> k);
		}
		cout << 1 << " ";

		for (int i = 0; i < 9; i++){
			cout << div[i] << " ";
		}
		cout << endl;
	}
}