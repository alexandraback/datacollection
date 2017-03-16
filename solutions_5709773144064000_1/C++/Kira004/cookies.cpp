#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int casenum;
	double C, F, X;
	
	cin >> casenum;
	for (int i = 1; i <= casenum; ++i) {
		cin >> C >> F >> X;
		if (C > X) {
			cout << "Case #" << i <<": " << fixed << setprecision(7) << X/2 << endl;
			continue;	
		}
		double threshold = F * (X - C) / C;
		double t = 0, s = 2;
		while (s < threshold) {
			t += C/s;
			s += F;
		}
		t += X/s;
		cout << "Case #" << i <<": " << fixed << setprecision(7) << t << endl;
	}
}
