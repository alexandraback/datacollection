#include <iostream>
using namespace std;
int main(){
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	bool test;
	int cases, n, m;
	cin >> cases;
	for(int c = 1; c <= cases; c++){
		if(c != 1) cout << endl;
		cout << "Case #" << c << ": ";

		cin >> n >> m;
		int arr[110][110];
		bool val[110][110] = {0};
		for(int i = 0; i < n; i++)
			for(int k = 0; k < m; k++)
				cin >> arr[i][k];

		for(int i = 0; i < n; i++){
			int mx = 0;
			for(int k = 0; k < m; k++){
				if(arr[i][k] > mx) mx = arr[i][k];
			}
			for(int k = 0; k < m; k++){
				if(arr[i][k] == mx) val[i][k] = true;
			}
		}

		for(int k = 0; k < m; k++){
			int mx = 0;
			for(int i = 0; i < n; i++){
				if(arr[i][k] > mx) mx = arr[i][k];
			}
			for(int i = 0; i < n; i++){
				if(arr[i][k] == mx) val[i][k] = true;
			}
		}

		test = true;
		for(int i = 0; i < n; i++)
			for(int k = 0; k < m; k++)
				if(!val[i][k]) test = false;	

		if(test) cout << "YES";
		else cout << "NO";
	}
	return 0;
}