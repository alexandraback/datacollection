#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	int n, j;
	cin >> n >> j;
	int k = (n / 2) - 2;
	cout << "Case #1:\n";
	for (int mask = 0; mask < j; mask++){
		cout << "11";
		for (int j = 0; j < k; j++){
			cout << ((mask >> j) & 1);
			cout << ((mask >> j) & 1);
		}
		cout << "11 3";	
		for (int i = 4; i <= 11; i++){
			cout << " " << i;
		}
		cout << "\n";
	}
	return 0;
}
