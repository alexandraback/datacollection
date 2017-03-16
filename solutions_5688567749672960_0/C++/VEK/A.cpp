#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

typedef long long unsigned lluint;

lluint min(lluint a, lluint b) {return (a<b)?a:b;}
lluint max(lluint a, lluint b) {return (a>b)?a:b;}

using namespace std;

unsigned int testNum, maxNum;

lluint rev(lluint num) {
	lluint ret = 0;
	while (num) {
		ret *= 10;
		ret +=  num%10;
		num /= 10;
	}
	return ret;
}

lluint invrev(lluint num) {
	if (!(num%10)) return 0;
	lluint ret = 0;
	while (num) {
		ret *= 10;
		ret +=  num%10;
		num /= 10;
	}
	return ret;
}

/*lluint solve() {
	lluint numCount = 1, currentNum = 1;
	while (currentNum < maxNum) {
		lluint nextOneZeroNine = 19;
		while (nextOneZeroNine < currentNum) {
			nextOneZeroNine -= 9;
			nextOneZeroNine *= 10;
			nextOneZeroNine += 9;
		}
		if ((rev(nextOneZeroNine) > maxNum || rev(currentNum) <= nextOneZeroNine)
		  && rev(currentNum) > currentNum && rev(currentNum) < maxNum) {
			currentNum = rev(currentNum);
		} else if (rev(nextOneZeroNine) <= maxNum && currentNum == nextOneZeroNine) {
			currentNum = rev(currentNum);
		} else currentNum++;
		cout << "|" << currentNum << endl;
		numCount++;
	}
	return numCount;
}*/

#define MAX 1000001
lluint shortest[MAX];

int main(int argc, char **argv) {
	shortest[1] = 1;
	for (lluint i = 1; i < MAX; i++) {
		if (invrev(i) < i && invrev(i) != 0)
			shortest[i] = min(shortest[i-1]+1, shortest[invrev(i)]+1);
		else shortest[i] = shortest[i-1]+1;
		//if (i < 100) cout << i << ": " << shortest[i] << " " << invrev(i) << endl;
	}
	ifstream ifile("A-small-attempt3.in");
	FILE *ofile = fopen("out.txt", "w");
	ifile >> testNum;
	for (unsigned i = 0; i < testNum; i++) {
		ifile >> maxNum;
		fprintf(ofile, "Case #%d: %lld\n", i+1, shortest[maxNum]);
		printf("Case #%d: %lld\n", i+1, shortest[maxNum]);
	}
	ifile.close();
	fclose(ofile);
	return 0;
}
