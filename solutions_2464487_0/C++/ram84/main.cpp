#include <iostream>
#include <cmath>
#include <ctime>
#include "Bullseye.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cerr << "Usage: " << argv[0] << " INPUTFILE OUTPUTFILE" << endl;
		return 1;
	}
	Bullseye a(argv[1], argv[2]);
	return 0;
}
