#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int n, m, mine, T;

void print(int x, int y, int mx, int my, int rx, int  ry){
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j)
			if (i == 1 && j == 1)
				cout << "c";
			else 
				if ((i <= x && j <= ry) || (i <= mx && j <= my) || (i <= rx && j <= y))
					cout << ".";
				else 
					cout << "*";
		cout << endl;
	}
}

int main(){
	cin >> T;
	for (int testcase = 1; testcase <= T; ++testcase){
		cin >> n >> m >> mine;
		cout << "Case #" << testcase << ":" << endl;
		int space = n * m - mine - 1;
		if (space < 0){
			cout << "Impossible" << endl; 
			continue;
		}
		if (n == 1 || m == 1){
			for (int i = 1; i <= n * m; ++i){
				if (i <= mine)
					cout << "*";
				else
					if (i == n * m)
						cout << "c";
					else 
						cout << ".";
				if (i % m == 0)
					cout << endl;
			}
			continue;
		}
		if (space == 0){
			print(1, 1, 1, 1, 1, 1);
			continue;
		}
		int isFound = 0;
		int x = 0, y = 0, mx = 0, my = 0, rx = 0, ry = 0;
		for (x = 2; x <= n && !isFound; ++x)
			for (y = 2; y <= m && !isFound; ++y){
				if (x * y > space + 1)
					break;
				for (mx = x; mx <= n && !isFound; ++mx)
					for (my = y; my <= m && !isFound; ++my)
						for (rx = mx; rx <= n && !isFound; ++rx)
							for (ry = my; ry <= m && !isFound; ++ry)
								if (x * ry + (mx - x) * my + (rx - mx) * y == space + 1){
									isFound = 1;
									print(x, y, mx, my, rx, ry);
									break;
								}
			}	
		if (!isFound)
			cout << "Impossible" << endl;
	}
	return 0;
}