#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	for (int k = 1; k <= n; k++){
		int a, b, c;
		cin >> a >> b >> c;
		switch(a){
			case 1: cout << "Case #" << k << ": GABRIEL" << endl; break;
			case 2: if ((b * c) % 2 == 0) cout << "Case #" << k << ": GABRIEL" << endl;
					else cout << "Case #" << k << ": RICHARD" << endl;
					break;
			case 3: if ((b * c) % 3 == 0 && b > 1 && c > 1) cout << "Case #" << k << ": GABRIEL" << endl;
					else cout << "Case #" << k << ": RICHARD" << endl;
					break;
			case 4: if ((b * c) % 4 || b < 3 || c < 3) cout << "Case #" << k << ": RICHARD" << endl;
					else cout << "Case #" << k << ": GABRIEL" << endl;
					break;
					
		}
	}
	
	return 0;
}
