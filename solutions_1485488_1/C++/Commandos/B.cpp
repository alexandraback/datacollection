#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <fstream>
#include <iostream>
#include <queue>
#include <algorithm>
#include <time.h>
#include <sstream>
#include <assert.h>
#include <limits>
#define _USE_MATH_DEFINES
#include <math.h>

#define pb(a) push_back(a)
#define sz size()
#define ALL(a) a.begin(),a.end()
#define ALLR(a) a.rbegin(),a.rend()
#define X first
#define Y second
#define mp(a,b) make_pair(a,b)

typedef long long ll;
typedef long double ld;

template<typename T> inline void SWAP(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}
template<typename T> inline T ABS(const T &VAL) {
	return VAL < 0 ? -VAL : VAL;
}
template<typename T> inline T MAX(const T &a, const T &b) {
	return a < b ? b : a;
}
template<typename T> inline T MIN(const T &a, const T &b) {
	return a < b ? a : b;
}
template<typename T> inline T SQR(const T &a) {
	return a * a;
}

#define MSET(d) memset(d,0,sizeof(d))
#define forn(i,n) for(int i=0;i!=n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forab(i,a,b) for(int i=a;i!=b;i++)
#define for1ab(i,a,b) for(int i=a+1;i<=b;i++)
#define fordab(i,a,b) for(int i=b-1;i>=a;i--)
#define ford1ab(i,a,b) for(int i=b;i!=a;i--)
#define ford(i,n) for(int i=n-1;i!=-1;i--)
#define ford1(i,n) for(int i=n;i!=0;i--)

//const int INTinf = 2147483647;
const int INTinf = 1000000005;
const int nINTinf = 0 - 2147483648;
const ll LLinf = 9223372036854775807LL;

using namespace std;
typedef pair<int, int> pii;
typedef unsigned int uint;

int n, t, h, m;
pii A[105][105];
ld met[105][105];
const ld TT = 1e10;
vector<pii> que;
int dx[2][4] = { { 1, -1, 0, 0 }, { 0, 0, -1, 1 } };
bool checkXY(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}
bool check(const pii &q, const pii &w) {
	return ((w.X - w.Y >= 50) && (w.X - h >= 50) && (w.X - q.Y >= 50) && (q.X - w.Y >= 50));
}
ld getTime(ld time, const pii &q, const pii &w) {
	if ((w.X - w.Y >= 50) && (w.X - q.Y >= 50) && (q.X - w.Y >= 50)) {
		ld lvl = MAX((ld) 0, h - time * 10);
		if (w.X - lvl < 50) {
			lvl = (w.X - 50);
			time = (h - lvl) / 10.0;
		}
		if (lvl - q.Y >= 20) {
			return time + 1;
		} else {
			return time + 10;
		}
	} else {
		return TT;
	}
}
priority_queue<pair<ld, pii> , vector<pair<ld, pii> > , greater<pair<ld, pii> > > pq;
int main() {
#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	cout.setf(ios_base::fixed);
	cout.precision(8);
	cin >> t;
	for1(xx,t) {
		cin >> h >> n >> m;
		forn(i,n) {
			forn(j,m) {
				cin >> A[i][j].X;
				met[i][j] = TT;
			}
		}
		forn(i,n) {
			forn(j,m) {
				cin >> A[i][j].Y;
			}
		}
		met[0][0] = 0;
		que.clear();
		que.pb(pii(0,0));
		pq.push(mp((ld)0, pii(0,0)));
		while (!que.empty()) {
			pii top = que.back();
			que.pop_back();
			forn(i,4) {
				int nx = top.X + dx[0][i];
				int ny = top.Y + dx[1][i];
				if (checkXY(nx, ny)) {
					if (met[nx][ny] != 0) {
						if (check(A[top.X][top.Y], A[nx][ny])) {
							met[nx][ny] = 0;
							que.pb(pii(nx,ny));
							pq.push(mp((ld)0, pii(nx,ny)));
						}
					}
				}
			}
		}
		while (!pq.empty()) {
			pair<ld, pii> top = pq.top();
			pq.pop();
			if (met[top.Y.X][top.Y.Y] == top.X) {
				forn(i,4) {
					int nx = top.Y.X + dx[0][i];
					int ny = top.Y.Y + dx[1][i];
					if (checkXY(nx, ny)) {
						ld tm = getTime(top.X, A[top.Y.X][top.Y.Y], A[nx][ny]);
						if (tm < met[nx][ny]) {
							met[nx][ny] = tm;
							pq.push(mp(tm, pii(nx,ny)));
						}
					}
				}
			}
		}
		cout << "Case #" << xx << ": " << met[n - 1][m - 1] << endl;
	}
#ifndef ONLINE_JUDGE
	fclose(stdout);
	fclose(stdin);
#endif
	return 0;
}
