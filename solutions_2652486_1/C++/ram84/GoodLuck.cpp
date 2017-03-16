#include <cmath>
#include <ctime>
#include <cstdlib>
#include "GoodLuck.h"

using namespace std;

GoodLuck::GoodLuck() {
}

GoodLuck::GoodLuck(char* inputFile, char* outputFile) {

	ifstream fileIn(inputFile);
	if (fileIn.fail()) {
		throw GoodLuckException("File cannot be read.");
	}

	fileOut = fopen(outputFile, "w");
	if (fileOut == NULL) {
		throw GoodLuckException("File cannot be written.");
	}
	
	string line;
	getline(fileIn, line);
	getline(fileIn, line);
	fprintf(fileOut, "Case #1:\n");
	int tic = clock();
	analyze(fileIn);
	int toc = clock() - tic;
	cout << "The GoodLuck took " << (double)toc / CLOCKS_PER_SEC << " seconds to compute and write " << R << " cases." << endl;
	fileIn.close();
}

GoodLuck::~GoodLuck() {
	fclose(fileOut);
}

void GoodLuck::readFile(ifstream& fileIn) {
	string line;
	int i;
	cout << "In readFile() " << endl;
	for (i=0; i<K-1; i++) {
		getline(fileIn, line, ' ');
		products[i] = atol(line.c_str());
	}
	getline(fileIn, line);
	products[K-1] = atol(line.c_str());
}

int GoodLuck::computeOneCase() {
	int dig=0;
	int i, j;
	for (j=0; j<K; j++) {
		/*for (i=0; i<dig; i++) {
			if (products[j] % digits[i] == 0) {
				products[j] /= digits[i];
		}*/
		if (products[j] % 2 == 0 /* && products[j] % 4 != 0 */ && dig < N) {
			digits[dig] = 2;
			dig++;
			products[j] /= 2;
		}
		if (products[j] % 3 == 0 /* && products[j] % 6 != 0 */ && dig < N) {
			digits[dig] = 3;
			dig++;
			products[j] /= 3;
		}
		if (products[j] % 4 == 0 /* && products[j] % 8 != 0 */ && dig < N) {
			digits[dig] = 4;
			dig++;
			products[j] /= 4;
		}
		if (products[j] % 5 == 0 && dig < N) {
			digits[dig] = 5;
			dig++;
			products[j] /= 5;
		}
		if (products[j] % 6 == 0 && dig < N) {
			digits[dig] = 6;
			dig++;
			products[j] /= 6;
		}
		if (products[j] % 7 == 0 && dig < N) {
			digits[dig] = 7;
			dig++;
			products[j] /= 7;
		}
		if (products[j] % 8 == 0 && dig < N) {
			digits[dig] = 8;
			dig++;
			products[j] /= 8;
		}
		if (dig >= N)
			break;
	}
}

void GoodLuck::analyze(ifstream& fileIn) {
	int i;
	for (i=0; i<K; i++) 
		digits[i] = 2;
	for (i=0; i<R; i++) {
		cout << "On case " << i << endl;
		readFile(fileIn);
		cout << "products are " << products[0] << products[1] << products[2] << products[3] << endl;
		computeOneCase();
		writeFile();
	}
}
	
void GoodLuck::writeFile() const {
	int i;
	for (i=0; i<N; i++) {
		fprintf(fileOut, "%d", digits[i]);
	}
	fprintf(fileOut, "\n");
}
