#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

void solve(int tc) {
	int out = 0;
	cout << "Case #" << tc << ": ";
	int a, b, k;
	cin >> a >> b >> k;
	for (int i=0; i<a; i++)
		for (int j=0; j<b; j++) {
			if ((i&j) < k) out++;
		}
	cout << out << endl;
}

int main() {
	int T;
	cin >> T;
	for (int tc=1; tc<=T; tc++) solve(tc);
	return 0;
}
