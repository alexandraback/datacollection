#include <iostream>
#include <stdint.h>
#include <iomanip>
using namespace std;

int main()
{
	int T;
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		double C, F, X;
		// cost of farm, farm rate, object
		cin >> C >> F >> X;
		double clickRate = 2.0;
		
		double totalTime = 0.0;
		
		if (C > X) {
			totalTime = X / clickRate;
		} else {
			while (true) {
				double timeToDirectWin = X / clickRate;
				double timeToNextFarmWin = C / clickRate + X / (clickRate + F);
				if (timeToDirectWin < timeToNextFarmWin) {
					totalTime += timeToDirectWin;
					break;
				} else {
					totalTime += C / clickRate;
					clickRate += F;
				}
			}
		}
		
		cout << "Case #" << t << ": " << std::fixed << setprecision( 6 ) << totalTime;
		
		cout << endl;
	}
}