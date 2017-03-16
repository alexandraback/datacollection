#include<iostream>

using namespace std;

int main(){
	int tests;

	cin >> tests;

	for(int t = 1; t <= tests; ++t){
		bool okay = true;

		int x, r, c;
		cin >> x >> r >> c;

		if(x >= 7) okay = false;
		if(r * c % x) okay = false;
		if(r < x && c < x) okay = false;
		if(r < (x+1)/2 || c < (x+1)/2) okay = false;
		if(min(r, c) == x/2 && x % 2 == 0 && x > 2) okay = false;



		cout << "Case #" << t << ": " << (okay? "GABRIEL": "RICHARD") << endl;
	}

	return 0;
}
