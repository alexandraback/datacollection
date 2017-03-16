// Google code jam 2015
// Qualification round
// Problem No.1: Standing Ovation

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
	ifstream infile("A-large.in");
	ofstream outfile("A-large.out");
	int caseNum;
	infile >> caseNum;
	for (int n = 1; n <= caseNum; ++n){
		int sMax;
		infile >> sMax;
		string shylevel;
		infile >> shylevel;
		int inviteNum = 0;
		int sum = 0;
		for (int i = 0; i < sMax; ++i){
			sum += shylevel[i] - 48;
			if (sum < i + 1){
				inviteNum += i + 1 - sum;
				sum = i + 1;
			}
		}

		outfile << "Case #" << n << ": " << inviteNum << endl;
	}
	infile.close();
	outfile.close();
}