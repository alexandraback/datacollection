#include<cmath>
#include<iostream>

using namespace std;

bool isFair(long long n) {
	long long x = n, t = 0;
	while (x > 0) {
		t = t * 10 + (x % 10);
		x /= 10;
	}
	return (t == n);
}

long long link(int a, int b) {
	long long p = a;
	
	while (b > 0) {
		p = p * 10 + (b % 10);
		b /= 10;
	}
	
	return p;
}

int main() {
	int Ncase;
	
	cin >> Ncase;
	
	for (int index = 1; index <= Ncase; index ++) {
		cout << "Case #" << index << ": ";
		long long a, b, c = 0;
		cin >> a >> b;
		
		for (int i = 1; ; i ++) {
			long long x, y;
			
			x = link(i, i / 10);
			y = x * x;
			
			if (y > b) {
				break;
			}
			
			if (y >= a) {
				if (isFair(y)) {
					c ++;
				}
			}
			
			x = link(i, i);
			y = x * x;
			
			if (y >= a && y <= b) {
				if (isFair(y)) {
					c ++;
				}
			}
		}
		
		cout << c << endl;
	}
	
	return 0;
}
