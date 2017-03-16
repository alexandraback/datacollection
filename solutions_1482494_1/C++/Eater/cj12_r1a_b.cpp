#include <iostream>
#include <fstream>

using namespace std;

int T, N;
int beaten[1000], a[1000], b[1000];

void quickSort(int left, int right);

int main()
{
	ifstream fin ("cj12_r1a_b.in");
	ofstream fout ("cj12_r1a_b.out");
	fin >> T;
	for (int t = 1; t <= T; t++) {
		fin >> N;
		for (int n = 0; n < N; n++) {
			beaten[n] = 0;
			fin >> a[n] >> b[n];
		}
		quickSort(0, N - 1);
		int stars = 0, games = 0;
		for (;;) {
			int i = -1;
			for (int n = 0; n < N && a[n] <= stars; n++) {
				if (beaten[n] == 2) { continue; }
				else if (b[n] <= stars) {
					stars += 2 - beaten[n];
					beaten[n] += 2 - beaten[n];
					i = -2;
					games++;
					break;
				}
				else if (beaten[n] == 0 && (i == -1 || b[i] < b[n])) { i = n; }
			}
			if (i > -1) {
				stars++;
				beaten[i] = 1;
				games++;
			}
			else if (i == -1) {
				if (stars < N * 2) { games = -1; }
				break;
			}
		}
		if (games == -1) { fout << "Case #" << t << ": Too Bad" << endl; }
		else { fout << "Case #" << t << ": " << games << endl; }
	}
	return 0;
}

void quickSort(int left, int right)
{
	int i = left, j = right;
	int midEle = a[(left + right) / 2];
	while (i <= j) {
		while (a[i] < midEle) { i++; }
		while (a[j] > midEle) { j--; }
		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			temp = b[i];
			b[i] = b[j];
			b[j] = temp;
			i++; j--;
		}
	}
	if (left < j) { quickSort(left, j); }
	if (i < right) { quickSort(i, right); }
}