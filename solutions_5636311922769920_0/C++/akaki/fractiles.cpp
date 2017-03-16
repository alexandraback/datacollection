#include <bits/stdc++.h> 

using namespace std;

int i, j, k, l, m, n, t, c, s;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	for (int test = 0; test < t; test++){
		cin >> k >> c >> s;
		cout << "Case #" << test + 1 << ": ";
		for (i = 0; i < s; i++){
			cout << i + 1 << " ";
		}
		cout << "\n";
	}
	return 0;
} 