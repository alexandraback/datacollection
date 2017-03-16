#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

unsigned long long bigpow(unsigned long long base, int power){
	unsigned long long res = 1;
	for(int i=1; i<=power; i++){
		res*=base;
	}
	return res;
}

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

		if(S==K){

			for(int j=1; j<=K; j++){
				cout << j;
				if(j!=K){
					cout << " ";
				}		
			}
			cout << endl;
		
		}else{

			//S < K
			int testsNeeded = (K/C);
			if(K%C!=0){
				testsNeeded+1;
			}

			if(S < testsNeeded){
				cout << "IMPOSSIBLE" << endl;
			}else{

				//cout << "POSSIBLE" << endl;
				int level = 1;
				unsigned long long position = 0;

				for(int p=1; p<=K; p++){
					position += (p-1)*bigpow(K,C-level);
					level++;
					if(level>C || p==K){
						cout << position+1 << " ";
						level = 1;
						position = 0;
					}
				}

				cout << endl;
			}

		}
	
	} 

	return 0;
}