#include <cstdio>
#include <cmath>
#include <vector>

// Not working

using namespace std;

const int maxDist = 100;
const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 49, -1};

inline int calcDist(int x1, int y1, int x2, int y2) {
	return ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

inline bool checkAndMark(int i1, int j1, int i2, int j2, vector<bool> * clonePossible, int cloneSize) {
	if (clonePossible[i2][j2] == false)
		return false;
	
	int di = i2 - i1, dj = j2 - j1;
	
	for (int i=0; primes[i] != -1; i++) {
		while (di%primes[i] == 0 and dj%primes[i] == 0) {
			di /= primes[i];
			dj /= primes[i];
		}
	}
	
	int pi = i2, pj = j2;
	while (pi >= 0 and pi < cloneSize and pj >= 0 and pj < int(clonePossible[pi].size())) {
		clonePossible[pi][pj] = false;
		pi += di;
		pj += dj;
	}
	
	//printf("Ponto: % 3d % 3d\n", i2, j2);
	
	return true;
}

int main() {
	int T, I;
	scanf("%d",&T);
	
	for (I=1; I<=T; I++) {
		int count = 0;
		int lines, cols, dist;
		scanf("%d %d %d", &lines, &cols, &dist);
		dist *= dist;
		
		char array[lines][cols+1];
		int posI, posJ, othI, othJ;
		for (int i=0; i<lines; i++) {
			scanf("%s", array[i]);
			for (int j=0; j<cols; j++) {
				if (array[i][j] == 'X') {
					// Ignore walls
					posI = i - 1;
					posJ = j - 1;
				}
			}
		}
		// Once again, ignore walls
		lines -= 2;
		cols -= 2;
				
		// The idea of the algorithm is that the mirrors create clones of the X
		// The algorithm assumes no obstacles, only mirrors in the wall
		
		// Allocate enough room for all the clones
		vector<bool> clonePossible[maxDist*2+lines];
		for (int i=0; i<maxDist*2+lines; i++)
			clonePossible[i].resize(maxDist*2+cols, true);
		
		// Center on [maxDist, maxDist]
		posI += maxDist;
		posJ += maxDist;
		
		// Up - mirror on maxDist - 0.5
		othJ = posJ;
		othI = posI + 2*(maxDist - posI) - 1;
		if (calcDist(posI, posJ, othI, othJ) <= dist)
			count ++;
			
		// Down - mirror on maxDist+lines-0.5
		othJ = posJ;
		othI = posI + 2*(maxDist+lines - posI) - 1;
		if (calcDist(posI, posJ, othI, othJ) <= dist)
			count ++;
			
		// Left - mirror on maxDist-0.5
		othI = posI;
		othJ = posJ + 2*(maxDist - posJ) - 1;
		if (calcDist(posI, posJ, othI, othJ) <= dist)
			count ++;
			
		// Right - mirror on maxDist+cols
		othI = posI;
		othJ = posJ + 2*(maxDist+cols - posJ) - 1;
		if (calcDist(posI, posJ, othI, othJ) <= dist)
			count ++;
		
		bool usedI = true, usedJ = true;
		for (int i=1; usedI; i++) {
			// Down
			if (i%2==0)
				othI = posI + lines*i;
			else {
				// Use previous calculations to go to point above and then descend
				othI = posI + 2*(maxDist - posI) - 1 + lines*(i+1);
			}
			
			usedI = false;
			if (othI <= posI + maxDist) {
				usedI = true;
				usedJ = true;
				for (int j=1; usedJ; j++) {
					// Right
					if (j%2==0)
						othJ = posJ + cols*j;
					else {
						// Use previous calculations to go to point above and then descend
						othJ = posJ + 2*(maxDist - posJ) - 1 + cols*(j+1);
					}
					
					usedJ = false;
					if (calcDist(posI, posJ, othI, othJ) <= dist) {
						//printf("Ponto DR (%d, %d)\n", othI, othJ);
						if (checkAndMark(posI, posJ, othI, othJ, clonePossible, maxDist*2+lines))
							count++;
						usedJ = true;
					}
						
					othJ -= 2*j*cols;
					
					if (calcDist(posI, posJ, othI, othJ) <= dist) {
						//printf("Ponto DL (%d, %d)\n", othI, othJ);
						if (checkAndMark(posI, posJ, othI, othJ, clonePossible, maxDist*2+lines))
							count++;
						usedJ = true;
					}
				}
			}
			
			// Up
			othI -= 2*i*lines;
			if (othI >= posI - maxDist) {
				usedI = true;
				usedJ = true;
				for (int j=1; usedJ; j++) {
					// Right
					if (j%2==0)
						othJ = posJ + cols*j;
					else {
						// Use previous calculations to go to point above and then descend
						othJ = posJ + 2*(maxDist - posJ) - 1 + cols*(j+1);
					}
					
					usedJ = false;
					if (calcDist(posI, posJ, othI, othJ) <= dist) {
						//printf("Ponto UR (%d, %d)\n", othI, othJ);
						if (checkAndMark(posI, posJ, othI, othJ, clonePossible, maxDist*2+lines))
							count++;
						usedJ = true;
					}
						
					othJ -= 2*j*cols;
					
					if (calcDist(posI, posJ, othI, othJ) <= dist) {
						//printf("Ponto UL (%d, %d)\n", othI, othJ);
						if (checkAndMark(posI, posJ, othI, othJ, clonePossible, maxDist*2+lines))
							count++;
						usedJ = true;
					}
				}
			}
		}
		
		printf("Case #%d: %d\n", I, count);
	}
	return 0;
}
