#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
int main() {
	int T, b;
	cin >> T;
	long long m;
	vector<long long>dic;
	dic.push_back(1);
	dic.push_back(1);
	for(int i = 2; i < 52; i++) {
		dic.push_back(2 * dic[i - 1]);
	}
	for(int t = 1; t <= T; t++) {
		cin >> b >> m;
		vector<vector<int> >mat(b, vector<int>(b, 0));
		
		for(int i = 0; i < b; i++) {
			for(int j = i + 1; j < b - 1; j++) {
				mat[i][j] = 1;
			}
		}
		for(int j = b - 2; j >= 0; j--) {
			if(m >= dic[j]) {
				mat[j][b - 1] = 1;
				m -= dic[j];
			}
		}
		
		if(m == 0) {
			cout << "Case #" << t << ": POSSIBLE" << endl;
			for(int i = 0; i < b; i++) {
				for(int j = 0; j < b; j++) {
					cout << mat[i][j];
				}
				cout << endl;
			}
		} else {
			cout << "Case #" << t << ": IMPOSSIBLE" << endl;
		}
	}
	return 0;
}