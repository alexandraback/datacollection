#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <iomanip.h>

int main()
{
	/*
	T=Number of test cases
	C=Cookies to buy a farm
	F=Increase in cookie production per farm
	X=Total cookie required
	*/

	int T;
	double C, F, X, time, perSecond, timeNext;
	ifstream input;
	ofstream output;
	input.open("input.in");
	output.open("output.txt");
	input>>T;
	for (int l = 1; l <= T; l++) {
		input>>C>>F>>X;
		perSecond=2;
		timeNext=X/perSecond;
		if (C>=X) {
			time=X/2;
			output<<"Case #"<<l<<": "<<fixed<<setprecision(7)<<time<<"\n";
		}
		else {
			do {
				time=timeNext;
				timeNext=time-(X/perSecond)+(C/perSecond)+(X/(perSecond+F));
				perSecond+=F;
			}while(time>timeNext);
			output<<"Case #"<<l<<": "<<fixed<<setprecision(7)<<time<<"\n";
        }
	}
	input.close();
	output.close();
	getch();
	return 0;
}


