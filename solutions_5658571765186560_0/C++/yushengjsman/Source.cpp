// Google code jam 2015
// Qualification round
// Problem No.4: Ominous Omino

#include <fstream>
#include <iostream>
using namespace std;

int main(){
	ifstream infile("D-small-attempt0.in");
	ofstream outfile("small.out");
	int caseNum;
	infile >> caseNum;
	for (int n = 1; n <= caseNum; ++n){
		int X, R, C;
		infile >> X >> R >> C;
		int winFlag = 0; // 0:Richard, 1:Gabriel
		switch (X)
		{
		case 1:
			winFlag = 1;
			break;
		case 2:
			if ((R*C) % 2 == 0){
				winFlag = 1;
			}
			else{
				winFlag = 0;
			}
			break;
		case 3:
			if (R == 1 || C == 1 || (R*C) % 3 != 0){
				winFlag = 0;
			}
			else{
				winFlag = 1;
			}
			break;
		case 4:
			if (R <= 2 || C <= 2 || (R*C) % 4 != 0){
				winFlag = 0;
			}
			else{
				winFlag = 1;
			}
		default:
			break;
		}
		if (winFlag == 0){
			outfile << "Case #" << n << ": RICHARD" << endl;
		}
		else{
			outfile << "Case #" << n << ": GABRIEL" << endl;
		}
	}
	return 0;
}