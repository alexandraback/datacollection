#include<iostream>
using namespace std;

int main(){
	int T, n, m;
	int v[100][100];
	int max_row[100], max_col[100];
	cin >> T;
	for(int cs = 1; cs <= T; ++cs){
		cin >> n >> m;
		for(int i = 0; i < n; ++i)
			max_row[i] = 0;
		for(int i = 0; i < m ;++i)
			max_col[i] = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				cin >> v[i][j];
				max_row[i] = max(max_row[i], v[i][j]);
				max_col[j] = max(max_col[j], v[i][j]);
			}
		bool good = true;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				if(v[i][j] != max_row[i] && v[i][j] != max_col[j]){
					good = false;
				}
		cout << "Case #" << cs << ": " << (good ? "YES" : "NO") << endl;

	}
	return 0;
}
