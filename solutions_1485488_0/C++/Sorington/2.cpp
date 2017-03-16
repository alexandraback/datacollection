#include<iostream>
#include<vector>
#include<map>
#include<fstream>
#include<algorithm>
#include<iomanip>
#include<queue>

using namespace std;

int posi[] = {1,0,-1,0};
int posj[] = {0,1,0,-1};

typedef pair<int,int> pii;
typedef pair<pii,int> pipii;
typedef pair<double,double> pdd;
typedef pair<double,pii > pdpii;
typedef vector<bool> vb;
typedef vector<vb > vvb;
long double EPS = 0.00000001;

int main()
{
	ifstream fin ("in.in");
	ofstream fout ("out.out");
	int caso = 1;
	int T;
	fin >> T;
	
	for (; T > 0; T--)
	{
		int h, n, m;
		fin >> h >> n >> m;
		vector<vector<double> > F (n, vector<double> (m)), C (n, vector<double> (m));
		vvb blk (n, vb (m, false));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				fin >> C[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				fin >> F[i][j];
				if (C[i][j]-F[i][j] < 50) blk[i][j] = true;
			}
		}
		
		vvb vis (n, vb(m, false));
		vis[0][0] = true;
		queue<pii > q;
		priority_queue<pdpii > pq;
		q.push(pii(0,0));
		pq.push(pdpii(0,pii(0,0)));
		vector<vector<double> > res (n, vector<double> (m, -1));
		res[0][0] = 0;
		
		while (!q.empty())
		{
			int i = q.front().first, j = q.front().second;
			q.pop();
			for (int z = 0; z < 4; z++)
			{
				int y = i+posi[z], x = j+posj[z];
				if (y < 0 || y >= n || x < 0 || x >= m || vis[y][x] || blk[y][x] || h > C[y][x]-50 || F[i][j] > C[y][x]-50 || C[i][j]-50 < F[y][x]) continue;
				vis[y][x] = true;
				q.push(pii(y,x));
				pq.push(pdpii(0,pii(y,x)));
				res[y][x] = 0;
			}
		}
		
		if (res[n-1][m-1] == -1)
		{
			while (!pq.empty())
			{
				int i = pq.top().second.first, j = pq.top().second.second;
				double t = -pq.top().first;
				pq.pop();
				if (i == n-1 && j == m-1) break;
				if (t > res[i][j]+EPS) continue;
				for (int z = 0; z < 4; z++)
				{
					int y = i+posi[z], x = j+posj[z];
					if (y < 0 || y >= n || x < 0 || x >= m || blk[y][x] || F[i][j] > C[y][x]-50 || C[i][j]-50 < F[y][x]) continue;
					double nt;
					double hact = h-(10*t);
					double hneed = C[y][x]-50;
					if (hact <= hneed)
					{
						double vel;
						if (hact >= F[i][j]+20) vel = 1;
						else vel = 10;
						nt = t+vel;
					}
					else
					{
						double tneed = (hact-hneed)/10.0;
						double vel;
						if (hneed >= F[i][j]+20) vel = 1;
						else vel = 10;
						nt = t+tneed+vel;
					}
					if (res[y][x] < nt && res[y][x] != -1) continue;
					pq.push(pdpii(-nt,pii(y,x)));
					res[y][x] = nt;
				}
			}
		}
		
		fout << "Case #" << caso << ": " << setprecision(6) << fixed << showpoint << res[n-1][m-1] << endl;
		caso++;
	}
}
