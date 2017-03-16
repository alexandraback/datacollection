#include <iostream>
#include <fstream>
using namespace std;

void obrada() {
	long int r, t;
	cin >> r >> t;
	long int a1 = 3 + 2*(r-1);
	long int d = 4;
	
	long int m1 = 2*a1;
	
	for(long int in=1; 1; in++) {
		if((in*(m1+d*(in-1)))/2>t ) {
			cout << in-1;
			break;
		}
	}
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int t;
	cin >> t;
	
	for(int i=1; i<=t; i++) {
		cout << "Case #" << i << ": ";
		obrada();
		cout << endl;
	}
	
	return 0;
}

