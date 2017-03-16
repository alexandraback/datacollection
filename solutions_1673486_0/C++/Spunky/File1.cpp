// ---------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	ifstream cin("A-small-attempt0.in");
	ofstream cout("A.out");
	int t;

	cin >> t;


	long a[10000], b[10000], d[10000], i =0;

	for (int u = 0; u < t; u++) {
		int a,b;
		float p[10000];
		double mul = 1;
		cin >> a >> b;
		for (int i =0; i < a; i++) {
			cin >> p[i];
			mul *= p[i];
		}

		float temp = b-a + 1;
		float tt = temp + b+1;
		float yy = b+2;
		float min = temp * mul + tt * (1- mul);

		if (min > yy) {
			min = yy;
		}

		int k = 0;
		for (int i = a-1;i >= 0; i--) {
			k++;
			mul /= p[i];
			temp = k + (b - i) + 1;
			tt = temp + b + 1;
			yy = temp * mul + tt * (1- mul);
            if (min > yy) {
				min = yy;
			}
		}






		cout << "Case #" << fixed << setprecision(6) << u+1 << ": " << min;
		cout << endl;

	}
	return 0;
}
// ---------------------------------------------------------------------------
