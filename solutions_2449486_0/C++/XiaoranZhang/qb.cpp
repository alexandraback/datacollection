#include<iostream>

using namespace std;

int smap[101][101], maxx[101], maxy[101];

int main() {
	int Ncase;
	
	cin >> Ncase;
	for (int t = 1; t <= Ncase; t ++) {
		bool valid = true;
		int m, n;
		
		cin >> n >> m;
		for (int i = 0; i < n; i ++) {
			maxx[i] = 0;
		}
		for (int i = 0; i < m; i ++) {
			maxy[i] = 0;
		}
		
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				cin >> smap[i][j];
				
				maxx[i] = maxx[i] > smap[i][j] ? maxx[i] : smap[i][j];
				maxy[j] = maxy[j] > smap[i][j] ? maxy[j] : smap[i][j];
			}
		}
		
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				if (smap[i][j] < maxx[i] && smap[i][j] < maxy[j]) {
					valid = false;
				}
			}
		}
		
		cout << "Case #" << t << ": " << (valid?"YES":"NO") << endl;
	}
	
	return 0;
}
