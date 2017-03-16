#include<iostream>
#include<fstream>
using namespace std;

int main() {
	ifstream cin("input");
	ofstream cout("output");
	int nLoop;
	int nGoogler;
	int nSurprising;
	int nThreshold;
	int nScore;

	cin >> nLoop;

	for(int i=1; i<=nLoop; ++i) {
		cin >> nGoogler >> nSurprising >> nThreshold;
		int upperBound = nThreshold*3 - 2;
		int lowerBound = nThreshold*3 - 5;
		if(nThreshold==0) lowerBound = -1;
		if(nThreshold==1) lowerBound = 0;

		int nCount = 0;
		int nCandidate = 0;
		for(int j=1; j<=nGoogler; ++j) {
			cin >> nScore;
			if(nScore <= lowerBound) continue;
			if(nScore >= upperBound) ++nCount;
			else ++nCandidate;
		}
		int tmp = (nCandidate>=nSurprising) ? nCount+nSurprising : nCount+nCandidate;
		cout<<"Case #"<<i<<": "<< tmp << endl;
	}
	//system("pause");
}
