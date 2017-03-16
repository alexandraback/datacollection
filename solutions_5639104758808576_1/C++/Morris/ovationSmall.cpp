#include <cstdio>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[]){
  ifstream infile(argv[1]);
	ofstream outfile("output");
  string line;
  getline(infile, line);
	int numTrials = stoi(line);
	for (int i = 1; i <= numTrials; i++){
		int k;
		string c;
		infile >> c;
		k = stoi(c);
		infile >> c;
		int deficiency = 0;
		int sum = c[0] - '0';
		int maxDeficiency = 0;
		for(int j = 1; j <= k; j++){
		  deficiency += 1;
			deficiency -= (c[j-1] - '0');
			if(deficiency > maxDeficiency) maxDeficiency = deficiency;
		}
		outfile << "Case #" << i << ": ";
		outfile << maxDeficiency << endl;
	}
	outfile.close();
	return 0;
}
