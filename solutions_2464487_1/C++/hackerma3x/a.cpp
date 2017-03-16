#include <iostream>
#include <fstream>
using namespace std;

void obrada() {
	long int r, t;
	cin >> r >> t;
	long int a1 = 3 + 2*(r-1);
	
	long int m1 = 2*a1;
	
	long int t2 = 2*t;
	
	/*for(long int in=1,m=2*a1; 1; in++, m+=4)
		if(t2/in<m) {
			cout << in-1;
			break;
		}
	*/
	for(long int in=1; 1; in++) {
		if((in*(m1+d*(in-1)))/2>t ) {
			cout << in-1;
			break;
		}
	}
}

int main() {
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int t;
	cin >> t;
	
	for(int i=1; i<=t; i++) {
		cout << "Case #" << i << ": ";
		obrada();
		cout << endl;
	}
	
	return 0;
}

