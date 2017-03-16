#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char ** argv){
    int numberOfTest;

    double C;
    double F;
    double sF;
    double X;

    vector <int> answers;
    vector <int> answers2;

    double current;
    double result;

    ifstream inFile;
    ofstream outFile;

    inFile.open(argv[1]);
    outFile.open(argv[2]);

    inFile >> numberOfTest;
    
    outFile.setf(ios::fixed, ios::floatfield);

    for(int count = 0 ; numberOfTest > count ; count++){
	inFile >> C;
	inFile >> F;
	inFile >> X;

	result = X;
	current	= X/2.;
	sF  = 0.;

	for(int count2 = 1 ; (100000 > count2) && (current < result) ; count2++){
	    result = current;

	    current  = X / (2. + F * static_cast<double>(count2));

	    sF	+= C /(2. + F * static_cast<double>(count2-1));

	    current += sF;
	}

	outFile << "Case #" << count+1 << ": ";


	outFile.precision(7);
	outFile << result << endl;

    }

    inFile.close();
    outFile.close();

    return EXIT_SUCCESS;
}



