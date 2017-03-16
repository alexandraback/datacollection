#include<iostream>
using namespace std;

int main() {
	int t, r, c, w, odp;
	cin >> t;
	for(int i = 1; i <= t; i ++) {
		cin >> r >> c >> w;
		odp = c / w * (r - 1);
		while(c >= 2 * w) {
			odp ++;
			c -= w;
		}
		odp += w;
		if(c > w) {
			odp ++;
		}
		cout << "Case #" << i << ": " << odp << endl;
	}
	return 0;
}
