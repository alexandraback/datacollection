#include <iostream>

using namespace std;


void ans(int x, int y){
	int turn = 1;

	while(x > 0){
		cout << "WE";
		--x;
	}

	while(x < 0){
		cout << "EW";
		++x;
	}

	while(y > 0){
		cout << "SN";
		--y;
	}

	while(y < 0){
		cout << "NS";
		++y;
	}
}

int main(){
	int cases;
	int x, y;

	cin >> cases;

	for(int i = 1; i <= cases; ++i){
		cin >> x >> y;
		cout << "Case #" << i << ": ";
		ans(x,y);
		cout << endl;
	}

	return 0;
}