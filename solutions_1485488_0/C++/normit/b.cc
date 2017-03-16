#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back

#define REP(i,n) for(int i=0; i < (n); ++i)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

int h,n,m;
static int dx[4] = {-1, 0, 1, 0};
static int dy[4] = {0, -1, 0, 1};

struct Tile
{
	int ceil;
	int floor;
};


struct Node
{
	Node(int r, int c, int t) {
		row = r;
		col = c;
		time = t;
	}
	int fr;
	int fc;

	int row;
	int col;
	int time;

	bool operator < (const Node &o) const {
		return time > o.time;
	}
};


Tile tiles[110][110];
int checked[110][110];
int from[110][110];

void solve()
{

	cin >> h >> n >> m;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> tiles[i][j].ceil;
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> tiles[i][j].floor;
			checked[i][j] = -1;
		}
	}

	priority_queue<Node> pq;
	checked[0][0] = 0;
	pq.push(Node(0,0,0));

	while(!pq.empty()) {
		Node node = pq.top();
		pq.pop();
		int row = node.row;
		int col = node.col;



		if(checked[row][col] == 1) continue;
		checked[row][col] = 1;
		from[row][col] = node.fr;
		//cout << row << "," << col << " : " << node.time << endl;
		if(row == n-1 && col == m-1) {
			cout << (double)node.time/10.0 << endl;
/*
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < m; ++j) {
					cout << from[i][j] << " ";
				}
				cout << endl;
			}
*/
			return;
		}



		for(int k = 0; k < 4; ++k) {
			int cur_time = node.time;
			int nr = row + dx[k];
			int nc = col + dy[k];
			if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
			int need_height = tiles[nr][nc].ceil - 50;

			if(tiles[nr][nc].floor > need_height) continue;
			if(tiles[row][col].floor > need_height) continue;
			if(tiles[row][col].ceil-50 < tiles[nr][nc].floor) continue;
			
			int need_time = h - need_height;
			if(need_time < 0) need_time = 0;
			need_time = std::max(need_time, cur_time);

			//int new_need_time = h - (tiles[row][col].ceil-50);
			//need_time = std::max(need_time, new_need_time);

			int next_time = 0;
			if(need_time > 0) {
				if((h - need_time) >= tiles[row][col].floor + 20) {
					next_time = need_time + 10;
				}
				else next_time = need_time + 100;
			}
			if(checked[nr][nc] ==1) continue; //>= 0 && checked[nr][nc] < next_time) continue;
			checked[nr][nc] = next_time;
			Node new_node = Node(nr,nc,next_time);
			new_node.fr = k;
			pq.push(new_node);
		}

	}
}

int main(int argc, char *argv[])
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

