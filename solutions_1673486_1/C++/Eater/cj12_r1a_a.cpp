#include <iostream>
#include <fstream>

using namespace std;

int T, A, B;

int main()
{
	ifstream fin ("cj12_r1a_a.in");
	ofstream fout ("cj12_r1a_a.out");
	fout.precision(6);
	fout.setf(ios::fixed,ios::floatfield);
	fin >> T;
	for (int t = 1; t <= T; t++) {
		fin >> A >> B;
		double lowest = B + 2, prop = 1;
		for (int n = 1; n <= A; n++) {
			double p;
			fin >> p;
			prop *= p;
			double keys = (B - A + 1 + (A - n) * 2) * prop + (B - A + 1 + (A - n) * 2 + B + 1) * (1 - prop);
			if (keys < lowest) { lowest = keys; }
		}
		fout << "Case #" << t << ": " << lowest << endl;
	}
	return 0;
}
