#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <limits>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef vector<vector<int> > graph;

const double pi = acos(-1.0);

#define oned(a, x1, x2) { cout << #a << ":"; for(int _i = (x1); _i < (x2); _i++){ cout << " " << a[_i]; } cout << endl; }
#define twod(a, x1, x2, y1, y2) { cout << #a << ":" << endl; for(int _i = (x1); _i < (x2); _i++){ for(int _j = (y1); _j < (y2); _j++){ cout << (_j > y1 ? " " : "") << a[_i][_j]; } cout << endl; } }

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

int TESTS, CASE;

int n, m, k;

char s[55][55];

bool nil[55][55];

bool isNil(int i, int j) {
	for(int dx = -1; dx <= 1; dx++) {
		for(int dy = -1; dy <= 1; dy++) {
			int x = i+dx;
			int y = j+dy;
			if(x>=0&&x<n&&y>=0&&y<m&&s[x][y]!='.') {
				return false;
			}
		}
	}
	return true;
}

bool reach(int i, int j) {
	for(int dx = -1; dx <= 1; dx++) {
		for(int dy = -1; dy <= 1; dy++) {
			int x = i+dx;
			int y = j+dy;
			if(x>=0&&x<n&&y>=0&&y<m&&nil[x][y]) {
				return true;
			}
		}
	}
	return false;
}

void solve() {
	cout << "Case #" << ++CASE << ":" << endl;
	
	memset(s,'*',sizeof(s));
	
	k = n*m-k;
	
	if(k==1) {
		s[0][0] = '.';
	} else if(n==1 || m==1) {
		for(int i = 0; i < n && k; i++) {
			for(int j = 0; j < m && k; j++) {
				s[i][j] = '.';
				k--;
			}
		}
	} else if(k==2||k==3||k==5||k==7) {
		cout << "Impossible" << endl;
		return;
	} else if(n==2 || m==2) {
		if(k&1) {
			cout << "Impossible" << endl;
			return;
		} else {
			for(int i = 0; i < k/2; i++) {
				if(n==2) {
					s[0][i] = s[1][i] = '.';
				} else {
					s[i][0] = s[i][1] = '.';
				}
			}
		}
	} else {
		for(int i = 0; i < n && k; i++) {
			for(int j = 0; j < m && k; j++) {
				s[i][j] = '.';
				k--;
			}
		}
		while(true) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					nil[i][j] = isNil(i,j);
				}
			}
			bool cool = true;
			for(int i = 0; i < n && cool; i++) {
				for(int j = 0; j < m && cool; j++) {
					if(s[i][j]=='.' && !nil[i][j] && !reach(i,j)) {
						cool = false;
					}
				}
			}
			if(cool) {
				break;
			}
			bool ok = true;
			for(int j = m-1; j >= 0 && ok; j--) {
				for(int i = n-1; i >= 0 && ok; i--) {
					if(s[i][j]=='.') {
						int y = j-1;
						int x = n-1;
						
						while(s[x][y] != '.') {
							x--;
						}
						x++;
						while(y>=0 && s[x][y]!='.') {
							y--;
						}
						y++;
						
						s[i][j] = '*';
						s[x][y] = '.';
						
						ok = false;
					}
				}
			}
		}
	}
	
	s[0][0] = 'c';
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << s[i][j];
		}
		cout << endl;
	}
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> TESTS;
	for(int i = 0; i < TESTS; i++) {
		cin >> n >> m >> k;
		solve();
	}
}
