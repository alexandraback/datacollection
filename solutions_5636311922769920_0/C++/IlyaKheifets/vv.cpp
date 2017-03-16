#include <bits/stdc++.h>
using namespace std;

void solve(int x){
	long long res = 1;
	int k, c , s;
	cin >> k >> c >> s;
	for (int i = 1; i < c; ++i)
		res *= 1ll * k;

	cout << "Case #" << x << ": ";
	for (int i = 0; i < k; ++i){
		if (i){
			cout << " ";
		}
		cout << (res * 1ll * i) + 1;
	}
	cout << "\n";
}

int main(){
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i){
		solve(i);
	}
	return 0;
}
