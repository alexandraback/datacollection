#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef vector <string> vs;
typedef vector <int> vi;
#define REP(a,b) for(int a=0;a<(b);++a)
#define FOR(a,c,b) for(int a=c;a<(b);++a) 

int h, n, m;
int c[100][100], f[100][100];
int t[100][100];
char v[100][100];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool cango(int r1, int c1, int r2, int c2, int h)
{
	if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m) return false;
	if (h+50>c[r2][c2] || f[r1][c1]+50>c[r2][c2] || f[r2][c2]+50 > c[r2][c2]) return false;
	if (f[r2][c2]+50>c[r1][c1]) return false;
	return true;
}

int whengo(int r1, int c1, int r2, int c2, int h)
{
	if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m) return 999999999;
	if (f[r1][c1]+50>c[r2][c2] || f[r2][c2]+50 > c[r2][c2]) return 999999999;
	if (f[r2][c2]+50>c[r1][c1]) return 999999999;
	int minh = c[r2][c2]-50;
	return max(h-minh,0);
}

int main() 
{
	//ifstream fin("B-small-attempt1.in");
	ifstream fin("B-large.in");
	//ifstream fin("b.in");
	ofstream fout("b.out");

	int tc;

	fin >> tc;

	REP(tcase,tc) {
		fin >> h >> n >> m;

		REP(i,n) REP(j,m) fin >> c[i][j];
		REP(i,n) REP(j,m) fin >> f[i][j];
		REP(i,n) REP(j,m) t[i][j] = 999999999;
		t[0][0] = 0;

		memset(v, 0, sizeof(v));
		priority_queue <pair<int, pair<int,int> > > pq;
		pq.push(make_pair(0,make_pair(0,0)));

		while (!pq.empty()) {
			pair<int, pair<int, int> > pos = pq.top();
			pq.pop();
			pos.first = -pos.first;
			if (v[pos.second.first][pos.second.second]) continue;
			v[pos.second.first][pos.second.second] = 1;
			if (pos.first < t[pos.second.first][pos.second.second])
				t[pos.second.first][pos.second.second] = pos.first;

			REP(i,4) {
				int nx = pos.second.first+dx[i];
				int ny = pos.second.second+dy[i];
				if (v[nx][ny] == 0 && cango(pos.second.first, pos.second.second, nx, ny, 0)) {
					int newt = max(whengo(pos.second.first, pos.second.second, nx, ny, h), t[pos.second.first][pos.second.second]);
					int newh = h-newt;

					if (newt==0);
					else if (newh - f[pos.second.first][pos.second.second] >= 20)
						newt += 10;
					else
						newt += 100;

					if (t[nx][ny] > newt) {
						t[nx][ny] = newt;
						pq.push(make_pair(-t[nx][ny], make_pair(nx,ny)));
					}						
				}
			}
		}


		int res = t[n-1][m-1];
	

		fout << "Case #" << tcase+1 << ": "<< res/10 << "." << res%10 << endl;
	}

	fout.close();

	return 0;
}