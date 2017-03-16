#include <bits/stdc++.h>
using namespace std;

bool a[10];

void solve(int x){
	int n;
	cin >> n;
	if (!n){
		cout << "Case #" << x << ": INSOMNIA\n";
		return;
	}
	fill(a, a + 10, false);

	for (int i = 1 ;; ++i){
		long long j = n * i;
		while (j){
			a[j % 10] = true;
			j /= 10;
		}
		bool t = true;
		for (int k = 0; k < 10; ++k)
			if (!a[k]){
				t = false;
			}
		if (t){
			cout << "Case #" << x << ": " << 1ll * n * i << "\n";
			break;
		}
	}
}

int main(){
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i){
		solve(i);
	}
	return 0;
}
