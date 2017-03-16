#include <iostream>
using namespace std;


int getRotations(int n, int u) {
	int t = n;
	int p = 1;
	while(t/10 > 0) {
		p = p*10;
		t = t/10;
	}
	int rot= n;
	int count = 0;
	do {
		rot = (rot/10) + (rot%10)*p;
	//	cout << rot << endl;
		if(rot > n && rot <= u)
			count++;
	}while(rot != n);
	
	return count;
}


int main() {
	int T;
			cin >> T;
			for(int j=0; j<T; ++j) {
				int l,u;
				cin >> l >> u;
				int count = 0;
				for(int i=l; i<u; ++i) {
					count += getRotations(i,u);
				}
				cout << "Case #" << j+1 << ": " << count << endl;
			}
		return 0;
}
