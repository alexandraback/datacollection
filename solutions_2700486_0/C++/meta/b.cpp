#include <cmath>
#include <stdio.h>
#include <iostream>

using namespace std;

double c(int n, int k) {
	double r = 1;
	for (int i = 0; i < k; ++i) r *= double(n - i)/double(i + 1);
	return r;
}

double f(int d, int y) {
	// cerr << "f (" << d << "," << y << ")\n";
	double r = 0;
	for (int i = y; i <=d ; ++i) {
		r += c(d, i);
	}
	return r * pow(0.5, d);
}

double solve(int x, int y, int n) {
	if (x < 0) x = - x;
	int within = x + y + 1;
	int i = 1;
	while ((i + 3) * (i + 2) / 2 <= n) {
		i += 2;
	}
	// cerr << "within = " << within << "; i = " << i << "\n"; 
	if (i >= within) return 1;
	if (i < within - 2) return 0;
	if (x == 0) return 0;
	int s = i * (i + 1) / 2; //volume of solid part
	int d = n - s;

	int side = i + 1;
	// cerr << "d " << d << " side " << side << "\n";
	if (d > side) {
		int j = d - side;
		d -= j * 2;
		y -= j;
		if (y < 0) return 1;
	}	
	return f(d, y + 1);
}

int main() {
	int cc;
	cin >> cc;
	for (int c = 0; c < cc; ++c) {
		int n;
		cin >> n;
		int x, y;
		cin >> x >> y;
		// cerr << n << " " << x << " " << y << "\n";
		double r = solve(x, y, n);
		printf("Case #%d: %lg\n", c + 1, r);
	}
	return 0;
}