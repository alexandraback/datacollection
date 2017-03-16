#include <cstdio>
#include <queue>
#include <string>
#include <bitset>
#include <cassert>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
using namespace std;
#include <iostream>
#include <map>
#include <cmath>

//By chyx111
#define DBG(a) do{cerr << #a << ": " << (a) << endl;}while(0)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) ((int)(a).size())
#define REP(i,n) for(int n_##__LINE__ = (n), i = 0; i < n_##__LINE__; ++i)
template<class T> ostream& operator<<(ostream& os, vector<T> v){
	REP (i, v.size()){
		if(i){
			os << ' ';
		}
		os << v[i];
	}
	return os;
};

int const N = 128;
double level;
double eps = 1e-6;
struct Node{
	int ceil_height;
	int floor_height;
	int i, j;
	int type;
	double cost;
	void set_type(int level)
	{
		if(level - floor_height >= 20){
			type = 1;
		}else{
			type = 2;
		}
	}
	bool operator<(Node const& other)const
	{
		return cost > other.cost;
	}
};
Node maze[N][N];
double best[N][N];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

double solve()
{
	REP (i, n) REP (j, m)best[i][j] = 1e20;
	priority_queue<Node> Q;
	maze[0][0].cost = 0;
	best[0][0] = 0;
	Q.push(maze[0][0]);
	while(!Q.empty()){
		Node curr = Q.top(); Q.pop();
		Node next;
		if(curr.i == n - 1 && curr.j == m - 1){
			return curr.cost;
		}
		REP (d, 4){
			int i = curr.i + dx[d];
			int j = curr.j + dy[d];
			next = maze[i][j];
			if(0 <= i && i < n
					&& 0 <= j && j < m){
				if(curr.ceil_height - next.floor_height < 50){
					continue;
				}
				if(next.ceil_height - next.floor_height < 50){
					continue;
				}
				if(next.ceil_height - curr.floor_height < 50){
					continue;
				}
				if(next.ceil_height - (level - curr.cost) >= 50){
					curr.set_type(level - curr.cost);
					if(curr.type == 1){
						next.cost = curr.cost + 10;
					}else if(curr.type == 2){
						next.cost = curr.cost + 100;
					}
					if(fabs(curr.cost) < eps)next.cost = 0;
					if(next.cost < best[i][j]){
						Q.push(next);
						best[i][j] = next.cost;
					}
				}else{
					int wait_time = (level - curr.cost) - (next.ceil_height - 50);
					curr.set_type(next.ceil_height - 50);
					if(curr.type == 1){
						next.cost = curr.cost + 10 + wait_time;
					}else if(curr.type == 2){
						next.cost = curr.cost + 100 + wait_time;
					}
					if(next.cost < best[i][j]){
						Q.push(next);
						best[i][j] = next.cost;
					}
				}
			}
		}
	}
}

int main() {
	int ca;
	scanf("%d", &ca);
	REP (ica, ca){
		scanf("%lf", &level);
		scanf("%d%d", &n, &m);
		REP (i, n) REP (j, m){
			scanf("%d", &maze[i][j].ceil_height);
		}
		REP (i, n) REP (j, m){
			scanf("%d", &maze[i][j].floor_height);
		}
		REP (i, n) REP (j, m){
			maze[i][j].i = i;
			maze[i][j].j = j;
			maze[i][j].set_type(level);
		}

		double ans = solve();
		printf("Case #%d: %.10f\n", ica + 1, ans / 10);
		
		//REP (i, n) {
		//	REP (j, m){
		//		cout << best[i][j] << " ";
		//	}
		//	cout << endl;
		//}
	}
	return 0;
}

