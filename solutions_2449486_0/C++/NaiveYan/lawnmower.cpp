#include <fstream>

using namespace std;

int a[100][100], mm[100], mn[100];

int main() {
	ofstream fout ("b.out");
	ifstream fin ("b.in");
	bool y;
	int t, n, m, x, i, j;
	fin >> t;
	for(x = 1; x <= t; x++) {
		fin >> n >> m;
		for(i = 0; i < n; i++) mn[i] = 0;
		for(i = 0; i < m; i++) mm[i] = 0;
		for(i = 0; i < n; i++) for(j = 0; j < m; j++) {
			fin >> a[i][j];
			if(a[i][j] > mn[i]) mn[i] = a[i][j];
			if(a[i][j] > mm[j]) mm[j] = a[i][j];
		}
		y = true;
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) if(a[i][j] != mn[i] && a[i][j] != mm[j]) {
				y = false;
				break;
			}
			if(!y) break;
		}
		fout << "Case #" << x << ": ";
		if(y) fout << "YES\n";
		else fout << "NO\n";
	}	
	return 0;
}
