#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

using namespace std;


int main(int argc, char* argv[]) {
	string inTestName, outTestName, outTestNameDBG;

	cout << "Enter the in test file name : " << endl;
	cin >> inTestName;
	cout << endl;

	cout << "Enter the out test file name : " << endl;
	cin >> outTestName;
	cout << endl;

	outTestNameDBG = outTestName + "dbg.txt";

	/* Open file */
	ifstream inFile(inTestName.c_str());
	if(!inFile.is_open()) {
		cout << "Can't open input file" << endl;
		system("PAUSE");
		return 1;
	}

	ofstream outFile(outTestName.c_str());
	if(!outFile.is_open()) {
		cout << "Can't open output file" << endl;
		system("PAUSE");
		return 1;
	}

	ofstream outFileDBG(outTestNameDBG.c_str());
	if(!outFileDBG.is_open()) {
		cout << "Can't open output file" << endl;
		system("PAUSE");
		return 1;
	}

	int T; /*number of tests */
	inFile >> T;

	for(int t = 0; t < T; t++) {
		int N; /* Number of googlers */
		int S; /* Number of surprising scores */
		int p; /* Best result to achieve */
		vector<int> sum_scores;

		inFile >> N >> S >> p;
		for(int i = 0; i < N; i++)  {
			int sum;
			inFile >> sum;
			sum_scores.push_back(sum);
		}

		/* Analysis :
		 * Let be q = sum/3 and r = sum%3 
		 * There are 3 cases :
		 *  . r = 0 :
		 *		scores can be {q, q, q} or {q-1, q, q+1} (*) : surprising score will be used if q < p and q+1 >= p
		 *	. r = 1 :
		 *      scores can be {q, q, q+1} or {q-1, q+1, q+1} (*) {q-1, q, q+2} is impossible : we won't use surprising score here, no interest
		 *	. r = 2 :
		 *		scores can be {q, q+1, q+1} or {q, q, q+2} (*) : surprising score will be used if q+1 < p and q+2 >= p
		 */
		int total = 0;	/* this is the result, ie number os best result >= p */
		for(int i = 0; i < N; i++)  {
			int q = sum_scores[i]/3;
			int r = sum_scores[i] - 3*q;

			if(r == 0) {
				if(q >= p) {
					total++;
					outFileDBG << sum_scores[i] << ": {" << q << ", " << q << ", " << q << "}(+1) - ";
				}
				else if(q < p && q != 0 && q+1 >= p) {
					if(S > 0) {
						S--;
						total++;
						outFileDBG << sum_scores[i] << ": {" << q-1 << ", " << q << ", " << q+1 << "}(*) - ";
					}
					else {
						outFileDBG << sum_scores[i] << ": {" << q << ", " << q << ", " << q << "} - ";
					}
				}
				else {
					outFileDBG << sum_scores[i] << ": {" << q << ", " << q << ", " << q << "} - ";
				}
			}
			else if(r == 1) {
				if(q+1 >= p) {
					total++;
					outFileDBG << sum_scores[i] << ": {" << q << ", " << q << ", " << q+1 << "}(+1) - ";
				}
				else {
					outFileDBG << sum_scores[i] << ": {" << q << ", " << q << ", " << q+1 << "} - ";
				}
			}
			else if(r == 2) {
				if(q+1 >= p) {
					total++;
					outFileDBG << sum_scores[i] << ": {" << q << ", " << q+1 << ", " << q+1 << "}(+1) - ";
				}
				else if(q+1 < p && q+2 >= p) {
					if(S > 0) {
						S--;
						total++;
						outFileDBG << sum_scores[i] << ": {" << q << ", " << q << ", " << q+2 << "}(*) - ";
					}
					else {
						outFileDBG << sum_scores[i] << ": {" << q << ", " << q+1 << ", " << q+1 << "} - ";
					}
				}
				else {
					outFileDBG << sum_scores[i] << ": {" << q << ", " << q+1 << ", " << q+1 << "} - ";
				}
			}
		}
		outFileDBG << endl;
		/* Write result */
		outFile << "Case #" << t+1 << ": " << total << endl;
	}

	outFileDBG.close();
	outFile.close();
	inFile.close();

	system("PAUSE");
	return 0;
}

