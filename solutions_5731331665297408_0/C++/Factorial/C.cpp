#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
#include <utility>
#include <iterator>
#include <fstream>
#include <cstdio>
#include <functional>

using namespace std;

template<class T>
string tostring(T a){ stringstream ss; ss << a; return ss.str(); }

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> II;
#define SZ(a) int((a).size()) 
#define PB push_back 
#define ALL(c) (c).begin(),(c).end() 
#define FOR(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define LOOP(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define MP(a,b) make_pair((a),(b))
#define LAST(t) (t[SZ(t)-1])

const int inf = 1000000000;

vector<int> zips;
VVI g;
VI vis;
vector<string> allstr;
int n;
stack<int> stk;

void f(int u, string s, int numvis, bool uj){
	if(uj){
		s += tostring(zips[u]);
		numvis++;
		if(numvis == n){
			allstr.push_back(s);
			return;
		}
	}

	FOR(i, SZ(g[u])){
		int v = g[u][i];
		if(vis[v] == 0){
			vis[v] = 1;
			stk.push(u);
			f(v, s, numvis, true);
			stk.pop();
			vis[v] = 0;
		}
	}

	if(SZ(stk)){
		int v = stk.top();
		stk.pop();
		vis[u] = 2;
		f(v, s, numvis, false);
		vis[u] = 1;
		stk.push(v);
	}

	vis[u] = 2;
}

int main(){
	ifstream be("C-small-attempt0.in");
	ofstream ki("ki.txt");
	int T;
	be >> T;
	FOR(tt, T){
		cout << tt + 1 << endl;
		int m;  be >> n >> m;
		zips = VI(n);
		int mi = inf;
		int mh;
		FOR(i, n){
			be >> zips[i];
			if(zips[i] < mi){
				mi = zips[i];
				mh = i;
			}
		}
		g = VVI(n);
		vis = VI(n);
		FOR(i, m){
			int u, v;  be >> u >> v;  u--; v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		allstr = vector<string>();

		vis[mh] = 1;
		stk = stack<int>();
		f(mh, "", 0, true);

		string sol = *min_element(ALL(allstr));

		ki << "Case #" << tt + 1 << ": " << sol << endl;
	}


	ki.close();
	return 0;
}