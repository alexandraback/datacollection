#include <iostream>

using namespace std;

int size[7][2] = {{0, 0},
				  {1, 1},
				  {1, 2},
				  {2, 3},
				  {3, 4},
				  {3, 5},
				  {4, 6}};
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int x, r, c;
		cin >> x >> r >> c;
		cout << "Case #" << t << ": " 
			 << ((     (x >= 7) 
			 	 	|| ((r * c) % x != 0) 
			 	 	|| (min(r,c) < size[x][0]) 
			 	 	|| (max(r,c) < size[x][1])) 
			     ? "RICHARD" 
			     : "GABRIEL") 
			 << endl;

	}
	return 0;
}
