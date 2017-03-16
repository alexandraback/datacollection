#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef pair<int, int> PP;
typedef long long LL;
#define pb push_back
#define fr first
#define sc second

void solve(int r, int c, int m){
	char p[50][50];
	for (int i = 0; i < r; i ++) for (int j = 0; j < c; j ++) p[i][j] = '*';
	if (r == 1) {
		if (m < c) {
			cout << "c";
			for (int i = 0; i < c - m - 1; i ++ ) cout << ".";
			for (int i = 0; i < m; i ++) cout << "*";
			cout << endl;
		}
		else cout << "Impossible" << endl;
		return;
	}
	else if (c == 1) {
		if (m < r) {
			cout << "c" << endl;
			for (int i = 0; i < r - m - 1; i ++ ) cout << "." << endl;
			for (int i = 0; i < m; i ++) cout << "*" << endl;
		}
		else cout << "Impossible" << endl;
		return;
	}
	else if (r == 2 || c == 2) {
		m = r * c - m;
		if (m > 1 && (m == 2 || (m & 1))) {
			cout << "Impossible" << endl;
			return;
		}
		if (r == 2){
			for (int i = 0; i < 2; i ++)
				for (int j = 0; j < m / 2; j ++) p[i][j] = '.';
		}
		else {
			for (int i = 0; i < 2; i ++) for (int j = 0; j < m / 2; j ++) p[j][i] = '.';
		}
	}
	else {
		m = r * c - m;
		if (m > 1 && (m == 2 || m == 3|| m == 5 || m == 7)){
			cout << "Impossible" << endl; return;
		}
		if (m > 1){
		p[0][0] = p[1][0] = p[1][1] = p[0][1] = '.'; m -= 4;
		if (m > 1) {
			p[0][2] = p[1][2] = '.'; m -= 2;
		}
		if (m > 1) {
			p[2][0] = p[2][1] = '.'; m -= 2;
		}
		for (int i = 0; i < 2; i ++) for (int j = 0; j < min(m / 2, c - 3); j ++) p[i][j + 3] = '.';
		m -= 2 * min(m / 2, c - 3);
		for (int i = 0; i < 2; i ++) for (int j = 0; j < min(m / 2, r - 3); j ++) p[j + 3][i] = '.';
		m -= 2 * min(m / 2, r - 3);
		int a = 2, b = 2;
		while (m) {
			p[a][b] = '.';
			b ++;
			if (b == c) {
				b = 2; a ++;
			}
			m --;
		}
		}
	}
	p[0][0] = 'c';
	for (int i = 0; i < r; i ++) {
		for (int j = 0; j < c; j ++) cout << p[i][j];
		cout << endl;
	}
}

int main() {
	#ifdef _TEST_
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	int n, r, c, m;
	cin >> n;
	for (int i = 0; i < n; i ++){
		cin >> r >> c >> m;
		cout << "Case #" << i + 1 << ":" << endl;
	//	cout << r << " " << c << " " << m << endl;
		solve(r, c, m);
	}
	return 0;
}
