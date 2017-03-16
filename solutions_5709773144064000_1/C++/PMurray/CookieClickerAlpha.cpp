#include<iostream>
#include<fstream>
#include<string>

using namespace std;

long double TimeToWin(long double C, long double F, long double X) {

//	long double X = 2000.0;
	long double seconds = 0;

	long double currentIncome = 2;

	long double timeUntilWin;
	long double timeUntilCookie;
	long double timeToWinWithCookie;

	while (true) {
		timeUntilWin = X / currentIncome;

		timeUntilCookie = C / currentIncome;
		timeToWinWithCookie = timeUntilCookie + X / (currentIncome + F);
		if (timeUntilWin < timeToWinWithCookie) {
			return seconds + timeUntilWin;
		}
		seconds += timeUntilCookie;
		currentIncome += F;

	}
}


int main() {
	string FILENAME = "B-large.in";
	string OUT_FILENAME = "output.out";

	ifstream inputfile;
	inputfile.open(FILENAME);
	int testCases;
	ofstream outfile;
	outfile.open(OUT_FILENAME);
	outfile.precision(10);

	long double X = 2000.0;

	long double F = 4.0;
	long double C = 500.0;
	long double currentIncome = 2;

	inputfile >> testCases;

	for (int i = 1; i <= testCases; ++i) {
		inputfile >> C;
		inputfile >> F;
		inputfile >> X;
		outfile << "Case #" << i << ": " << fixed << TimeToWin(C, F, X) << endl;
	}

	return 0;

}