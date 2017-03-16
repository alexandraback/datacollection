#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<stdio.h>

using namespace std;

vector<long long int> pw;

int T;
long long int B, M;
vector<vector<int> > Mat;

void Ipw() {
	pw.resize(63);
	pw[0] = 1;
	for(int i = 1; i < 63; i++) {
		pw[i] = 2 * pw[i - 1];
	}
}

int main() {
	ifstream fin("input_b.txt");
	ofstream fout("output_b.txt");
	
	Ipw();
	
	fin >> T;
	for(int tc = 1; tc <= T; tc++) {
		fin >> B >> M;
		
		if(M > pw[B - 2]) {
			fout << "Case #" << tc << ": IMPOSSIBLE" << endl;
			continue;
		}
		
		fout << "Case #" << tc << ": POSSIBLE" << endl;
		
		Mat = vector<vector<int> >(B, vector<int>(B, 0));
		for(int i = 0; i < B - 1; i++) {
			for(int j = i + 1; j < B - 1; j++) {
				Mat[i][j] = 1;
			}
		}
		
		if(M == pw[B - 2]) {
			for(int i = 0; i < B; i++) {
				for(int j = 0; j < B; j++) {
					int tmp = (i < j)? 1 : 0;
					fout << tmp;
				}
				fout << endl;
			}
			
			continue;
		}
		
		long long int C = M;
		int cnt = 1;
		while(C != 0) {
			if(C % 2 == 1) {
				Mat[cnt][B - 1] = 1;
			}
			cnt++;
			C /= 2;
		}
		for(int i = 0; i < B; i++) {
			for(int j = 0; j < B; j++) {
				fout << Mat[i][j];
			}
			fout << endl;
		}
	}
}
