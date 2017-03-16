// ---------------------------------------------------------------------------

#pragma hdrstop

#include <tchar.h>
// ---------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib>
using namespace std;
#pragma argsused

int main() {
	int t;
	ifstream fin("B-small-attempt1.in");
	ofstream fout("A.out");
	fin >> t;
	for (int i = 0; i < t; i++) {
		int n, p, s;
		fin >> n >> s >> p;
		int t;
		int count = 0;
		for (int j = 0; j < n; j++) {
			fin >> t;
			int temp = ceil(t / 3.0);
			if (temp >= p) count++;
			else {
				if (s > 0 && (t >= p) && (temp+1) >= p && ((t % 3) != 1) ) {
					s--;
					count++;
				}
            }

		}

		fout << "Case #" << (i+1) << ": " << count << endl;
	}
	return 0;
}
// ---------------------------------------------------------------------------
