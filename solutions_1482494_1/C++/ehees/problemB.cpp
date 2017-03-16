#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

int main() {
	int numCases;
	cin >> numCases;
	for(int caseNo = 1; caseNo <= numCases; caseNo++) {
		int numLevels;
		cin >> numLevels;
		int levelReqs[numLevels][2];
		int stars[numLevels];

		for(int i = 0; i < numLevels; i++) {
			scanf("%d %d", &levelReqs[i][0], &levelReqs[i][1]);
			stars[i] = 0;
		}
		int totalstars = 0;
		int gamesPlayed = 0;
		while(totalstars < numLevels * 2) {
			int prevstars = totalstars;
			int candidate = -1;
			for(int i = 0; i < numLevels; i++) {
				if(levelReqs[i][1] <= totalstars && stars[i] < 2) {
					totalstars += 2 - stars[i];
					stars[i] = 2;
					candidate = -1;
					break;
				}
				else if(levelReqs[i][0] <= totalstars && stars[i] < 1 && 
						(candidate == -1 || levelReqs[candidate][1] < levelReqs[i][1])) {
					candidate = i;
				}

			}
			if(candidate == -1) {
				gamesPlayed++;
				if(prevstars == totalstars) {
					printf("Case #%d: Too Bad\n", caseNo);
					break;
				}
			}
			else {
				gamesPlayed++;
				stars[candidate] = 1;
				totalstars++;
			}
		}
		if(totalstars == numLevels * 2)
			printf("Case #%d: %d\n", caseNo, gamesPlayed);
	}
}
