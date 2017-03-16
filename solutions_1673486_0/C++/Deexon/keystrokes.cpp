#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


int main(int argc, char* argv[]){
	int numOfCases, charsSoFar, passLength;
	double* p;
	
	ofstream output;
	ifstream input;
	
	input.open(argv[1]);
	if (!input){
		cout << "Cannot open file "<<argv[1]<<endl;
		return -1;
	}
	cout << "File "<< argv[1] <<" opened for reading" <<endl;

	output.open(argv[2]);
	if (!output){
		cout << "Cannot open file "<<argv[2]<<endl;
		return -1;
	}
	cout << "File "<< argv[2] <<" opened for writing" <<endl;
	

	input>>numOfCases;


	int k=0;
	while(k<numOfCases){
		input>>charsSoFar>>passLength;
		double min;
		p=new double[charsSoFar];
		for(int j=0; j<charsSoFar; j++){
			input>>p[j];
		}
		//continue typing
		double correct=1;
		for(int j=0; j<charsSoFar; j++){
			correct *= p[j]; 
		}
		double expected = correct*(passLength-charsSoFar+1) + (1-correct)*(passLength-charsSoFar+1+passLength+1);
		min=expected;

		//backspaces
		
		for(int j=1; j<=charsSoFar; j++){
			correct=1;
			for(int i=charsSoFar-j-1; i>=0; i--){
				correct *= p[i];
			}
			expected = correct*(j+passLength-(charsSoFar-j)+1) + (1-correct)*(j+passLength-(charsSoFar-j)+1+passLength+1);
			if (expected<min) min=expected;
		}

		//enter straight away
		expected = passLength+2;
		if (expected<min)  min=expected;

		output<<"Case #"<<k+1<<": "<< setprecision(6) <<setiosflags(ios::fixed)<<min<<endl;
		k++;
		delete p;

	}



	cout<<"Work finished"<<endl;
	input.close();
	output.close();

	return 0;


}