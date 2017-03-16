#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;


vector<long> vsteps;
long msteps;

long flip(long n) {
	long n2 = 0;
	while(n > 0) {
		n2 *= 10;
		n2 += n%10;
		n /= 10;
	}
	return n2;
}

long calc(long current, long n, long steps) {
	while (current != n) {
		int flipped = flip(current);
		if (flipped > current and flipped <= n) {
			if(flip(current+1) <= n and flip(current+1) > flipped) {
				++current;	
			} else {
				current = flipped;
			}
		} else {
			++current;	
		}
		++steps;
	}
	return steps;
}

int main() {
	int t;
	cin >> t;
	for (int c = 1; c < t+1; ++c) {
		vsteps = vector<long>(pow(10,6), -1);
		msteps = pow(10,15);
		long n; 
		cin >> n;
		cout << "Case #" << c << ": " << calc(1, n, 1) << endl;
	}
}