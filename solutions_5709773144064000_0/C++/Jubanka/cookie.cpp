#include <iostream>
#include <float.h>

using namespace std;

double simulate(double c, double f, double x)
{
	double t = 0.0, r = 2.0;
	double ptO = DBL_MAX;

	while (true) {
		double dtF = c / r;
		double dtE = x / r;
		double pt = t + dtE;
		if (dtE < dtF) {
			t += dtE;
			break;
		}
		if (ptO < pt) {
			t = ptO;
			break;
		}
		t += dtF;
		r += f;
		ptO = pt;
	}

	return t;
}

int main(void)
{
	int T;
	double C, F, X;

	cout.precision(7);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> C >> F >> X;
		cout << "Case #" << t << ": " << fixed << simulate(C, F, X) << endl;
	}
}
