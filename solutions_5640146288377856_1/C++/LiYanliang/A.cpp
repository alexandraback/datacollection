#include <iostream>

using namespace std;

int main(){
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++){
		int a, b, c, d;
		cin >> a >> b >> c;
		if (b % c == 0) d = a * b / c + c - 1;
		else d = a * (b / c) + c;
		cout << "Case #" << k << ": " << d << endl;
	}
	
	return 0;
}
