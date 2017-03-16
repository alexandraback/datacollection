#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream cin;
	ofstream cout;
	cin.open("B-large.in");
	cout.open("B-large.out");

	int testCases;
	double c, f, x, r, t;
	
	cin >> testCases;
	cout.precision(10);
	for(int tcase = 1; tcase <= testCases; tcase++) {
		r = 2; t = 0;
		cin >> c >> f >> x;
		while(x > 0) {
			if(x <= c) {
				t += x / r;
				x = 0;
			}
			else if((r + f)*c <= f*x) {
				t += c / r;
				r += f;
			}
			else {
				t += x / r;
				x = 0;
			}
		}
		
		cout << "Case #" << tcase << ": ";
		
		cout << t;
		
		cout << endl;

	}
	
	cin.close();
	cout.close();
	return 0;
}

