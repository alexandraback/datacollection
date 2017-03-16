#include <iostream>

using namespace std;

int main() {
	int t, n, m, mx;
	int tab[101][101];
	bool check[101][101];
	cin >> t;

	for (int it=0; it<t; ++it) {
		cin >> n >> m;
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j) {
				cin >> tab[i][j];
				check[i][j]=false;
			}

		//Poziomo
		for (int i=0; i<n; ++i) {
			mx=0;
			for (int j=0; j<m; ++j)
				if (tab[i][j] > mx) 
					mx = tab[i][j];

			for (int j=0; j<m; ++j)
				if (tab[i][j] == mx) 
					check[i][j] = true;
		}

		//Pionowo
		for (int i=0; i<m; ++i) {
			mx=0;
			for (int j=0; j<n; ++j)
				if (tab[j][i] > mx) 
					mx = tab[j][i];

			for (int j=0; j<n; ++j)
				if (tab[j][i] == mx) 
					check[j][i] = true;
		}

		bool res = true;
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				if (check[i][j] == false) 
					res = false;

		if (res) cout << "Case #" << it+1 << ": YES" << endl;
		else cout << "Case #" << it+1 << ": NO" << endl;
	}

	//system("PAUSE");
	return 0;
}