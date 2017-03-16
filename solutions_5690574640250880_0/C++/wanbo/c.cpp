#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long       LL;
typedef pair<int, int>  PII;
typedef pair<LL, LL>    PLL;
typedef vector<int>     VI;
typedef vector<LL>      VL;
typedef vector<PII>     VPII;
typedef vector<PLL>     VPLL;
#define MM(a,x) memset(a,x,sizeof(a));
#define ALL(x)  (x).begin(), (x).end()
#define P(x)	cerr<<"["#x<<" = "<<(x)<<"]\n"
#define PP(x,i)	cerr<<"["#x<<i<<" = "<<x[i]<<"]\n"
#define P2(x,y)	cerr<<"["#x" = "<<(x)<<", "#y" = "<<(y)<<"]\n"
#define TM(a,b)	cerr<<"["#a" -> "#b": "<<1e3*(b-a)/CLOCKS_PER_SEC<<"ms]\n";
#define UN(v) sort(ALL(v)), v.resize(unique(ALL(v))-v.begin())
#define mp make_pair
#define pb push_back
#define x first
#define y second
struct _ {_() {ios_base::sync_with_stdio(0);}} _;
template<class T> void PV(T a, T b) {while(a != b)cout << *a++, cout << (a != b ? " " : "\n");}
template<class T> inline bool chmin(T &a, T b) {return a > b ? a = b, 1 : 0;}
template<class T> inline bool chmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template<class T> string tostring(T x, int len = 0) {stringstream ss; ss << x; string r = ss.str(); if(r.length() < len) r = string(len - r.length(), '0') + r; return r;}
template<class T> void convert(string x, T& r) {stringstream ss(x); ss >> r;}
template<class A, class B> ostream& operator<<(ostream &o, pair<A, B> t) {o << "(" << t.x << ", " << t.y << ")"; return o;}
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 111111;

int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {1, 0, -1, 1, 0, -1, 1, -1};

int R, C, M;
char s[55][55];


bool check() {
	int cnt = 0;
	for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) if(s[i][j] == '*') cnt++;
	assert(s[0][0] == 'c' && cnt == M);

	bool can[55][55] = {};
	bool b[55][55] = {};

	can[0][0] = 1;

	while(1) {
		int over = 1;
		for(int r = 0; r < R; r++)
			for(int c = 0; c < C; c++) {
				if(!can[r][c]) continue;
				b[r][c] = 1;
				for(int i = 0; i < 8; i++) {
					int x = r + dx[i];
					int y = c + dy[i];
					if(x < 0 || x >= R || y < 0 || y >= C) continue;
					b[x][y] = 1;
					int ok = 1;
					for(int k = 0; k < 8; k++) {
						int tx = x + dx[k];
						int ty = y + dy[k];
						if(tx < 0 || tx >= R || ty < 0 || ty >= C) continue;
						if(s[tx][ty] == '*') ok = 0;
					}
					if(ok && !can[x][y]) {can[x][y] = 1; over = 0;}
				}
			}
		if(over) break;
	}

	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			if(s[i][j] != '*' && !b[i][j]) {P2(R, C); P(M); P2(i, j); return 0;}

	return 1;
}

void output() {
	for(int i = 0; i < R; i++) cout << s[i] << endl;
	assert(check());
}

int main() {
	int T;
	cin >> T;
	for(int ts = 1; ts <= T; ts++) {
		cin >> R >> C >> M;
		int rot = 0;
		if(R > C) swap(R, C), rot = 1;

		int m = R * C - M;

		cout << "Case #" << ts << ":" << endl;
		MM(s, '*');
		if(m == 1) {
		} else if(R == 1) {
			for(int i = 0; i < m; i++) s[0][i] = '.';
		} else if(R == 2) {
			if(m >= 4 && m % 2 == 0) {
				for(int i = 0; i < m / 2; i++) s[0][i] = s[1][i] = '.';
			} else {
				cout << "Impossible" << endl;
				continue;
			}
		} else {
			if(m < 4 || m == 5 || m == 7) {
				cout << "Impossible" << endl;
				continue;
			} else {
				int lx = -1, ly = -1;
				for(int j = 0; j < C; j++) {
					s[0][j] = s[1][j] = '.';
					lx = 0, ly = j;
					m -= 2;
					if(m <= 1) break;
				}

				int lastx = -1;
				int lasty = -1;
				for(int i = 2; i < R && m > 0; i++)
					for(int j = 0; j < C && m > 0; j++)
						s[i][j] = '.', m--, lastx = i, lasty = j;
				if(lasty == 0) {
					if(lastx % 2 == 0) {
						s[lastx][lasty + 1] = '.';
						s[lastx][lasty + 2] = '.';
						for(int i = C - 1; i >= 0; i--) {
							if(s[lastx - 1][i] == '.') {
								s[lastx - 1][i] = '*';
								s[lastx - 2][i] = '*';
								break;
							}
						}
					} else {
						s[lastx - 1][C - 1] = '*';
						s[lastx][lasty + 1] = '.';
					}
				}
			}
		}
		s[0][0] = 'c';
		if(rot) {
			for(int i = 0; i < R; i++)
				for(int j = i; j < C; j++) swap(s[i][j], s[j][i]);
			swap(R, C);
		}
		for(int i = 0; i < R; i++) s[i][C] = 0;
		output();
	}
	return 0;
}
