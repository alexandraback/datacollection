#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <set>
#include <cassert>

using namespace std;

ifstream fin ("a.in");
ofstream fout ("a.out");

int T, n;
long long int aantmk[1234567];
long long int volg[1234567];
long long int opl;
string S;

int main () {
	fin >> T;
	for (int i =  1; i <= T; i++) {
		fout << "Case #" << i << ": ";
		fin >> S >> n;
		aantmk[S.size()] = 0;
		volg[S.size()] = -1;
		opl = 0;
		for (int j = S.size()-1; j >= 0; j--) {
			if ((S[j] == 'a') or (S[j] == 'e') or (S[j] == 'i') or (S[j] == 'o') or (S[j] == 'u')) {
				aantmk[j] = 0;
			} else {
				aantmk[j] = aantmk[j+1] + 1;
			}
			if (aantmk[j] >= n) {
				volg[j] = j;
			} else {
				volg[j] = volg[j+1];
			}
			if (volg[j] > -1) {
				opl += S.size() - volg[j] - n + 1;
			}
		}
		fout << opl << '\n';
	}	
	return 0;
}
