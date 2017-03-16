#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
#define EPS 1e-15

int N;
int s[1000];
int X;

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		cin >> N;
		X = 0;
		for (int i = 0; i < N; i++) {
			cin >> s[i];
			X += s[i];
		}
		
		cout << "Case #" << icase << ":";
		for (int i = 0; i < N; i++) {
			// binary search over choices of Y_i
			double a = 0, b = 1.0;
			while (fabs(b - a) > EPS)
			{
				double m = .5 * (b+a);
				//cout << a << " " << b << " " << m << endl;
				double score = s[i] + X * m;
				double sum_yj = m;
				for (int j = 0; j < N; j++) {
					if (j == i) continue;
					if (s[j] >= score) continue;
					sum_yj += (score - s[j]) / (double)X;
				}
				if (sum_yj >= 1.0) // too big
					b = m;
				else
					a = m;
			}
			double res = b * 100.0;
			printf(" %.8f", res);
			/*
			double res = 2.0 / (double)N - (double)s[i] / (double)X;
			res *= 100.0;
			if (res < 0) res = 0;
			//cout << " " << res;
			res = b;
			printf(" %.8f", res);*/
		}
		cout << endl;
	}
	return 0;
}
