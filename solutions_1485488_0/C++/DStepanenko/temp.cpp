#pragma comment(linker, "/STACK:64000000")
#include <iostream> 
#include <stdio.h> 
#include <cmath> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <queue> 
#include <sstream> 
#include <utility> 
#include <map> 
#include <set> 
#include <memory.h> 
using namespace std; 
 
#define forn(i, n) for(int i = 0; i < (int) (n); ++i) 
#define fore(i, a, b) for(int i = (int) (a); i < (int) (b); ++i) 
 
#define ll long long 
#define ld long double 
#define PLL pair <ld, ld> 
#define PII pair <int, int> 
#define pb push_back 
#define sz size

const ld EPS = 1e-7; 

const int MAXN = 110;

const int MAXS = int(1e6 + 1e-6 + 5);
const ll BASE = int(1e9 + 1e-1 + 7); 
const ld PI = 3.1415926535897932384626433832795; 
const int INF = 1e30;

string s1, s2;
int k;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int c[MAXN][MAXN], f[MAXN][MAXN];
int h, n, m;

bool us[MAXN][MAXN];

int d[MAXN][MAXN];

bool valid(int x, int y){
	return (x > -1 && x < n && y > -1 && y < m);
}


/*
The water level, the floor height of your current square, and the floor height of the adjacent square 
must all be at least 50 centimeters lower than the ceiling height of the adjacent square. 
Note: this means that you will never be able to enter a square with less than 50 centimeters between the floor and the ceiling.

The floor height of the adjacent square must be at least 50 centimeters below the ceiling height of your current square as well.
*/
bool okay(int x, int y, int nx, int ny, int t){
	int H = h - t;

	int q = max(H, f[x][y]);
	q = max(q, f[nx][ny]);

	if (c[nx][ny] - q < 50) return 0;
	if (c[x][y] - f[nx][ny] < 50) return 0;

	return 1;
}

void go(int x, int y){
	forn(k, 4){
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (!valid(nx, ny)) continue;

		if (d[nx][ny] > INF / 2 && okay(x, y, nx, ny, 0)) {
			d[nx][ny] = 0;
			go(nx, ny);
		}
	}
}


int main() 
{ 
     
    freopen("input.txt","rt", stdin); 
    freopen("output.txt", "wt", stdout);     
    
	cout.precision(9);
	cout.setf(ios::fixed);

	int tk;
	cin >> tk;

	forn(ii, tk){
		printf("Case #%d: ", ii + 1);	

		
		cin >> h >> n >> m;

		forn(i, n){
			forn(j, m){
				scanf("%d", &c[i][j]);
			}
		}

		forn(i, n){
			forn(j, m){
				scanf("%d", &f[i][j]);
				d[i][j] = INF;
			}
		}

		memset(us, 0, sizeof us);

		d[0][0] = 0;

		go(0, 0);

		forn(kk, n * m){
			int x = -1, y = -1;
			int nx, ny;

			forn(i, n){
				forn(j, m){
					if (us[i][j] || d[i][j] > INF / 2) continue;

					if (x == -1 || d[x][y] > d[i][j]){
						x = i;
						y = j;
					}
				}
			}

			if (x == -1) break;

			us[x][y] = 1;
			int w;

			forn(k, 4){
				nx = x + dx[k];
				ny = y + dy[k];

				if (!valid(nx, ny)) continue;

				if (d[nx][ny] < d[x][y]) continue;

				if (!okay(x, y, nx, ny, h)) continue;

				int t = c[nx][ny] - 50;

				t = max(t, 0);
				t = h - t;

				t = max(t, d[x][y]);

				if (c[nx][ny] - (h - t) < 50) continue;

				if (h - t - f[x][y] >= 20) w = 1;
				else
					w = 10;

				if (d[nx][ny] > d[x][y] + w) d[nx][ny] = t + w * 10;
			}
		}

		cout << d[n - 1][m - 1] / 10 << "." << d[n - 1][m - 1] % 10 << endl;
	}
	

	return 0; 
}