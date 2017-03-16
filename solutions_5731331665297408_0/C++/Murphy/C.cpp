#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;

int N, M;
int g[16][16];
string best = ""; string ss;
string zip[16];
int Z[16];
map<LL, string> st;

void gao(int s, int v, int stack, int out) {
	if (stack == 0)
		return;
	if (!(v & (1 << s))) {
		ss = ss  + zip[s];
	}
	//int v2 = v;
	v |= 1<<s;
	LL status = v << 8;
	status |= out; status <<= 8;
	status = status * 10 + s;
	status = status * 100000000 + stack;
	//cout<<s<<' '<<v<<' '<<stack<<' '<<out<<' '<<status<<endl;
	if (st.find(status) != st.end() && st[status] < ss) return;
	st[status] = ss;
	if (v == (1<<N) - 1) {
		if (best == "" || ss < best) {
			//cout<<ss<<endl;
			//cout<<s<<' '<<v<<' '<<stack<<' '<<out<<endl;
			best = ss;
		}
		return;
	}
	REP(i, N) {
		if (i != s && g[i][s] ) {
			if (out & (1<<i)) {
				continue;
			}
			if (v & (1<<i)) {
				continue;
			}
			string s2 = ss;
			gao(i, v, stack * 10 + i + 1, out | (1<<i));
			ss = s2;
		}
	}
	int pre = (stack / 10)% 10 - 1;
			string s2 = ss;
	gao(pre, v, stack / 10, out);
			ss = s2;
}


int main(){
	int T;
	cin>>T;
	for (int cases = 0; cases < T; cases++) {
		cin>>N>>M;best="";
		string small = "99999"; int c = 0;st.clear();
		REP(i, N) {
			cin>>zip[i];
			if (zip[i] < small) { small = zip[i]; c = i;
			}
		}
		memset(g, 0, sizeof g);
		REP(i, M) {
			int u, v;
			cin>>u>>v;
			u--;v--;
			g[u][v] = g[v][u] = 1;
		}
		ss = "";
		st.clear();
		gao(c, 0, c + 1, 0);
		printf("Case #%d: %s\n", cases + 1, best.c_str());
		
	}
	return 0;
}
