#include <stdio.h>

int main (void) {
	char temp[81];
	
	int cases;
	int currentCase;
	
	double C;
	double F;
	double X;
	double cookieRatio;
	double timeToFarm;
	double timeToWin;
	double newTimeToWin;
	
	fgets(temp, 80, stdin);
	sscanf(temp, "%d", &cases);
	for (currentCase = 1; currentCase <= cases; currentCase++) {
		timeToWin = 0;
		timeToFarm = 0;
		newTimeToWin = 0;
		cookieRatio = 2;
		
		fgets(temp, 80, stdin);
		sscanf(temp, "%lf %lf %lf", &C, &F, &X);
		
		timeToWin = X/cookieRatio;
		while(1) {
			timeToFarm += C/cookieRatio;
			//printf("Time to farm is: %f", timeToFarm);
			cookieRatio += F;
			//printf("Cookie ratio increased to %f", cookieRatio);
			newTimeToWin = timeToFarm + X/cookieRatio;
			
			if (newTimeToWin < timeToWin) {
				timeToWin = newTimeToWin;
			}
			else {
				break;
			}
		}
		
		printf("Case #%d: %1.7lf\n", currentCase, timeToWin);
	}
	return 0;
}