#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <set>
#include <cassert>

using namespace std;

ifstream fin ("blarge.in");
ofstream fout ("blarge.out");

int T, X, Y, D, n, N, over, teken;
char opl[5000];


int main () {
	fin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << '\n';
		fout << "Case #" << i << ": ";
		fin >> X >> Y;
		D = abs(X) + abs(Y);
		n = 0;
		N = 0;
		while ((N < D) or ((N-D) % 2 != 0)) {
			n++;
			N += n;
		}
		over = (N - D) / 2;
		for (int j = 1; j <= n; j++)
			opl[j] = 'a';
		
		/*// OVERSCHOT
		//cout << "over: " << over << '\n';
		if (over <= n) {
			if (Y < 0) {
				opl[over] = 'N';
				Y -= over;
			} else {
				opl[over] = 'S';
				Y += over;
			}
		} else {
			if ((over % 2) == 0) {
				if (Y > 0) {
					opl[over/2 - 1] = 'N';
					opl[over/2 + 1] = 'N';
					Y -= over;
				} else {
					opl[over/2 - 1] = 'S';
					opl[over/2 + 1] = 'S';
					Y += over;
				}
			} else {
				if (Y > 0) {
					opl[(over-1)/2] = 'N';
					opl[(over+1)/2] = 'N';
					Y -= over;
				} else {
					opl[(over-1)/2] = 'S';
					opl[(over+1)/2] = 'S';
					Y += over;
				}
			
			}
		}
		// EIND OVERSCHOT*/
		
		for (int j = n; j >= 1; j--) {
			if (opl[j] != 'a')
				continue;
			if (abs(Y) >= abs(X)) {
				if (Y > 0) {
					opl[j] = 'N';
					Y -= j;
				} else {
					opl[j] = 'S';
					Y += j;
				}
			} else {
				if (X > 0) {
					opl[j] = 'E';
					X -= j;
				} else {
					opl[j] = 'W';
					X += j;
				}
			}
		}
		
		//cout << "(X, Y) = (" << X << ", " << Y << ")\n";
		if ((X == 0) and (Y == 0)) {
		
			for (int j = 1; j <= n; j++)
				fout << opl[j];
				
		} else {
		
			fout << "???";
			cout << "WARNING CASE #" << i << '\n';	
			cout << "n = " << n << '\n';
			for (int j = 1; j <= n; j++)
				fout << opl[j];
			
		}
		fout << '\n';		
	}
	
	return 0;
}
