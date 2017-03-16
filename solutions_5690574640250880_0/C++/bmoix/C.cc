#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;
typedef pair<int,int> pii;

int R,C,M;
VVC solution, map;
bool found;

int find_mine(const VVC & m, int i, int j) {
	int ans = 0;
	if (i-1 >= 0 and i-1 < R and j >= 0 and j < C and m[i-1][j] == '*') ans++;
	if (i+1 >= 0 and i+1 < R and j >= 0 and j < C and m[i+1][j] == '*') ans++;
	if (i >= 0 and i < R and j-1 >= 0 and j-1 < C and m[i][j-1] == '*') ans++;
	if (i >= 0 and i < R and j+1 >= 0 and j+1 < C and m[i][j+1] == '*') ans++;
	if (i-1 >= 0 and i-1 < R and j-1 >= 0 and j-1 < C and m[i-1][j-1] == '*') ans++;
	if (i-1 >= 0 and i-1 < R and j+1 >= 0 and j+1 < C and m[i-1][j+1] == '*') ans++;
	if (i+1 >= 0 and i+1 < R and j-1 >= 0 and j-1 < C and m[i+1][j-1] == '*') ans++;
	if (i+1 >= 0 and i+1 < R and j+1 >= 0 and j+1 < C and m[i+1][j+1] == '*') ans++;
	return ans;
}

bool check(int i, int j) {
	VVC m = map;
	queue<pii> q;
	int count = 0;
	q.push(pair<int,int>(i,j));
	while (not q.empty()) {
		count++;
		i = q.front().first;
		j = q.front().second;
		q.pop();
		m[i][j] = '0' + find_mine(m,i,j);
		if (m[i][j] == '0') {
			if (i-1 >= 0 and i-1 < R and j >= 0 and j < C and m[i-1][j] == '.') { q.push(pair<int,int>(i-1,j)); m[i-1][j] = 'x'; }
			if (i+1 >= 0 and i+1 < R and j >= 0 and j < C and m[i+1][j] == '.') { q.push(pair<int,int>(i+1,j)); m[i+1][j] = 'x'; }
			if (i >= 0 and i < R and j-1 >= 0 and j-1 < C and m[i][j-1] == '.') { q.push(pair<int,int>(i,j-1)); m[i][j-1] = 'x'; }
			if (i >= 0 and i < R and j+1 >= 0 and j+1 < C and m[i][j+1] == '.') { q.push(pair<int,int>(i,j+1)); m[i][j+1] = 'x'; }
			if (i-1 >= 0 and i-1 < R and j-1 >= 0 and j-1 < C and m[i-1][j-1] == '.') { q.push(pair<int,int>(i-1,j-1)); m[i-1][j-1] = 'x'; }
			if (i-1 >= 0 and i-1 < R and j+1 >= 0 and j+1 < C and m[i-1][j+1] == '.') { q.push(pair<int,int>(i-1,j+1)); m[i-1][j+1] = 'x'; }
			if (i+1 >= 0 and i+1 < R and j-1 >= 0 and j-1 < C and m[i+1][j-1] == '.') { q.push(pair<int,int>(i+1,j-1)); m[i+1][j-1] = 'x'; }
			if (i+1 >= 0 and i+1 < R and j+1 >= 0 and j+1 < C and m[i+1][j+1] == '.') { q.push(pair<int,int>(i+1,j+1)); m[i+1][j+1] = 'x'; }
		}
	}
	return (count == (R*C)-M);
}

void bck(int i, int j, int count) {
	if (found) return;
	if (i == R-1 and j == C and count == M) {
		for (int x = 0; x < R and not found; x++) {
			for (int y = 0; y < C and not found; y++) {
				if (map[x][y] == '.') {
					found = check(x,y);
					if (found) map[x][y] = 'c';
				}
			}
		}
	}
	else {
		if (j == C) { i++; j = 0; }
		if (i < R) {
			if (count < M) {
				map[i][j] = '*';
				bck(i,j+1,count+1);
			}
			if (not found) {
				map[i][j] = '.';
				bck(i,j+1,count);
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		
		cin >> R >> C >> M;
		map = VVC (R, VC(C, '.'));
		found = false;
		bck(0,0,0);
		cout << "Case #" << cas << ":" << endl;
		if (found) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					cout << map[i][j];
				}
				cout << endl;
			}
		}
		else cout << "Impossible" << endl;
	}
}