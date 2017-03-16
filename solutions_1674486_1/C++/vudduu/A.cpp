#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define MP          make_pair
#define S           size()
typedef long long   LL;

vector<vector<int> > G;
int vis[1005];

bool bfs(int x){
	memset(vis, 0, sizeof(vis));
	stack<int> st;
	st.push(x);
	while(!st.empty()){
		x = st.top();
		st.pop();
		if(vis[x]) return true;
		vis[x] = 1;
		F(i, G[x].S){
			st.push(G[x][i]);
		}
	}
	return false;
}

void solve(int caso){
	int N, M, x, y;
	scanf("%d", &N);
	G = vector<vector<int> > (N);
	F(i, N){
		scanf("%d", &M);
		F(j, M){
			scanf("%d", &x);
			G[i].PB(x-1);
		}
	}
	F(i, N){
		if(bfs(i)){
			cout<<"Case #"<<caso<<": Yes"<<endl;
			return;
		}
	}
	cout<<"Case #"<<caso<<": No"<<endl;
}

int main(){
	//freopen("a.in", "r", stdin);
	//freopen("A-small-attempt0.in.txt", "r", stdin);
	freopen("A-large.in.txt", "r", stdin);
	freopen("a.out", "w", stdout);
	int T;
	scanf("%d", &T);
	F(i, T){ solve(i+1); }
}

