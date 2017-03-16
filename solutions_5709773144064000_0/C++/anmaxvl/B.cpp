#include <stdio.h>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main (){
	double c, f, x;
	int t;

	ifstream fin;

	fin.open("B.in");

	FILE *fout;

	fout = fopen("B.out", "w");

	fin>>t;

	for (int test = 1; test<=t; test ++) {
		fin>>c>>f>>x;

		double currentTime = 0;
		double currentIncome = 2;
		double currentFinishTime = x/currentIncome;
		double currentCookies = 0;
		double expectedIncome = 0;
		double expectedFinishTime = 0;

		if (x<=c) {
			currentFinishTime = x/currentIncome;
		}
		else{
			cout<<"Case #"<<test<<endl;
			while(true){
				cout<<currentCookies<<" "<<currentIncome<<endl;
				if (currentCookies + c < x) {
					currentCookies += c;
					currentTime += c/currentIncome;

					expectedIncome = currentIncome + f;
					expectedFinishTime = currentTime + x/expectedIncome;
					currentFinishTime = currentTime + (x - currentCookies)/currentIncome;

					if (currentFinishTime > expectedFinishTime) {
						currentCookies = 0;
						currentIncome = expectedIncome;
					}
				}
				else {
					currentFinishTime = currentTime + (x - currentCookies)/currentIncome;
					break;
				}
			}
		}

		fprintf(fout, "Case #%d: %1.6f\n", test, currentFinishTime);
	}

	fin.close();
	fclose(fout);
	return 0;
}
