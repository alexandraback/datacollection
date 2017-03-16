#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <fstream>

using namespace std;

int T;
int J, P, S, K;

int cnt;

int JP[11][11];
int JS[11][11];
int PS[11][11];
bool have[11][11][11];

int rec[1001][3];

ifstream infile;
ofstream outfile;

void reset() {
	cnt = 0;
	for (int i = 1; i <= 10; ++i)
		for (int j = 1; j <= 10; ++j) {
			JP[i][j] = 0;
			JS[i][j] = 0;
			PS[i][j] = 0;
			for (int k = 1; k <= 10; ++k)
				have[i][j][k] = false;
		}
}

void proc() {
	for (int i = 1; i <= J; ++i)
		for (int j = 1; j <= P; ++j) {
			while (JP[i][j] < K) {
				int min = 100;
				int mink = 0;
				for (int k = 1; k <= S; ++k) {
					if (have[i][j][k] || JS[i][k] == K || PS[j][k] == K) continue;
					if (JS[i][k] < min && PS[j][k] < min) {
						min = JS[i][k] > PS[j][k] ? JS[i][k] : PS[j][k];
						mink = k;
					}
				}
				if (min < 100) {
					++JP[i][j];
					++JS[i][mink];
					++PS[j][mink];
					++cnt;
					rec[cnt][0] = i;
					rec[cnt][1] = j;
					rec[cnt][2] = mink;
					have[i][j][mink] = true;
				}
				else
					break;
			}
		}
}

int main() {
	infile.open("input.txt");
	outfile.open("output.txt");

	infile >> T;

	for (int p = 1; p <= T; ++p) {
		reset();

		infile >> J >> P >> S >> K;
		outfile << "Case #" << p << ": ";

		proc();
		outfile << cnt << endl;
		for (int i = 1; i <= cnt; ++i)
			outfile << rec[i][0] << ' ' << rec[i][1] << ' ' << rec[i][2] << endl;
	}

	infile.close();
	outfile.close();
	return 0;
}