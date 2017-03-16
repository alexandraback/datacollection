#include <iostream>

using namespace std;

int data[200][200];

int main(){
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N, M;
		cin >> N >> M;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				cin >> data[n][m];
			}
		}
	
		bool ok = true;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				bool row = true;
				bool col = true;
				for (int r = 0; r < N; r++) {
					if (data[r][m] > data[n][m]) {
						row = false;
						break;
					}
				}
				for (int c = 0; c < M; c++) {
					if (data[n][c] > data[n][m]) {
						col = false;
						break;
					}
				}
				if (!(row || col)) {
					ok = false;
					break;
				}
			}
			if (!ok)
				break;
		}
		cout << "Case #" << t << (ok ? ": YES" : ": NO") << endl;	
	}
	return 0;
}