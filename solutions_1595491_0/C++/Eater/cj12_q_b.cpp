#include <iostream>
#include <fstream>

using namespace std;

int T, N, S, p, minS, nG;
int googlers[100];

void quickSort(int left, int right);

int main()
{
	ifstream fin ("cj12_q_b.in");
	ofstream fout ("cj12_q_b.out");
	fin >> T;
	for (int t = 1; t <= T; t++) {
		fin >> N >> S >> p;
		int c = (S > 0)?2:1;
		if (p <= c) { minS = p; }
		else { minS = p + 2 * (p - c); }
		for (int n = 0; n < N; n++) { fin >> googlers[n]; }
		quickSort(0, N - 1);
		nG = 0;
		for (int n = 0; n < N; n++) {
			if (googlers[n] < minS) { continue; }
			nG++;
			if (S > 0 && --S == 0) {
				if (p <= 1) { minS = p; }
				else { minS = p + 2 * (p - 1); }
			}
		}
		fout << "Case #" << t << ": " << nG << endl;
	}
	return 0;
}

void quickSort(int left, int right)
{
	int i = left, j = right;
	int midEle = googlers[(left + right) / 2];
	while (i <= j) {
		while (googlers[i] < midEle) { i++; }
		while (googlers[j] > midEle) { j--; }
		if (i <= j) {
			int temp = googlers[i];
			googlers[i] = googlers[j];
			googlers[j] = temp;
			i++; j--;
		}
	}
	if (left < j) { quickSort(left, j); }
	if (i < right) { quickSort(i, right); }
}