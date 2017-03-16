#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <new>
#include <cassert>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

struct starSort {
	int level;
	int stars;
};

bool mySortFunc(starSort i, starSort j) { return (i.stars < j.stars); }



int main(int argc, char **argv) {
	if (argc!=3) {
		cerr << "provide input and output file names as the first 2 command line parameters\n";
		exit(1);
	}
	if (strcmp(argv[1], argv[2])==0) {
		cerr << "don't use the same input and output file names\n";
		exit(1);
	}
	
	ifstream infile;
	ofstream outfile;
	
	infile.open(argv[1]);
	if (!infile.is_open()) {
		cerr << "can't open file " << argv[1] << " for reading\n";
		exit(1);
	}
	
	outfile.open(argv[2]);
	if (!outfile.is_open()) {
		cerr << "can't open file " << argv[2] << " for writing\n";
		exit(1);
	}
	
	int numCases;
	int i, j, k, levels, twoStarIndex, starCount, levelCount;
	int *twoStarOriginal;
	starSort *oneStar, *twoStar;
	oneStar = new starSort [2000];
	twoStar = new starSort [2000];
	twoStarOriginal = new int [2000];
	
	char *levelsPlayed;
	levelsPlayed = new char[2000];
	
	int levelCandidate;
	
	infile >> numCases;
	for (int caseNum = 1; caseNum <= numCases; caseNum++) {
		infile >> levels;
		for (i=0; i<levels; i++) {
			infile >> j >> k;
			oneStar[i].level = i;
			oneStar[i].stars = j;
			twoStar[i].level = i;
			twoStar[i].stars = k;
			twoStarOriginal[i] = k;
		}
		
		sort(&(oneStar[0]), &(oneStar[levels]), mySortFunc);
		sort(&(twoStar[0]), &(twoStar[levels]), mySortFunc);
		
	//	for (i=0; i<levels; i++) cout << " " << twoStar[i].level;
	//	cout << "\n";
		
		
		outfile << "Case #" << caseNum << ": ";
	//	cout << "\n\n";
		
		//strategy: play a two-star if you can, otherwise play a one-star, otherwise impossible
		//play the cheapest level first, if not already played
		
		for (i=0; i<levels; i++) levelsPlayed[i] = 0;
		twoStarIndex = 0;
		starCount = 0;
		levelCount = 0;
		while (starCount < 2*levels) {
			if (twoStarIndex<levels && levelsPlayed[ twoStar[twoStarIndex].level ] < 2 && twoStar[twoStarIndex].stars <= starCount) {	//not played as 2 star and playable
				if (levelsPlayed[ twoStar[twoStarIndex].level ]==0) starCount += 2;	//never played
				else starCount++;			//played as 1 star earlier
				levelsPlayed[ twoStar[twoStarIndex].level ] = 2;
		//		cout << "play 2 star on level " << twoStar[twoStarIndex].level << "\n";
				twoStarIndex++;
				levelCount++;
			}
			//if we can't play 2 star, among the feasible 1 star, play the one with the highest corresponding 2 star
			else {
				i = 0;
				j = 0;	//highest 2 star partner
				k = -1;	//level to play
				while (i < levels) {
					if (oneStar[i].stars > starCount) break;	//can't play here or beyond
					levelCandidate = oneStar[i].level;
					if (levelsPlayed[levelCandidate] == 0 && twoStarOriginal[levelCandidate] > j) {
						j = twoStarOriginal[levelCandidate];
						k = levelCandidate;
					}
					i++;
				}
				if (k==-1) {	//can't play anything
					outfile << "Too Bad\n";
					goto bypass;
				}
				starCount++;
				levelsPlayed[k] = 1;	//play level k as 1 star
		//		cout << "play 1 star on level " << k << "\n";
				levelCount++;
			}
		}
		outfile << levelCount << "\n";
		
		bypass:;
	}
	infile.close();
	outfile.close();
	
	
	return 0;
}
