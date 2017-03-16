// ---------------------------------------------------------------------------

#pragma hdrstop

#include <tchar.h>
// ---------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib>
#include <vector>
using namespace std;
#pragma argsused

int main() {
	int t;
	ifstream fin("C-large.in");
	ofstream fout("A.out");
	fin >> t;
	for (int i = 0; i < t; i++) {
		int a,b;
		fin >> a >> b;
		int count = 0;

		for (int i = a; i <= b; i++) {
			int t = i;

			int y = 1;
			while (y <= i) y *= 10;
			y /= 10;
			int x = 10;
			int tt = y / 10;


			while (tt) {

				t = (t % x) * y +  (t / x);
				if (i < t && t <= b) {
					count++;

				}
				if (t == i) {
					tt /= 10;
					break;
				}
				tt /= 10;
				//y /= 10;
				//x *= 10;
			}
		}

		fout << "Case #" << (i+1) << ": " << count << endl;
	}
	return 0;
}
// ---------------------------------------------------------------------------
