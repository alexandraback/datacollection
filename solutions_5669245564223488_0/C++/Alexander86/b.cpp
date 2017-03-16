
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <cassert>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const ll MOD = 1000000007;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)


ll fac(int n){
	if(n == 0)return 1;
	return (n * fac(n-1)) % MOD;
}

ll calc(vs in){
	ll res = 1;
	string start = "";
	FOR(i,0,sz(in)){
		if(sz(in[i]) > 1){
			start = in[i];
			in[i] = "";
			break;
		}
	}
	if(start == "")return fac(sz(in));
	while(true){
		bool fin = true;
		FOR(i,0,sz(in))if(in[i] != "") fin = false;
		if(fin)break;
		vi n2,n1,p2,p1;
		FOR(i,0,sz(in)){
			if(sz(in[i]) == 2){
				if(in[i][1] == start[1])return 0;
				if(in[i][0] == start[0])return 0;
				if(in[i][0] == start[1])n2.pb(i);
				if(in[i][1] == start[0])p2.pb(i);
			} else if(sz(in[i]) == 1){
				if(in[i][0] == start[0])p1.pb(i);
				if(in[i][0] == start[1])n1.pb(i);
			}
		}
		res = (res * fac(sz(n1))) % MOD;
		res = (res * fac(sz(p1))) % MOD;
		FOR(i,0,sz(n1))in[n1[i]] = "";
		FOR(i,0,sz(p1))in[p1[i]] = "";
		if(sz(n2) > 0){
			if(sz(n2) > 1)return 0;
			start[1] = in[n2[0]][1];
			if(start[0] == start[1])return 0;
			in[n2[0]] = "";
		} else if(sz(p2) > 0){
			if(sz(p2) > 1)return 0;
			start[0] = in[p2[0]][0];
			if(start[0] == start[1])return 0;
			in[p2[0]] = "";
		}
	}

	return res;
}

vi adj[128];
bool vis[128];
void calc(){
	int N;
	vs inp;
	cin >> N;
	FOR(i,0,N){
		string tmp;
		cin >> tmp;
		FOR(i,1,sz(tmp))if(tmp[i] == tmp[i-1]){
			tmp = tmp.substr(0,i) + tmp.substr(i+1);
			--i;
		}
		inp.pb(tmp);
	}
	ll res = 1;
	FOR(i,0,N)adj[i].clear();
	FOR(i,0,N)FOR(j,0,N)if(i!=j){
		FOR(i2,0,sz(inp[i])){
			FOR(j2,1,sz(inp[j])-1){
				if(inp[i][i2] == inp[j][j2]){
					cout << 0 << endl;
					return;
				}
			}
		}
	}
	FOR(i,0,N)FOR(j,0,sz(inp[i]))FOR(k,0,j)if(inp[i][j] == inp[i][k]){
		cout << 0 << endl;
		return;
	}
	FOR(i,0,N){
		if(sz(inp[i]) > 1){
			inp[i] = inp[i].substr(0,1) + inp[i].substr(sz(inp[i]) - 1);
		}
	}
	FOR(i,0,N)FOR(j,0,N)if(i!=j){
		bool con = false;
		FOR(i2,0,sz(inp[i])){
			FOR(j2,0,sz(inp[j])){
				if(inp[i][i2] == inp[j][j2]){
					con = true;
				}
			}
		}
		if(con)adj[i].pb(j);
	}
	FOR(i,0,N)vis[i] = false;
	int parts = 0;
	FOR(i,0,N)if(!vis[i]){
		++parts;
		vi cur;
		cur.pb(i);
		vis[i] = true;
		int j = 0;
		while(j < sz(cur)){
			int n = cur[j++];
			FOR(k,0,sz(adj[n])){
				int to = adj[n][k];
				if(vis[to])continue;
				vis[to] = true;
				cur.pb(to);
			}
		}
		vs next;
		FOR(k,0,sz(cur))next.pb(inp[cur[k]]);
		res = (res * calc(next)) % MOD;
	}
	res = (res * fac(parts)) % MOD;
	cout << res << endl;
}

int main() {
	int TC;
	cin >> TC;
	FOR(T,1,TC+1){
		cout << "Case #" << T << ": ";
		calc();
	}
	return 0;
}
