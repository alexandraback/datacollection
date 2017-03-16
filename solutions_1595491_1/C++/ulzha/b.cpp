#include <iostream>
#include <algorithm>
using namespace std;

const int nmax = 100;
int n, s, p;

int main() {
	int nc, ic;
	
	cin >> nc;
	for (ic = 1; ic <= nc; ic++) {
		int i, x, nl = 0, ns = 0;
		
		cin >> n >> s >> p;
		for (i = 0; i < n; i++) {
			cin >> x;
			if ((x + 2) / 3 >= p) {
				nl++;
			} else if ((x % 3 == 2 ? x / 3 + 2 : (x ? x / 3 + 1 : 0)) >= p) {
				ns++;
			}
		}
		
		cout << "Case #" << ic << ": " << nl + min(s, ns) << endl;
	}
	
	return 0;
}
