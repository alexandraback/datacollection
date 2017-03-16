#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> v;
	int t,n,x; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		cin >> n;
		v.assign(3000, 0);
		int m = n*n*2 -n;
		for (int i = 0; i < m; i++){
			cin >> x;
			v[x]++;
		}
		cout << "Case #" << tc<<':';
		for (int i = 0; i < 2600; i++){
			if (v[i] % 2)cout << ' ' << i;
		}
		cout << '\n';
	}
}