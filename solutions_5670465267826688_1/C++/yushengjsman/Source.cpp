// Google code jam 2015
// Qualification round
// Problem No.3: Dijkstra

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	ifstream infile("C-large.in");
	ofstream outfile("large.out");
	int multiplyTable[4][4] = {0,1,2,3, 1,0,3,2, 2,3,0,1, 3,2,1,0};
	int multiplySign[4][4] =  {1,1,1,1, 1,-1,1,-1, 1,-1,-1,1, 1,1,-1,-1};
	int divisionTable[4][4] = {0,1,2,3, 1,0,3,2, 2,3,0,1, 3,2,1,0};
	int divisionSign[4][4] =  {1,-1,-1,-1, 1,1,1,-1, 1,-1,1,1, 1,1,-1,1};
	int divisionTable_k[4][4] = {0,1,2,3, 1,0,3,2, 2,3,0,1, 3,2,1,0};
	int divisionSign_k[4][4] = {1,-1,-1,-1, 1,1,-1,1, 1,1,1,-1, 1,-1,1,1};

	int caseNum;
	infile >> caseNum;
	for (int n = 1; n <= caseNum; ++n){
		int L;
		long long X;
		vector<int> mVec;
		vector<int> signVec;
		vector<int> mVec_k;
		vector<int> signVec_k;
		infile >> L >> X;
		string s;
		infile >> s;
		vector<int> LVec;
		for (int i = 0; i < L; ++i){
			switch (s[i])
			{
			case 'i':
				LVec.push_back(1);
				break;
			case 'j':
				LVec.push_back(2);
				break;
			case 'k':
				LVec.push_back(3);
				break;
			default:
				break;
			}
		}
		int mTemp = 0;
		int sTemp = 1;
		for (int i = 0; i < L; ++i){
			int mTempOld = mTemp;
			mTemp = multiplyTable[mTemp][LVec[i]];
			sTemp = sTemp * multiplySign[mTempOld][LVec[i]];
			mVec.push_back(mTemp);
			signVec.push_back(sTemp);
		}
		// i*j*k = -1
		int total;
		int totalSign;
		int r = X % 4;
		switch (r)
		{
		case 0:
			total = 0;
			totalSign = 1;
			break;
		case 1:
			total = mVec.back();
			totalSign = signVec.back();
			break;
		case 2:
			total = 0;
			totalSign = -1;
			if (mVec.back() == 0){
				totalSign = 1;
			}
			break;
		case 3:
			total = mVec.back();
			totalSign = -signVec.back();
			if (mVec.back() == 0){
				totalSign = signVec.back();
			}
			break;
		default:
			break;
		}
		
		if (!(total == 0 && totalSign == -1)){
			outfile << "Case #" << n << ": NO" << endl;
			continue;
		}

		// find smallest idx for "i" from the head
		int iIdx = 4 * L;
		for (int i = 0; i < L; i++){
			int tTemp = mVec[i];
			int sTemp = signVec[i];
			if (tTemp == 1 && sTemp == 1){
				if (iIdx > i){
					iIdx = i;
				}
			}
			if (tTemp == divisionTable[1][mVec.back()] && sTemp == divisionSign[1][mVec.back()] * signVec.back()){
				if (iIdx > i + L){
					iIdx = i + L;
				}
			}
			if (tTemp == 1 && sTemp == -1 && mVec.back() != 0){ // if...
				if (iIdx > i + L*2){
					iIdx = i + L*2;
				}
			}
			if (tTemp == divisionTable[1][mVec.back()] && sTemp == -divisionSign[1][mVec.back()] * signVec.back() && mVec.back() != 0){
				if (iIdx > i + L*3){
					iIdx = i + L*3;
				}
			}
		}

		// find the smallest idx for "k" from the tail
		int tTemp_k = 0;
		int sTemp_k = 1;
		int kIdx = 4 * L;

		for (int i = 0; i < L; i++){
			int tTemp_k_old = tTemp_k;
			tTemp_k = multiplyTable[LVec[L - 1 - i]][tTemp_k];
			sTemp_k = multiplySign[LVec[L - 1 - i]][tTemp_k_old];
			if (tTemp_k == 3 && sTemp_k == 1){
				if (kIdx > i){
					kIdx = i;
				}
			}
			if (tTemp_k == divisionTable_k[3][mVec.back()] && sTemp_k == divisionSign_k[3][mVec.back()] * signVec.back()){
				if (kIdx > i + L){
					kIdx = i + L;
				}
			}
			if (tTemp_k == 3 && sTemp_k == -1 && mVec.back() != 0){ // if ...
				if (kIdx > i + L * 2){
					kIdx = i + L * 2;
				}
			}
			if (tTemp_k == divisionTable_k[3][mVec.back()] && sTemp_k == -divisionSign_k[3][mVec.back()] * signVec.back() && mVec.back() != 0){
				if (kIdx > i + L * 3){
					kIdx = i + L * 3;
				}
			}
		}

		if (iIdx == 4 * L || kIdx == 4 * L 
			|| (long long)iIdx + 1 >= (long long)L * X 
			|| (long long)kIdx + 1 >= (long long)L * X
			|| long long(iIdx + kIdx + 2) >= (long long)L*X){
			outfile << "Case #" << n << ": NO" << endl;
			continue;
		}
		else{
			outfile << "Case #" << n << ": YES" << endl;
			continue;
		}

	}
	infile.close();
	outfile.close();
	return 0;
}