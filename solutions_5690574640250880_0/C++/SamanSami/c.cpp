#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define sz(v) int(v.size())
typedef long long ll;
typedef pair<int,int> pii;

bool a[100][100];

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int n, m, c;
		cin >> n >> m >> c;
		c = n * m - c;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				a[i][j] = 1;
		bool ok = true;
		if(c == 1) {
			a[0][0] = false;
		} else if(min(n, m) == 1) {
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					if(i+j < c) 
						a[i][j] = 0;
		} else if(min(n, m) == 2) {
			if(c < 4 || c % 2 == 1)
				ok = false;
			else {
				for(int i = 0; i < n; i++)
					for(int j = 0; j < m; j++)
						if(i < c / 2 && j < c / 2)
							a[i][j] = 0;
			}
		} else {
			if(c < 4 || c == 5 || c == 7)
				ok = false;
			else {
				for(int i = 0; i < m && c > 0 && c != 3; i++) {
					c -= 2;
					a[0][i] = a[1][i] = 0;
				}
				for(int i = 2; i < n && c > 1; i++) {
					c -= 2;
					a[i][0] = a[i][1] = 0;
				}
				for(int i = 2; i < n && c > 0; i++)
					for(int j = 2; j < m && c > 0; j++) {
						c--;
						a[i][j] = 0;
					}
			}
		}
		cout << "Case #" << t << ":" << endl;
		if(!ok)
			cout << "Impossible" << endl;
		else
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++)
					if(i == 0 && j == 0)
						cout << 'c';
					else
						cout << (a[i][j]?'*':'.');
				cout << endl;
			}
	}
	return 0;
}
