#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {
	ifstream fin("lawnmower.in", ios::in);

	int tstNum, tstCount;
	int g[100][100];
	fin >> tstNum; tstCount = tstNum;
	while(tstCount--) {
		int n, m, max = 0;
		bool ans = true;
		fin >> n >> m;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				fin >> g[i][j];
				if(g[i][j] > max) max = g[i][j];
			}
		if(n != 1 && m != 1) {
			int lastmin = -1;
			while(1) {
				int min = max;
				int semin = min;
				int mini, minj;
				for(int i = 0; i < n; ++i)
					for(int j = 0; j < m; ++j) {
						if(min > g[i][j]) {
							semin = min;
							min = g[i][j];
						} else if(semin > g[i][j] && g[i][j] != min) semin = g[i][j];
					}
				if(min == max) break;
				if(min == lastmin) {ans = false; break;}
				lastmin = min;
				bool r[100] = {false};
				for(int i = 0; i < n; ++i) {
					int j;
					for(j = 0; j < m && g[i][j] == min; ++j);
					if(j == m) r[i] = true;
				}

				bool c[100] = {false};
				for(int j = 0; j < m; ++j) {
					int i;
					for(i = 0; i < n && g[i][j] == min; ++i);
					if(i == n) c[j] = true;
				}

				for(int i = 0; i < n; ++i)
					if(r[i])
						for(int j = 0; j < m; ++j)
							g[i][j] = semin;
				for(int j = 0; j < m; ++j)
					if(c[j])
						for(int i = 0; i < n; ++i)
							g[i][j] = semin;
			} 
		}
		ofstream fout("lawnmower.out", ios::app);
		fout << "Case #" << tstNum - tstCount << ": ";
		if(ans) fout << "YES" << endl;
		else fout << "NO" << endl;
		fout.close();
	}
	fin.close();
	return 0;
}
