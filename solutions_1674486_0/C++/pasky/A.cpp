#define _HAS_CPP0X 0
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")
#include <queue>
#include <cassert>
#include <sstream>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
template<class T> T Abs(T x) { return x < 0 ? -x : x; }
#define FOR(i, n) for(int i = 0; i < (int)(n); ++i)


struct Task{
	int n;
	vector<VI> G;
	VI was;
	bool dfs(int u){
		was[u]++;
		if (was[u] > 1)
			return true;
		FOR(i, G[u].size()){
			int v = G[u][i];
			if (dfs(v))
				return true;
		}
		return false;
	}
	void go(){
		cin >> n;
		G.resize(n);
		was.resize(n);
		FOR(i, n){
			int m;
			cin >> m;
			FOR(j, m){
				int v;
				cin >> v;
				v--;
				G[i].push_back(v);
			}
		}
		bool ok = 1;
		FOR(i, n){
			was.assign(n, 0);
			if (dfs(i)){
				ok = 0;
				break;
			}
		}
		cout << (ok ? "No" : "Yes");
	};
};

int main(){
	const string task = "A";
	const string folder = "gcj/2012/1c";
	const int attempt = 0;
	const bool dbg = false;


	if (dbg){
		freopen("inp.txt", "r", stdin);
	}
	else{
		stringstream ss;
		if (attempt < 0)
			ss << folder << '/' << task << "-large";
		else
			ss << folder << '/' << task << "-small-attempt" << attempt;
		freopen((ss.str() + ".in").c_str(), "r", stdin);
		freopen((ss.str() + ".out").c_str(), "w", stdout);
	}


	static char tt[128];
	gets(tt);
	int t;
	sscanf(tt, "%d", &t);
	FOR(i, t){
		printf("Case #%d: ", i + 1);
		Task t; t.go();
		printf("\n");
	}
	return 0;
}