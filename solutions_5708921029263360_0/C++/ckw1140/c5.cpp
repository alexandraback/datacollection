#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<stdio.h>

using namespace std;

int T;
int J, P, S, K;

int main() {
	ifstream fin("input_c.txt");
	ofstream fout("output_c.txt");
	
	fin >> T;
	for(int tc = 1; tc <= T; tc++) {
		fin >> J >> P >> S >> K;
		
		fout << "Case #" << tc << ": ";
		if(S <= K) fout << J * P * S << endl;
		else fout << min(J, K) * min(P, K) * K << endl;
		
		if(S <= K) {
			for(int i = 1; i <= J; i++) {
				for(int j = 1; j <= P; j++) {
					for(int k = 1; k <= S; k++) {
						fout << i << ' ' << j << ' ' << k << endl;
					}
				}
			}
		}
		else {
			for(int i = 1; i <= min(J, K); i++) {
				int j = i;
				int cnt1 = 0;
				while(cnt1 < min(P, K)) {
					int k = j;
					int cnt = 0;
					while(cnt < K) {
						fout << i << ' ' << j << ' ' << k << endl;
						k = (k + K - 1) % S + 1;
						cnt++;
					}
					j = (j + K - 1) % P + 1;
					cnt1++;
				}
			}
		}
	}
}
