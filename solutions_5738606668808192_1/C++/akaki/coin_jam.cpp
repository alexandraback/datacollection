#include <bits/stdc++.h> 

using namespace std;

int i, j, k, l, m, n, t;
string s;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	for (int test = 0; test < t; test++){
		cin >> n >> j;
		cout << "Case #" << test + 1 << ":\n";
		for (i = 0; i < j; i++){
			cout << "11";			
			for (k = 0; k < 14; k++){
				if ( (i & (1 << k)) > 0) {
					cout << "11";
				} else
				{
					cout << "00";
				}
			}
			cout << "11 ";
			for (k = 2; k <= 10; k++){
				cout << 1 + k << " ";
			}
			cout << "\n";
		}
	}
	return 0;
} 