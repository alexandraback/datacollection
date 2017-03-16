#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string basePath = "../data/2014_QR";
	string baseName = "D-small-attempt0";
	string inFile = basePath + "/" + baseName + ".in";
	string outFile = basePath + "/" + baseName + "-out.txt";
	ifstream ifs(inFile.c_str(), ifstream::in);
	ofstream ofs(outFile.c_str(), ofstream::out);

	int numTest(0), idxTest(1);
	ifs >> numTest;
	cout << numTest << endl;

	while(idxTest <= numTest) {
		int N, scoreWar(0), scoreDWar(0);
		ifs >> N;
		double * wNaomi = new double [N];
		double * wKen = new double [N];
		
		for (int i = 0; i < N; i++)
			ifs >> wNaomi[i];
		for (int i = 0; i < N; i++)
			ifs >> wKen[i];
		
		// play war
		vector<double> tmpKen;
		bool * usedKen = new bool [N];
		for (int i = 0; i < N; i++) {
			tmpKen.push_back(wKen[i]);
			usedKen[i] = false;
		}

		sort(tmpKen.begin(), tmpKen.end());

		for (int i = 0; i < N; i++) {			
			int winKen(0);
			for (int j = 0; j < N; j++) {
				if (!usedKen[j] && tmpKen[j] > wNaomi[i]) {
					winKen = 1;	
					usedKen[j] = true;
					break;					
				}
			}

			if (!winKen) {
				++scoreWar;
				int tmpIdx = 0;
				while (usedKen[tmpIdx])	tmpIdx++;						
				usedKen[tmpIdx] = true;
			}
		}

		// play D war
		vector<double> tmpNaomi;
		for (int i = 0; i < N; i++) {
			tmpNaomi.push_back(wNaomi[i]);
			usedKen[i] = false;
		}

		sort(tmpNaomi.begin(), tmpNaomi.end());

		for (int i = 0; i < N; i++) {			
			int winKen(0);
			
			for (int j = 0; j < N; j++) {
				if (!usedKen[j]) {
					if (tmpNaomi[i] < tmpKen[j]) {
						winKen = 1;	
						int tmpIdx = N-1;
						while (usedKen[tmpIdx])	tmpIdx--;						
						usedKen[tmpIdx] = true;
					}
					else
						usedKen[j] = true;

					break;
				}
			}

			if (!winKen)
				++scoreDWar;
		}

		// output
		ofs << "Case #" << idxTest << ": " << scoreDWar << " " << scoreWar << endl;
		++idxTest;

		delete[] usedKen;
		delete[] wKen;
		delete[] wNaomi;
	}

	ifs.close();
	ofs.close();
	getchar();
	return 0;
}