//Catch me if you can!
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<string>
#include<sstream>
#include<numeric>
#include<complex>
#include<cassert>
#include<queue>
using namespace std;

#define big long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

const int SIZE = 100;
int H, R, C;
int F[SIZE][SIZE], CE[SIZE][SIZE];

bool valid(int r, int c){
	return r >= 0 && r < R && c >= 0 && c < C;
}

struct state{
	int r, c, t;
	bool operator<(const state& st)const{
		return t < st.t;
	}
};
multiset<state> s;
bool vis[SIZE][SIZE][20001];

bool vis1[SIZE][SIZE];

int main(){

	//freopen("1.in", "rt", stdin);
	//freopen("1.out", "wt", stdout);
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("B-small-attempt0.out", "wt", stdout);
	//freopen("A-large.in", "rt", stdin);
	//freopen("A-large.out", "wt", stdout);

	int tt; scanf("%d ", &tt);
	for(int tttt = 0 ; tttt < tt ; tttt++){
		cerr << "Solving testcase " << tttt+1 << endl;

		cin >> H >> R >> C;
		for(int i = 0 ; i < R ; i++)
			for(int j = 0 ; j < C ; j++)
				cin >> CE[i][j];
		for(int i = 0 ; i < R ; i++)
			for(int j = 0 ; j < C ; j++)
				cin >> F[i][j];

		memset(vis, 0, sizeof vis);
		s.clear();
		memset(vis1, 0, sizeof vis1);

		//get starting positions
		queue<pair<int, int> > q1;
		q1.push(make_pair(0, 0));
		vis1[0][0] = true;

		state st = {0, 0, 0};
		s.insert(st);
		vis[0][0][0] = true;

		while(!q1.empty()){
			pair<int, int> p = q1.front(); q1.pop();
			for(int i = 0 ; i < 4 ; i++){
				int r = p.first+dir[i][0];
				int c = p.second+dir[i][1];
				if(!valid(r,c))continue;
				int x = max(H, max(F[p.first][p.second], F[r][c]));
				if(CE[r][c]-x < 50)
					continue;
				if(CE[p.first][p.second]-F[r][c] < 50)
					continue;
				if(!vis1[r][c]){
					vis1[r][c] = true;
					q1.push(make_pair(r,c));

					state st = {r, c, 0};
					s.insert(st);
					vis[r][c][0] = true;
				}
			}
		}

		//BFS
		int res = -1;
		while(!s.empty()){
			state st = *s.begin(); s.erase(s.begin());
			if(st.r == R-1 && st.c == C-1){
				res = st.t;
				break;
			}

			//wait
			state ns = st;
			ns.t++;
			if(!vis[ns.r][ns.c][ns.t]){
				vis[ns.r][ns.c][ns.t] = true;
				s.insert(ns);
			}

			for(int i = 0 ; i < 4 ; i++){
				int r = st.r+dir[i][0];
				int c = st.c+dir[i][1];
				if(!valid(r,c))continue;
				int x = max(F[st.r][st.c], F[r][c]);
				if(CE[r][c]-x < 50)
					continue;
				if(CE[st.r][st.c]-F[r][c] < 50)
					continue;

				int mywaterlevel = max(0, H-st.t);
				if(CE[r][c]-mywaterlevel < 50)
					continue;

				int remainingwater = mywaterlevel-F[st.r][st.c];
				state ns = {r, c, st.t+(remainingwater>=20?10:100)};
				if(!vis[ns.r][ns.c][ns.t]){
					vis[ns.r][ns.c][ns.t] = true;
					s.insert(ns);
				}
			}
		}

		printf("Case #%d: %.9lf\n", tttt+1, (double)(res/10.));

	}

	return 0;
}
