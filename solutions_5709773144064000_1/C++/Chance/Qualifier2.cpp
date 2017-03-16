#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

void solve(double C, double F, double X, int caseNum) {
	int maxFarms = (int)(X / C);
	int farmsAdded = 0;
	double currentTime = 0;
	double cps = 2;
	double timeElapsed = 0;
	while (farmsAdded < maxFarms) {
		double xcps = (X-C) / cps;
		double cf = (C / F) + X / (cps + F);
		double payForItselfTime = C / F;
		if (C/F > ((X-C) / cps)) {
			break;
		}
		else {
			farmsAdded++;
			timeElapsed += C / cps;
			cps += F;
		}
	}
	currentTime = timeElapsed + X/cps;
	cout << "Case #" << caseNum << ": " << setprecision(7) << currentTime << endl;
}

int main(void){
	int numCases;
	cin >> numCases;
	for (int ii = 0; ii < numCases; ++ii) {
		double C, F, X;
		cin >> C;
		cin >> F;
		cin >> X;
		solve(C, F, X, ii + 1);
	}
	return 0;
}