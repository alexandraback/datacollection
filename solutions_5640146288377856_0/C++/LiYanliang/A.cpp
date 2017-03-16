#include <iostream>

using namespace std;

int main(){
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++){
		int a, b, c, d;
		cin >> a >> b >> c;
		if (b == c) d = c;
		else if (b % c == 0){
			d = b / c + c - 1;
		}
		else d = b / c + c;
		cout << "Case #" << k << ": " << d << endl;
	}
	
	return 0;
}
