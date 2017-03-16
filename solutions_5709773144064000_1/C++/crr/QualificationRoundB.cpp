//============================================================================
// Name        : QualificationRoundB.cpp
// Author      : crr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main() {
	int nCase;
	ifstream fin("B-large.in");
	ofstream fout("B-large.out");
	fin >> nCase;
	cout << nCase << endl;
	bool isFirstCase = true;
	for(int iCase=0;iCase<nCase;iCase++)
	{
		if(isFirstCase)
			isFirstCase = false;
		else
			fout<<endl;
		fout<<"Case #"<<iCase+1<<": ";

		double C,F,X;
		fin>>setprecision(6)>>C>>F>>X;

		fout.setf(ios::fixed);
		cout.setf(ios::fixed);
		cout<<setprecision(7)<<C<<","<<F<<","<<X<<endl;

		int nBuy = 0;
		int minBuy=0,maxBuy=0;
		double min = numeric_limits<double>::max();
		do{
			double time = 0;
			for(int i=0;i<nBuy;i++)
			{
				time += C/(2+i*F);
			}
			time += X/(2+nBuy*F);
//			cout << "nBuy = " << nBuy << " time= " << time << endl;

			if(time < min)
				min = time;
			else{
				cout << min << endl;
				fout <<setprecision(7)<< min;
				break;
			}
//			if(nBuy>10)	break;

			nBuy ++;
		}while(true);

		cout << "============================================" << endl;
	}

	return 0;
}
