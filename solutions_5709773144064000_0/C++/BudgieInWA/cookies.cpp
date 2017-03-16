#include<iostream>
#include<cstdio>

using namespace std;

int main() {
	int kases;
	cin >> kases;
	for (int kase = 1; kase <= kases; kase++) {
		double c, f, x;
		cin >> c >> f >> x;
		double r = 2.0; // cookie rate

		double bestTime = x; // inf
		double currentTime = 0.0;
		while (true) {
			double timeTillDone = x / r;
			double timeTillFarm = c / r;
			double doneTime = currentTime + timeTillDone;
			if (doneTime > bestTime) break; // buying more farms was detrimental
			bestTime = doneTime;

			// buy another farm
			currentTime += timeTillFarm;
			r += f;
		}

		printf("Case #%d: %.7f\n", kase, bestTime);
	}
	return 0;
}
