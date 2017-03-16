#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	string basePath = "../data/2014_QR";
	string baseName = "B-small-attempt0";
	string inFile = basePath + "/" + baseName + ".in";
	string outFile = basePath + "/" + baseName + "-out.txt";
	ifstream ifs(inFile.c_str(), ifstream::in);
	ofstream ofs(outFile.c_str(), ofstream::out);

	int numTest(0), idxTest(1);
	ifs >> numTest;
	cout << numTest << endl;

	while(idxTest <= numTest) {
		int nFarm(0);	
		double C, F, X, tCookie(0.0), tTime(0.0), gRate(2.0);
		ifs >> C >> F >> X;

		while (tCookie < X) {
			double tmpRate1 = gRate + nFarm*F;
			double tmpRate2 = tmpRate1 + F;

			double t1 = X/tmpRate1;
			double t2 = C/tmpRate1;
			double t3 = t2 + X/tmpRate2;

			if (t1 <= t3) {
				tCookie = X;
				tTime += t1;
			}
			else {
				nFarm++;
				tTime += t2;
			}
		}

		ofs << "Case #" << idxTest << ": " << fixed << setprecision(7) << tTime << endl;
		++idxTest;
	}

	ifs.close();
	ofs.close();
	getchar();
	return 0;
}