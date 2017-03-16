#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int X,R,C,cas,T;

int main() {
	cin >> T;
	for (cas=1;cas<=T;cas++) {
		cin >> X >> R >> C;
		cout << "Case #" << cas << ": ";
		if (X>=7) {cout << "RICHARD" << endl; continue;}
		if (R<C) swap(R,C);
		if (X>R || X>2*C || (R*C)%X
			|| (C==3&& X==6) || (C==3 && X==5 && R<7)
			|| (C==2&& X==4)) {cout << "RICHARD" << endl; continue;}
		cout << "GABRIEL" << endl;
	}
	return 0;
}
