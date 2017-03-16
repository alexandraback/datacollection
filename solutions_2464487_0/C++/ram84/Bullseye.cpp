#include <cmath>
#include <ctime>
#include <cstdlib>
//#include <thread>
#include "Bullseye.h"

using namespace std;

Bullseye::Bullseye() {
	numCases = 0;
}

Bullseye::Bullseye(char* inputFile, char* outputFile) {

	ifstream fileIn(inputFile);
	if (fileIn.fail()) {
		throw BullseyeException("File cannot be read.");
	}

	fileOut = fopen(outputFile, "w");
	if (fileOut == NULL) {
		throw BullseyeException("File cannot be written.");
	}
	
	string line;
	getline(fileIn, line);
	numCases = atoi(line.c_str());
	
	radius = new long[numCases];
	volume = new long[numCases];
	numRings = new long[numCases];
	
	int tic = clock();
	readFile(fileIn);
	analyze();
	writeFile();
	int toc = clock() - tic;
	cout << "The Bullseye took " << (double)toc / CLOCKS_PER_SEC << " seconds to compute and write " << numCases << " cases." << endl;
	fileIn.close();
}

Bullseye::~Bullseye() {
	delete[] radius;
	delete[] volume;
	delete[] numRings;
	fclose(fileOut);
}

void Bullseye::readFile(ifstream& fileIn) {
	string line;
	int i;
	cout << "In readFile() " << endl;
	for (i=0; i<numCases; i++) {
		getline(fileIn, line, ' ');
		radius[i] = atol(line.c_str());
		getline(fileIn, line);
		volume[i] = atol(line.c_str());
	}
}

long Bullseye::computeOneCase(long r, long t) const {
	long i;
	long rings = 0;
	for (i=r; t>=0; i+=2) {
		t -= (2*i+1);
		rings++;
	}
	return rings - 1;
}

void Bullseye::analyze() {
	int i;
	for (i=0; i<numCases; i++) {
		cout << "On case " << i << ": radius " << radius[i] << ", volume " << volume[i] << endl;
		numRings[i] = computeOneCase(radius[i], volume[i]);
	}
}
	
void Bullseye::writeFile() const {
	int i;
	for (i=0; i<numCases; i++) {
		fprintf(fileOut, "Case #%d: %ld\n", i+1, numRings[i]);
	}
}
