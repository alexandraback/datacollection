#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>

using namespace std;

#define FOR(i,a,b)  for(int i=(a);i<(b);++i)
#define REP(i,a)    FOR(i,0,a)
#define ZERO(m)     memset(m,0,sizeof(m))
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define S           size()
#define LL          long long
#define LD          long double
#define MP          make_pair
#define X           first
#define Y           second
#define VC          vector
#define PII			pair <int, int>
#define VI          VC<int>
#define VPII		VC < PII >
#define VS          VC<string>
#define DB(a)		cout << #a << ": " << a << endl;

void print(VI v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]\n";}
void print(VS v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]\n";}
template<class T> string i2s(T x) {ostringstream o; o << x; return o.str(); }
VS splt(string s, char c = ' ') {VS rv; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) rv.PB(s.substr(p, np - p)); p = np + 1;} if (p < s.S) rv.PB(s.substr(p)); return rv;}

int F[101][101];
int C[101][101];
int V[101][101];

int H, N, M;

#define PX pair < int, PII >

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main() {
	int tc;
	cin >> tc;
	FOR(atc, 1, tc + 1) {
		cin >> H >> N >> M;
		REP(i, N) REP(j, M) cin >> C[i][j];
		REP(i, N) REP(j, M) cin >> F[i][j];
		
		REP(i, N) REP(j, M) V[i][j] = 1 << 25;
		
		priority_queue < PX, VC < PX >, greater < PX > > pq;
		pq.push(MP(0, MP(0, 0)));
		
		int rv = -1;
		while (!pq.empty()) {
			PX p = pq.top(); pq.pop();
			
			int c = p.X;
			int x = p.Y.X;
			int y = p.Y.Y;
			
			if (V[x][y] <= c) continue;
			V[x][y] = c;
			
			if (x == N - 1 && y == M - 1) {
				rv = c;
				break;
			}
			
			REP(d, 4) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (C[nx][ny] < F[x][y] + 50 || C[nx][ny] < F[nx][ny] + 50 || F[nx][ny] > C[x][y] - 50) continue;
				int t = H - C[nx][ny] + 50;
				t = max(t, c);
				if (t) t += (H - t < F[x][y] + 20 ? 100 : 10);
				pq.push(MP(t, MP(nx, ny)));				
			}
		}
		
		printf("Case #%d: %.1f\n", atc, rv / 10.0);
	}
}