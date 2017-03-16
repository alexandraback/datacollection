#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>

#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld epsylon = 1e-9;
typedef unsigned int ui;
inline long double get_time(){   
	return (long double)clock()/CLOCKS_PER_SEC;
};
ld start_time,end_time;

string IMPOS = "\nImpossible";

int MOVES[8][2] = {
	{0,1},{0,-1},{1,0},{-1,0},
	{1,1},{1,-1},{-1,1},{-1,-1}
};

bool vis[55][55];

vector <pair <int, int> > unvis_nbs(int i, int j, int rows, int cols) {
	vector <pair <int, int> > res;
	for (int nbmv=0; nbmv<8;++nbmv) {
		int nx=i+MOVES[nbmv][0];
		int ny=j+MOVES[nbmv][1];
		//chck valid
		if (nx>-1&&ny>-1&&nx<rows&&ny<cols&&!vis[nx][ny]) {
			res.push_back(make_pair(nx,ny));	
		}
	}
	return res;
}

bool can_make_zero(int i, int j, int rows, int cols, int empt) {
	return unvis_nbs(i,j,rows,cols).size() <=empt;
}
int make_zero(int i,int j,int rows, int cols, stack<pair<int, int> >& st) {
	int res = 0;
	for (int nbmv=0; nbmv<8;++nbmv) {
		int nx=i+MOVES[nbmv][0];
		int ny=j+MOVES[nbmv][1];
		//chck valid
		if (nx>-1&&ny>-1&&nx<rows&&ny<cols&&!vis[nx][ny]) {
			vis[nx][ny] = 1;
			st.push(make_pair(nx,ny));
			res++;
		}
	}
	return res;
}
int make_zero(int i,int j,int rows, int cols, queue<pair<int, int> >& st) {
	int res = 0;
	for (int nbmv=0; nbmv<8;++nbmv) {
		int nx=i+MOVES[nbmv][0];
		int ny=j+MOVES[nbmv][1];
		//chck valid
		if (nx>-1&&ny>-1&&nx<rows&&ny<cols&&!vis[nx][ny]) {
			vis[nx][ny] = 1;
			st.push(make_pair(nx,ny));
			res++;
		}
	}
	return res;
}

string do_from_map(int fromi, int fromj, int rows, int cols) {
	string res;
	res.push_back('\n');
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (i==fromi&&j==fromj) {
				res.push_back('c');
			} else {
				res.push_back(vis[i][j]?'.':'*');
			}
		}
		if (i<rows-1){
			res.push_back('\n');
		}
	}
	return res;
}

string bfs(int i, int j, int rows, int cols, int empt) {
	memset(vis, 0, sizeof(vis));
	vis[i][j] = 1;
	empt--;
	stack<pair<int,int> > st;
	st.push(make_pair(i,j));

	while (!st.empty()) {
		pair<int, int> tp = st.top(); st.pop();
		if (can_make_zero(tp.first,tp.second,rows,cols,empt)) {
			empt-=make_zero(tp.first,tp.second,rows,cols, st);
			if (empt==0) {
				return do_from_map(i,j,rows,cols);
			}
		}
	}
	return empt ? IMPOS : do_from_map(i,j,rows,cols);;
}

string dfs(int i, int j, int rows, int cols, int empt) {
	memset(vis, 0, sizeof(vis));
	vis[i][j] = 1;
	empt--;
	queue<pair<int,int> > st;
	st.push(make_pair(i,j));

	while (!st.empty()) {
		pair<int, int> tp = st.front(); st.pop();
		if (can_make_zero(tp.first,tp.second,rows,cols,empt)) {
			empt-=make_zero(tp.first,tp.second,rows,cols, st);
			if (empt==0) {
				return do_from_map(i,j,rows,cols);;
			}
		}
	}
	return empt ? IMPOS : do_from_map(i,j,rows,cols);;
}

string solve() {
	int r,c,m;
	cin >> r >> c >> m;
	string res = IMPOS;
	int empt = r*c-m;
	for (int i = 0; i < r; ++i){
		for (int j = 0; j < c; ++j) {
			res = bfs(i,j, r ,c, empt);
			if (res != IMPOS) {
				return res;
			}
			res = dfs(i,j, r ,c, empt);
			if (res != IMPOS) {
				return res;
			}
		}
	}
	return res;
}



int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	//start_time = get_time();
	//program
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		printf("Case #%d: %s\n", test ,solve().c_str()); 
	}


	//end program
	//end_time=get_time()-start_time;
	return 0;
}




