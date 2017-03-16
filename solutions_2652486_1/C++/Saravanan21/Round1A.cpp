#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <sstream>

using namespace std;

ofstream fout("output.txt");
ifstream fin("input.txt");

void Target() {
	unsigned long double R, T;
	fin >> R >> T;
	unsigned long long answer = floor((1 - 2*R + floor(sqrt((4*R*R - 4*R + 1 + 8*T))))/4);
	fout << answer << endl;
}

void Energy() {
	unsigned long long E, R, N;
	fin >> E >> R >> N;
	unsigned long long Activities[10100];
	for (int i=0; i<N; ++i)
		fin >> Activities[i];
	if (R >= E) {
		unsigned long long Score = 0;
		for (int i=0; i<N; ++i)
			Score += Activities[i] * E;
		fout << Score << endl;
		return;
	}
	unsigned long long MaxSteps = floor((double)E / (double)R);

	unsigned long long CurrentE = E;
	unsigned long long CurrentN = 0;
	unsigned long long Score = 0;

	while (CurrentN < N) {
		unsigned long long NextA = Activities[CurrentN];
		if (CurrentN == N-1) {
			Score += CurrentE*NextA;
			break;
		}
		unsigned long long BestA = 0;
		int BestIndex = -1;
		for (int j=CurrentN+1; j<=CurrentN+MaxSteps; ++j) {
			if (j >= N)
				break;
			if (Activities[j] > BestA) {
				BestA = Activities[j];
				BestIndex = j;
				if (BestA > NextA)
					break;
			}
		}
		if (BestA >= NextA) {
			unsigned long long Diff = (BestIndex - CurrentN)*R;
			if (CurrentE + Diff > E) {
				int Spend = CurrentE - (E - Diff);
				Score += Spend*NextA;
				CurrentE -= Spend;
			}
			CurrentE += Diff;
			CurrentN = BestIndex;
		}
		else {
			unsigned long long Spend = CurrentE;
			Score += Spend * NextA;
			CurrentE -= Spend;

			unsigned long long Diff = (BestIndex - CurrentN)*R;
			CurrentE += Diff;
			CurrentN = BestIndex;
		}
	}

	fout << Score << endl;
}

void GoodLuck() {
	fout << endl;
	int R, N, M, K;
	fin >> R >> N >> M >> K;
	int Val;
	for (int i=0; i<R; ++i) {
		if (i == 9) {
			fout << "Ooops";
		}
		int ReqCount[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		for (int j=0; j<K; ++j) {
			fin >> Val;
			for (int f=M; f>=2; --f) {
				int count = 0;
				while (Val % f == 0) {
					Val /= f;
					++count;
				}
				ReqCount[f] = max<int>(ReqCount[f], count);
			}
		}
		int totalReq = 0;
		for (int i=2; i<=M; ++i) {
			totalReq += ReqCount[i];
		}
		while (totalReq < N) {
			/*int maxVal = 0;
			int maxIndex = 2;
			for (int f=2; f<=M; ++f) {
				if (ReqCount[f] > maxVal) {
					maxVal = ReqCount[f];
					maxIndex = f;
				}
			}*/
			/*
			int maxIndex = rand() % (M-1) + 2;
			++ReqCount[maxIndex];
			++totalReq;
			*/
			if (M >= 8 && ReqCount[8] > 0) {
				if (rand() % 2 == 0 && ReqCount[8] > 1) {
					ReqCount[8] -= 2;
					ReqCount[4] += 3;
					++totalReq;
					continue;
				}
				else {
					ReqCount[8] -= 1;
					ReqCount[2] += 3;
					totalReq += 2;
					continue;
				}
			}
			if (M >= 6 && ReqCount[6] > 0) {
				--ReqCount[6];
				++ReqCount[2];
				++ReqCount[3];
				++totalReq;
				continue;
			}
			if (M >= 4 && ReqCount[4] > 0) {
				--ReqCount[4];
				ReqCount[2] += 2;
				++totalReq;
				continue;
			}
			break;
		}
		while (totalReq < N) {
			int maxVal = 0;
			int maxIndex = rand() % (M-1) + 2;
			for (int f=2; f<=M; ++f) {
				if (ReqCount[f] > maxVal + 2) {
					maxVal = ReqCount[f];
					maxIndex = f;
				}
			}
			++ReqCount[maxIndex];
			++totalReq;
		}
		
		while (totalReq > N) {
			if (M >= 8 && ReqCount[2] > 0 && ReqCount[4] > 0) {
				--ReqCount[2];
				--ReqCount[4];
				++ReqCount[8];
				--totalReq;
				continue;
			}
			if (M >= 6 && ReqCount[2] > 0 && ReqCount[3] > 0) {
				--ReqCount[2];
				--ReqCount[3];
				++ReqCount[6];
				--totalReq;
				continue;
			}
			if (M >= 4 && ReqCount[2] > 1) {
				ReqCount[2] -= 2;
				++ReqCount[4];
				--totalReq;
				continue;
			}
			if (M >= 8 && ReqCount[4] > 2) {
				ReqCount[4] -= 3;
				ReqCount[8] += 2;
				--totalReq;
				continue;
			}
			break;
		}
		while (totalReq < N) {
			if (ReqCount[3] > 2 && ReqCount[8] > 0) {
				ReqCount[3] -= 3;
				--ReqCount[8];
				ReqCount[6] += 3;
				--totalReq;

			}
		}
		for (int f=2; f<=M; ++f) {
			for (int j=0; j<ReqCount[f]; ++j)
				fout << f;
		}
		fout << endl;
	}
}

int main() {
	int N;
	fin >> N;
	for (int i=1; i<=N; ++i) {
		fout << "Case #" << i << ": ";
		// Call function
		//Target();
		//Energy();
		GoodLuck();
	}
	return 0;
}