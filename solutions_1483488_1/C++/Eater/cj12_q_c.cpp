#include <iostream>
#include <fstream>

using namespace std;

int T, A, B;

int main()
{
	ifstream fin ("cj12_q_c.in");
	ofstream fout ("cj12_q_c.out");
	fin >> T;
	for (int t = 1; t <= T; t++) {
		fin >> A >> B;
		int d = 0, tA = A;
		for (; tA > 0; tA /= 10) { d++; }
		int multi = 1;
		for (int n = 1; n < d; n++) { multi *= 10; }
		int sol = 0;
		for (int n = A; n < B; n++) {
			for (int m = n, c = 1; c < d; c++) {
				m = multi * (m % 10) + m / 10;
				if (m == n) { break; }
				if (m <= B && m > n) { sol++; }
			}
		}
		fout << "Case #" << t << ": " << sol << endl;
	}
	return 0;
}
