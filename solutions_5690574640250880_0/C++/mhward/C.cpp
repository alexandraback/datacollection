#include <iostream>

using namespace std;

int ans[50][50];

int r, c, m;

bool valid(int i, int j) {
	if (i < 0 || i > r-1)
		return false;
	if (j < 0 || j > c-1)
		return false;
	return true;
}

bool visited[50][50];

void dfs(int i, int j) {
	//cout << i << " " << j << endl;
	if (ans[i][j] == -2)
		return;
	int n = 0;
	for (int a = -1; a < 2; ++a)
		for (int b = -1; b < 2; ++b)
			if (valid(i+a, j+b) && ans[i+a][j+b] == -2)
				++n;
	ans[i][j] = n;
	if (n == 0) {
		for (int a = -1; a < 2; ++a) {
			for (int b = -1; b < 2; ++b) {
				if (valid(i+a, j+b) && ans[i+a][j+b] == -1 && (a != 0 || b != 0) ) {
					dfs(i+a, j+b);
				}
			}
		}
	}
}

bool allDone() {
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j) 
			if (ans[i][j] == -1)
				return false;
	return true;
}

void reset() {
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j) {
			if (ans[i][j] == -2)
				continue;
			ans[i][j] = -1;
			// visited[i][j] = false;
		}
}

bool bruteForce() {

	//int pos = r*c;
	//cout << pos << endl;
	unsigned int v = 0;
	for (int i = 0; i < m; ++i) {
		// cout << v << endl;
		v |= (1 << i);
	}

	// cout << v << ";;;;" << endl;

	unsigned int w = 0; 
	unsigned int max = (1 << (r*c))-1;
	// cout << max << endl;
	while (v < max) {
		// cout << v << endl;

		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j) 
				ans[i][j] = -1;

		for (int i = 0; i < r; ++i) {
			int n = i * c;
			for (int j = 0; j < c; ++j) {
				int m = n + j;
				if ( ((1 << m) & v) != (1 << m))
					continue;
				// cout << "blocked: " << i << " " << j << endl;
				ans[i][j] = -2;
			}
		}
		

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				// cout << "a" << endl;
				dfs(i, j);



				// for (int ii = 0; ii < r; ++ii) {
				// 	for (int jj = 0; jj < c; ++jj) {
				// 		cout << ans[ii][jj];
				// 	}
				// 	cout << endl;
				// }

				// cout << endl;

				// cout << "b" << endl;
				if (allDone()) {
					ans[i][j] = 99;
					return true;
				}
				// cout << "c" << endl;
				reset();
				// cout << "d" << endl;
			}
		}


		unsigned int t = (v | (v - 1)) + 1;  
		w = v == 0 ? 0 : t | ((((t & -t) / (v & -v)) >> 1) - 1);
		t = v;
		v = w;
		w = t;
	}
	return false;


}

int main() {
	int kases;
	cin >> kases;

	for (int i = 0; i < kases; ++i) {
		cin >> r >> c >> m;
		cout << "Case #" << i+1 << ":" << endl;

		if (m == 0) {
			for (int j = 0; j < r; ++j) {
				for (int k = 0; k < c; ++k) 
					cout << ((j == 0 && k == 0) ? 'c' : '.');
				cout << endl;
			}
		}
		else {
		
			if(!bruteForce()){
				cout << "Impossible" << endl;
				continue;
			}
			for (int i = 0; i < r; ++i) {
				for (int j = 0; j < c; ++j) {
					if(ans[i][j] == -2)
						cout << '*';
					else if(ans[i][j] == 99)
						cout << 'c';
					else
						cout << '.';
				}
				cout << endl;
			}
		}
		
		

		

		// int f = r*c - m;
		// 
		// if (f == 1) {
		// 	for (int j = 0; j < r; ++j) {
		// 		for (int k = 0; k < c; ++k) 
		// 			cout << ((j == r-1 && k == c-1) ? 'c' : '*');
		// 		cout << endl;
		// 	}
		// }
		// else if((c > 1 && r > 1) && f < 4)
		// 	cout << "Impossible" << endl;
		// else {
		// 	int rem = m;
		// 	for (int j = r-1; j > -1; --j) {
		// 		for (int k = c-1; k > -1; --k) {
		// 			if (j == 0 && k == 0) 
		// 				cout << 'c';
		// 			else if (j+k < 2 || (j == 1 && k == 1) || rem == 0)
		// 				cout << '.';
		// 			else {
		// 				cout << '*';
		// 				--rem;
		// 			}
		// 		}
		// 		cout << endl;
		// 	}
		// }

	}

	return 0;
}