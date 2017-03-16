// Google code jam 2015
// Qualification round
// Problem No.2: Infinite House of Pancakes

#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

int main(){
	ifstream infile("B-small-attempt1.in");
	ofstream outfile("small1.out");
	int caseNum;
	infile >> caseNum;
	for (int n = 1; n <= caseNum; ++n){
		int D;
		infile >> D;
		int* PArray = new int[D];
		int maxNum = 0;
		for (int i = 0; i < D; ++i){
			infile >> PArray[i];
			if (maxNum < PArray[i])
				maxNum = PArray[i];
		}
		int minutes = maxNum;
		int size = 2;
		while (size < minutes){
			int tempTime = size;
			for (int i = 0; i < D; ++i){
				tempTime += (PArray[i] - 1) / size;
			}
			if (tempTime < minutes)
				minutes = tempTime;
			size++;
		}
		outfile << "Case #" << n << ": " << minutes << endl;

	}
	infile.close();
	outfile.close();
	return 0;
}