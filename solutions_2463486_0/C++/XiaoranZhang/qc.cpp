#include<cmath>
#include<iostream>

using namespace std;

bool isFair(int n) {
	int x = n, t = 0;
	while (x > 0) {
		t = t * 10 + (x % 10);
		x /= 10;
	}
	return (t == n);
}

int main() {
	int Ncase;
	
	cin >> Ncase;
	
	for (int index = 1; index <= Ncase; index ++) {
		cout << "Case #" << index << ": ";
		int a, b, c = 0;
		cin >> a >> b;
		
		for (int i = a; i <= b; i ++) {
			int j = sqrt(i);
			if (j * j == i && isFair(i) && isFair(j)) {
				++ c;
			}
		}
		
		cout << c << endl;
	}
	
	return 0;
}
