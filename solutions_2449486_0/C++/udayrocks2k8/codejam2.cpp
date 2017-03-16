#include <iostream>
using namespace std;

typedef pair<int ,int> pii;

struct lawn {
	int height;
	int row;
	int column;
};

bool cmp(lawn l1, lawn l2) {
	return l1.height > l2.height;
}

void getResult() {
	int m, n;
	cin >> m >> n;
	struct lawn grass[m * n];
	pii simLawn[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grass[n * i + j].height;
			grass[n * i + j].row = i;
			grass[n * i + j].column = j;
			simLawn[i][j] = make_pair(-1, -1);
		}
	}
	sort(grass, grass + (m * n), cmp);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j< n; j++) {
			int height = grass[i * n + j].height;
			int row = grass[i * n + j].row;
			int column = grass[i * n + j].column;
			if (simLawn[row][column].first == -1) {
				for (int k = 0; k < n; k++) {
					simLawn[row][k].first = height;
				}
			}
			if (simLawn[row][column].second == -1) {
				for (int k = 0; k < m; k++) {
					simLawn[k][column].second = height;
				}
			}	
			int presentHeight = min(simLawn[row][column].first, simLawn[row][column].second);
			if (presentHeight > height) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl; 
}

int main() {
	int testCases;
	cin >> testCases;
	for (int i = 1; i <= testCases; i++) {
		cout << "Case #" << i << ": ";
		getResult();
	}
	return 0;
}