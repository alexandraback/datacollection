#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int nCases;
	cin >> nCases;
	
	for (int cnt = 1; cnt <= nCases; cnt++) {
		int R, C, W;
		cin >> R >> C >> W;
		
		int result = C / W * R + W;
		if (C % W == 0)
			result--;
		
		cout << "Case #" << cnt << ": " << result << endl;
	}
	return 0;
}
