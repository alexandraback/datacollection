#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
using namespace std;


int main(int argc, char **argv) {
	ifstream infile;
	ofstream outfile;

	assert(argc == 3);
	infile.open(argv[1]);
	if (!infile.is_open()) { cout << "can't open file " << argv[1] << "\n"; exit(1); }
	int numCases;
	infile >> numCases;
	
	outfile.open(argv[2]);
	if (!outfile.is_open()) { cout << "can't open file " << argv[2] << "\n"; exit(1); }
	
	int numGooglers, surprisingScores, scoreToGet, score, count;
	for (int itr=1; itr<=numCases; itr++) {
		infile >> numGooglers >> surprisingScores >> scoreToGet;
//		cout << numGooglers << " " << surprisingScores << " " << scoreToGet << "\n";
		count = 0;
		for (int i=0; i<numGooglers; i++) {
			infile >> score;
//			cout << " " << score;
			int mod = score % 3;
			if (mod == 0) {
				if (score / 3 >= scoreToGet) count++;
				else if (score / 3 + 1 >= scoreToGet && surprisingScores > 0 && score > 0) {
					count++;
					surprisingScores--;
				}
			}
			else if (mod == 1) {
				if (score / 3 + 1 >= scoreToGet) count++;	//having a surprise won't help in this case
			}
			else {	//mod == 2
				if (score / 3 + 1 >= scoreToGet) count++;
				else if (score / 3 + 2 >= scoreToGet && surprisingScores > 0) {
					count++;
					surprisingScores--;
				}
			}
		}
//		cout << "\n";
//		cout << "count is " << count << "\n";
		
		outfile << "Case #" << itr << ": " << count << "\n";
	}
	infile.close();
	outfile.close();
	
	return 0;
}