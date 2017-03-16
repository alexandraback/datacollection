#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main () {
	int T;
	ifstream fin ("input.txt");
	ofstream fout ("output.txt");
	fin >> T;
	for (int t = 0; t < T; t++) {
		int jac, p, s, qq;
		fin >> jac >> p >> s >> qq;
		int a[30], b[30], c[30];
		int aa[5][5], bb[5][5], cc[5][5];
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				aa[i][j] = bb[i][j] = cc[i][j] = 0;
		int n = 0;
		for (int i = 1; i <= jac; i++)
			for (int j = 1; j <= p; j++)
				for (int k = 1; k <= s; k++)
					if (aa[i][j] != qq && bb[i][k] != qq && cc[k][j] != qq) {
						aa[i][j]++;
						bb[i][k]++;
						cc[k][j]++;
						a[n] = i;
						b[n] = j;
						c[n] = k;
						n++;
					}	
		fout << "Case #" << t + 1 << ": " << n << endl;
		for (int i = 0; i < n; i++)
			fout << a[i] << " " << b[i] << " " << c[i] << endl; 
			
	}
	fin.close();
	fout.close();
	return 0;
}