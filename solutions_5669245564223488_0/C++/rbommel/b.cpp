#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <set>
#include <cassert>
#include <cmath>

using namespace std;

ifstream fin ("b.in");
ofstream fout ("b.out");

long long T, N;
long long M = 1000000007;
string wagon[123];
char eerste[123], laatste[123];
long long nE[30], nL[30], dd[30], dubbel[123];
long long volg[123], voor[123];

int main () {
	fin >> T;
	for (long long i =  1; i <= T; i++) {
		bool poss = true;
		long long A = 1;
		for (int k = 0; k < 30; k++)
			nE[k] = nL[k] = dd[k]  = 0;
		for (int k = 0; k < 123; k++)
			volg[k] = voor[k] = dubbel[k] = -1;
		fout << "Case #" << i << ": ";
		fin >> N;
		for (long long j = 0; j < N; j++) {
			fin >> wagon[j];
			eerste[j] = wagon[j][0];
			laatste[j] = wagon[j][(wagon[j]).length() - 1];
			//cerr << laatste[j] << '\n';
			nE[eerste[j] - 'a']++;
			nL[laatste[j] - 'a']++;
			dubbel[j] = -1;
			if (eerste[j] == laatste[j]) {
				dd[eerste[j] - 'a']++;
				dubbel[j] = eerste[j] - 'a';	
			}
		}
		for (int k = 0; k < 30; k++) {
			if ((nE[k] > 0) && (nL[k] > 0)) {
				if ((nE[k] > nL[k] + 1) || (nL[k] > nE[k] + 1)) {
					//cerr << "Impossible1\n";
					poss = false;
				} else if (max(nE[k], nL[k]) > dd[k] + 1) {
					//cerr << "Impossible2\n";
					poss = false;
				} else {
					for (long long B = 1; B <= dd[k]; B++) {
						A *= B;
						A %= M;
					}
					int vwagon = -1;
					int awagon = -1;
					for (long long j = 0; j < N; j++) {
						if ((eerste[j] - 'a' == k) && (laatste[j] - 'a' != k))
							awagon = j;
						if ((eerste[j] - 'a' != k) && (laatste[j] - 'a' == k))
							vwagon = j;
					}			
					int vorige = vwagon;
					//cerr << "Tijd om te rangeren\n";
					for (long long j = 0; j < N; j++) {
						if (dubbel[j] == k) {
							if (vorige != -1) {
								volg[vorige] = j;
								voor[j] = vorige;
								//cerr << "Na " << wagon[vorige] << " zetten we " << wagon[j] << '\n';
							}							
							vorige = j;
						}
					}
					if (awagon != -1) {
						volg[vorige] = awagon;
						voor[awagon] = vorige;
						//cerr << "Na " << wagon[vorige] << " zetten we " << wagon[awagon] << '\n';
					}
					
				}
				//cerr << "Let op " << ((char) ('a' + k)) << "; voor i = " << i << '\n';
			} else if ((nE[k] > 1) || (nL[k] > 1)) {
				//cerr << "Impossible3\n";
				poss = false;
			}
		}
		//cerr << "If possible, then in " << A << " ways\n";
		if (poss) {
			int agehad = 0;
			string trein = "";
			long long aW = 0;
			for (long long j = 0; j < N; j++) {
				if (voor[j] == -1) {
					aW++; A *= aW; A %= M;
					int curr = j;
					while (curr != -1) {
						trein += wagon[curr];
						agehad++;
						curr = volg[curr];
					}
				}
			}
			if (agehad < N)
				poss = false;
			//cerr << "Is " << trein << " een correcte trein?\n";
			bool visited[30];
			for (int k = 0; k < 30; k++) visited[k] = false;
			char vorigekar = '0';
			for (int k = 0; k < ((int) trein.length()); k++) {
				if (trein[k] != vorigekar) {
					if (visited[trein[k] - 'a'])
						poss = false;
					visited[trein[k] - 'a'] = true;
				}
				vorigekar = trein[k];
			}
		}
		
		if (poss)
			fout << A << '\n';
		else
			fout << "0\n";
	}	
	return 0;
}
