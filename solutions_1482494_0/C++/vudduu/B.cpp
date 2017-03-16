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

int N;
vector<int> a, b;
map<vector<int>, int> memo;

int dfs(vector<int> v, int points){
	if(points == N*2) return 0;
	if(memo.find(v) != memo.end()) return memo[v];
	int r = 1000000000, sol;
	F(i, N){
		if(v[i] == 2) continue;
		int ante = v[i];
		if(points >= b[i]){
			v[i] = 2;
			if(ante == 1){
				sol = dfs(v, points + 1) + 1;
				r = min(r, sol);
				v[i] = ante;
			}
			if(ante == 0){
				sol = dfs(v, points + 2) + 1;
				r = min(r, sol);
				v[i] = ante;
			}
		}
		if(points >= a[i] && v[i] == 0){
			v[i] = 1;
			sol = dfs(v, points + 1) + 1;
			r = min(r, sol);
			v[i] = 0;
		}
	}
	memo[v] = r;
	return r;
}

void solve(int caso){
	scanf("%d", &N);
	memo.clear();
	a = b = vector<int> (N);
	F(i, N) scanf("%d %d", &a[i], &b[i]);
	int res = dfs(vector<int> (N, 0), 0);
	if(res == 1000000000) cout<<"Case #"<<caso<<": Too Bad"<< endl;
	else cout<<"Case #"<<caso<<": "<< res << endl;
}

int main(){
	//freopen("a.in", "r", stdin);
	freopen("B-small-attempt3.in.txt", "r", stdin);
	//freopen("B-large.in.txt", "r", stdin);
	freopen("a.out", "w", stdout);
	int T;
	scanf("%d", &T);
	F(i, T){ solve(i+1); }
}

