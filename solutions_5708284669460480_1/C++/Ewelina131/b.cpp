#include<iostream>
using namespace std;

int main() {
	int t, c, d, v;
	cin >> t;
	for(int i = 0; i < t; i ++) {
		cin >> c >> d >> v;
		int tab[v + 1];
		tab[0] = 0;
		for(int j = 1; j <= v; j ++) {
			tab[j] = 1;
		}
		for(int j = 0; j < d; j ++) {
			int a;
			cin >> a;
			for(int k = v - a; k >= 0; k --) {
				tab[k + a] = tab[k];
			}
		}
		int odp = 0;
		for(int j = 0; j <= v; j++) {
			odp += tab[j];
		}
		cout << "Case #" << i << ": " << odp << endl;
	}
	return 0;
}
