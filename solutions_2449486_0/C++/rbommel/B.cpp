#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("B.in");
ofstream fout("B.out");

int T, N, M;
int veld[100][100];
int maxR[100], maxC[100];
bool possible;

int main() {
	fin >> T;
	
	for (int i = 1; i <= T; i++) {
	
	// Read field
		fin >> N >> M;
		for (int k = 0; k < M; k++)
			maxC[k] = 0;
		for (int j = 0; j < N; j++) {
			maxR[j] = 0;
			for (int k = 0; k < M; k++) {
				fin >> veld[j][k];
			maxR[j] = max(maxR[j], veld[j][k]);
			maxC[k] = max(maxC[k], veld[j][k]);		
			}
		}
		
	// See if possible
		possible = true;
		for (int j = 0; j < N; j++)
		for (int k = 0; k < M; k++)
			if (veld[j][k] != min(maxR[j], maxC[k]))
				possible = false;
		
	// Output result
		fout << "Case #" << i << ": ";
		if (possible)
			fout << "YES\n";
		else
			fout << "NO\n";
	
	
	}

	return 0;
}

