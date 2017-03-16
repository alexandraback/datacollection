#include <iostream>
using namespace std;

int count[1000][1000];
int visited[1000];
int num[1000];
int store[1000][1000];
int n,t;

bool dfs (int i) {
	if (visited[i])
		return false;
	else {
		visited[i] = true;
		for (int j = 0; j < num[i]; j++){
			count[i][store[i][j]]++;
			if (dfs(store[i][j])) return true;
			for (int k = 0; k < t; k++) {
				count[i][k] += count[store[i][j]][k];
				if (count[i][k] >= 2) return true;
			}
		}
	}
	return false;
}

int main () {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		memset (count, 0, 1000*1000*sizeof(int));
		memset (visited, 0, 1000*sizeof (int));
		memset (num, 0, 1000*sizeof(int));
		memset (store, 0, 1000*1000*sizeof(int));
		for (int j = 0; j < t; ++j) {
			cin >> num[j];
			for (int k = 0; k < num[j]; k++) {
				cin >> store[j][k];
				store[j][k]--;
			}
		}
		bool flag = false;
		for (int j = 0; j < t; ++j) {
			if (dfs(j)) {
				flag = true;
				break;
			}
		}
		if (flag) {
			cout << "Case #" << i+1 << ": Yes" << endl;
		}
		else {
			cout << "Case #" << i+1 << ": No" << endl;
 		}
	}
}

