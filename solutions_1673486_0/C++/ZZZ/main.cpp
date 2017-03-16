#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>

using namespace std;
#define A 3

double p[A+1];
double d[A+1];
int main() {
	freopen("D://A-small-attempt0.in", "r", stdin);
	freopen("D://data.out", "w", stdout);
	int t, a, b;
	double min, tmp;
	double r = 0.0;
	cin >> t;
	for(int cas = 0; cas < t; cas++) {
		cin >> a >> b;
		for(int i = 1; i <= a; ++i)
			cin >> p[i];
		for(int i = 0; i <= a; ++i)
			d[i] = 1.0;

		for(int j = a-1; j >= 0; --j) {
			d[j] = d[j+1] * p[a-j];
		}

		for(int j = a; j > 0; --j) {
			d[j] *= (1-p[a-j+1]);
		}

		min = 10000000;
		for(int i = 0; i <= a; ++i) {
			tmp = 0;
			for(int j = 0; j <= i; ++j)
				tmp += d[j] * (b-a+2*i+1);
			for(int j = i+1; j <=a; ++j)
				tmp += d[j] * (b-a+2*i+b+2);
		
			if(tmp < min)
				min = tmp;
		}

		if(b+2 < min)
			min = b+2;
		printf("Case #%d: %.6f\n", cas+1, min);
		
	}
}