#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int digits[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

int main(){
	
	int t, a, b, i, j, k, p, digit, total, count, rep;
	cin >> t;
	for (i=0; i<t; i++) {
		cin >> a >> b;
		digit = 1;
		while (b>digits[digit]) {
			digit++;
		}
		total = 0;
		for (j=a; j<=b; j++) {
			count = 0;
			rep = 1;
			for (k=1; k<digit; k++) {
				p = j/digits[k]+(j%digits[k])*digits[digit-k];
				if (p>j && p>=a && p<=b) {
					count++;
				} else if (p==j) {
					rep++;
				}
			}
			total += count/rep;
		}
		cout << "Case #"<<(i+1)<<": "<<total<<endl;
	}
	
	return 0;
}