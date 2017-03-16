#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	for(int c=1;c<=T;c++) {
		int A,B,K;
		cin >> A >> B >> K;
		int sum = 0;
		for(int i=0;i<A;i++) {
			for(int j=0;j<B;j++) {
				if((i&j)<K) {
					sum ++;
				}
			}
		}
		cout << "Case #" << c << ": " << sum << endl;
	}
}