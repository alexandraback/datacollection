#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("B-small-attempt0.in");
	fout.open("B-small-attempt0.out");

	int testCases;
	double c, f, x, r, t;
	
	fin >> testCases;
	fout.precision(10);
	for(int tcase = 1; tcase <= testCases; tcase++) {
		r = 2; t = 0;
		fin >> c >> f >> x;
		while(x > 0) {
			if(x <= c) {
				t += x / r;
				x = 0;
			}
			else if((r + f)*c <= f*x) {
				t += c / r;
				r += f;
			}
			else {
				t += x / r;
				x = 0;
			}
		}
		
		fout << "Case #" << tcase << ": ";
		
		fout << t;
		
		fout << endl;

	}
	
	fin.close();
	fout.close();
	return 0;
}

