#include <bits/stdc++.h>
/*
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
*/
using namespace std;

typedef long long ll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;

#define mp make_pair
#define pb push_back

#define fi first
#define se second

#define repp(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define rep(i,n) repp(i,0,(n)-1)

void visit(int now, vint &f, int &lc, int cnt, int origin, vint &visited){
cerr << "now: " << now << endl;
	visited[now] = 1;
	if(f[now] == origin){
		lc = max(lc, cnt);
cerr << "lc := " << lc << endl;
	}else{
		if( visited[f[now]] == 0 )
			visit(f[now], f, lc, cnt + 1, origin, visited);
//		visited[i] = cnt++;
//		visit(f[i], f, visited, lc, cnt);
	}
}

int longest( int now, vector<vint> &g, vint &f){
	int res = 0;
	rep(i, g[now].size()){
		if( f[now] != g[now][i] ){
			res = max(res, longest( g[now][i], g, f ) + 1);
		}
	}
	return res;
}

void main2(){
	int n; cin >> n;
	vint f(n + 1);
	vector< vint > g(n + 1);
	rep(i, n){
		scanf("%d", &f[i + 1]);
		g[ f[i + 1] ].pb(i + 1);
	}
repp(i, 1, n){
	cerr << "i=" << i << "; "; 
	rep(j, g[i].size()) cerr << g[i][j] << " "; cerr << endl;
}
	int ans = 0;
	int lc = 0;
	//vector<int> visited(n+1, 0);
	//int cnt = 1;
	repp(i, 1, n){
cerr << "loop " << i << endl;
		vint visited(n + 1, 0);
		visit(i, f, lc, 1, i, visited);
	}
//repp(i, 1, n) cerr << "i: " << i << ", vis[i]: " << visited[i] << endl;
cerr << "lc: " << lc << endl;

	
	repp(i, 1, n){
		if(f[f[i]] == i && i < f[i]){
			ans += 2 + longest(i, g, f) + longest(f[i], g, f);
cerr << "(i, f[i], l(i), l(f[i])) = " << i << " " << f[i] << " " << longest(i,g,f) << " " << longest(f[i],g,f) << endl;
		}
	}
	cout << max(ans, lc) << endl;
}

int main(){
	int casenum; cin >> casenum;
	rep(casenow, casenum){
		printf("Case #%d: ", casenow+1);
		main2();
	}
	return 0;
}

