#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]) {
	int tstNum, tstCount;
	cin >> tstNum; tstCount = tstNum;
	while(tstCount--) {
		int v[10];
		int f[10][6] = {0};
		int e, r, n;
		cin >> e >> r >> n;
		for(int i = 0; i < n; ++i)
			cin >> v[i];
		for(int i = 0; i <= e; ++i)
			f[0][i] = (e - i) * v[0];
		for(int i = 1; i < n; ++i)
			for(int j = 0; j <= e; ++j) 
				for(int k = 0; k <= e; ++k) {
					int ebc = (k + r >= e) ? e : (k + r);
					if(ebc < j) continue;
					int value = (ebc - j) * v[i] + f[i - 1][k];
					if(value > f[i][j]) f[i][j] = value;
				}
		cout << "Case #" << tstNum - tstCount << ": ";
		int max = 0;
		for(int j = 0; j <= e; ++j)
			if(max < f[n - 1][j]) max = f[n - 1][j];
		cout << max << endl;
	}
	return 0;
}
