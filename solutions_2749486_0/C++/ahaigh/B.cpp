#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <queue>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
#include <cassert>
#include <set>
#include <iomanip>
using namespace std;

#include "gmpxx.h"
typedef mpz_class big;

#define REP(i,n) for(int i = 0; i < n; i++)
#define CL(x) memset(x, 0, sizeof(x))
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MP make_pair
#define PB push_back

const int X = 10;
int T; //, dist[X][X][X], par[X][X][X], dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

int main() {
	/*REP(i,X) REP(j, X) REP(k, X) dist[i][j][k] = -1;
	queue<pair<pii,int> > q; q.push(MP(MP(0,0),0)); dist[0][0][0] = 0;
	
	while (!q.empty()) {
		int x = q.front().first.first, y = q.front().first.second, mv = q.front().second;
		q.pop();
		cout << x << " " <<  y << " " << mv << " " << dist[x][y][mv] << " " << endl;
		REP(k,4) {
			int xn = x + dx[k] * mv, yn = y + dy[k] * mv;
			xn = abs(xn);
			yn = abs(yn);
			if (xn >= 0 && yn >= 0 && xn < X && yn < X && mv+1 < X  && dist[xn][yn][mv+1] == -1) {
				par[xn][yn][mv+1] = k;
				dist[xn][yn][mv+1] = dist[x][y][mv] + 1;
				q.push(MP(MP(xn,yn),mv+1));
			}
		}
	}*/
		
	cin >> T;
	REP(tttt,T) {
		int x, y;
		cin >> x >> y;
		
		int cx = 0, cy = 0, k = 1;
		cout << "Case #" << (tttt+1) << ": ";
		while (cx != x || cy != y) {
			if (cx != x) {
				if (cx > x) cout << "EW", cx--, k+=2;
				else cout << "WE", cx++, k+=2;
			} else {
				if (cy > y) cout << "NS", cy--, k+=2;
				else cout << "SN", cy++, k+=2;
			}
		}
		cout << endl;
		
		/*int best = -1;
		REP(k,X) {
			cout << dist[x][y][k] << " ";
			if (dist[x][y][k] != -1 && (best == -1 || dist[x][y][best] > dist[x][y][k])) best = k;
		}
		cout << endl;
		cout << best << " " << dist[x][y][best] << endl;
		
		int k = best;
		REP(i,best) {
			bool flag = false;
			REP(q,4) {
				if (!flag) {
					int xn = abs(x - k*dx[q]);
					int yn = abs(y - k*dy[q]);
					if (dist[xn][yn][k-1] != -1) {
						cout << q << " " << xn << " " << yn << " " << dist[xn][yn][k-1] << endl;
						flag = true;
						x = xn;
						y = yn;
						k--;
					}
				}
			}
			
			int dir = par[x][y][k];
			cout << "!" << x << " " << y << " " << k << " " << dir << endl;
			x -= k*dx[dir];
			y -= k*dy[dir];
			x = abs(x);
			y = abs(y);
			k --;
			cout << dir << " ";
		}
		cout << endl; */
	}
}
