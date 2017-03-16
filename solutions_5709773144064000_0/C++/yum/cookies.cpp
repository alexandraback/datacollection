#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main () {
	double C,F,X,v,t,bestt,twin,tbuy;
	int testcases;
	cin >> testcases;
	for (int tc = 1; tc <= testcases; tc++) {
		cin >> C >> F >> X;
		v = 2.0;
		t = 0.0;
		bestt = 1e14;
		for (;;) {
			//cout << "Now t=" << t <<", producing at " << v << ", need " << X << " more" << endl;
			twin = t + X / v;
			if (twin > bestt) break;
			bestt = twin;
			tbuy = C / v;
			X -= v * tbuy;
			X += C;
			t += tbuy;
			v += F;
		}
		cout << "Case #" << tc << ": " << fixed << setprecision(7) << bestt << endl;
	}
}
