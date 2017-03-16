#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){

	ifstream input(argv[1]);

	int nCases;
	input >> nCases;

	for(int i=0; i<nCases; i++){

		std::string pancakes;
		input >> pancakes;

		int flips = 0;
		char prev = 'a';

		for(int p=0; p<pancakes.length(); p++){

			if(prev=='a'){
				prev = pancakes[p];
			}else{
				if(prev != pancakes[p]){
					prev = pancakes[p];
					flips++;
				}
			}
		}

		if(pancakes[pancakes.length()-1]=='-'){
			flips++;
		}

		cout << "Case #" << i+1 << ": " << flips << endl;
	} 

	return 0;
}