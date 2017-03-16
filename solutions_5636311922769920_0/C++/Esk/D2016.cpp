#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]){

	ifstream input(argv[1]);

	int nCases;
	input >> nCases;

	for(int i=0; i<nCases; i++){

		cout << "Case #" << i+1 << ": "; 

		int K;
		input >> K;
		int C;
		input >> C;
		int S;
		input >> S;

		//Handles K=S only!!!
		unsigned long long KC_1 = pow(K,C-1); 
		for(int j=0; j<=K-1; j++){
			cout << j*KC_1+1;
			if(j!=K-1){
				cout << " ";
			}		
		}
		cout << endl;
	
	} 

	return 0;
}