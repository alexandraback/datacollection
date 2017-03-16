#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

ifstream inFile;
ofstream outFile;
double cps, t;
double cost, benefit, goal;

int main(int argc, char const *argv[]){
	if(argc != 2){
		cout<<"Error in Input"<<endl;
		return 0;
	}
	inFile.open(argv[1]);
	outFile.open("output.txt", ios::trunc | ios::out);
	if(!(inFile.is_open() && outFile.is_open()) ){
		cout << "can't open files"<<endl;
		return 0;
	}

	int N;
	inFile >> N;
	cout << "Running through " << N << " Iterations" << endl;
	for(int count=0; count<N; count++){
		cps = 2;
		t = 0;
		inFile >> cost;
		inFile >> benefit;
		inFile >> goal;

		while(true){
			if( goal/cps < ( (goal/(cps+benefit)) + cost/cps ) ){
				t += goal/cps;
				break;
			}
			t += cost/cps;
			cps += benefit;
		}

		outFile << "Case #" << count+1 << ": ";
		outFile << std::setprecision(7) << std::fixed << t << "\n";

		cout << ".";
	}

	cout << "\n";
	inFile.close();
	outFile.close();
	return 0;
}
