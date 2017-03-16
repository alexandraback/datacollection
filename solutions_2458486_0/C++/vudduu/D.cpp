/**
 * Large Input ?
 * Ain nobody got time foo that
 */

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

int K, N;
vector<int> type;

int createType(int x) {
	type.PB(x);
	return type.S-1;
}

class Keys {
public:
	// vector<LL> v;
	LL v;
	Keys(){
		reset();	
	}
	void reset() {
		// v = vector<LL> (8, 0);
		v = 0LL;
	}
	void add(LL x) {
		// v[i] |= x;
		v |= x;
	}
	void add(int it) {
		// add(it/50, 1LL<<(it%50));
		add(1LL<<it);
	}
	void add(Keys x) {
		// F(i, 8) v[i] |= x.v[i];
		v |= x.v;
	}

	void remove(LL x){
		// v[i] ^= x;
		if(v & x) v ^= x;
	}
	void remove(int it) {
		// LL aux = 1LL<<(it%50);
		// if( v[it/50] & aux )
		// 	v[it/50] ^= aux;
		remove(1LL<<it);
	}
	
	void remove(Keys x) {
		// F(i, 8) v[i] ^= x.v[i];
		v ^= x.v;
	}

	LL getValidKey(Keys b) {
		// F(i, 8) {
		// 	LL x = v[i] & b.v[i];
		// 	if(x) return MP( i, ((x-1)|x)^(x-1) );
		// }
		// return MP(-1, -1);
		LL x = v & b.v;
		if(x) return ((x-1)|x)^(x-1);
		return -1LL;
	}

	static Keys createFromVector(vector<int> a) {
		Keys ret;
		F(i, a.S) ret.add( createType(a[i]) );
		return ret;
	}
};
Keys keys;

vector<Keys> kindKeys;
void initKindKeys() {
	kindKeys = vector<Keys>(202);
	F(i, type.S) {
		kindKeys[ type[i] ].add( i );
	}
}
// END KEYS

vector<pair<int, Keys> > nodes;
bool vis[21], flag, memo[1<<21];
vector<int> sol;

void dfs(int cont, vector<int> rec, int mask) {
	if(flag || memo[mask]) return;
	if(cont == 0) {
		sol = rec;
		flag = true;
		return;
	}
	memo[mask] = true;
	rec.PB(0);
	F(i, N) {
		if(vis[i]) continue;
		LL x = keys.getValidKey(kindKeys[ nodes[i].first ]);
		if(x == -1LL) continue;
		keys.remove(x);
		vis[i] = true;
		keys.add(nodes[i].second);

		rec[rec.S-1] = i;
		dfs( cont-1, rec, mask|(1<<i) );

		keys.add(x);
		vis[i] = false;
		keys.remove(nodes[i].second);
	}
}

void solveIni(int caso) {
	int n, x;
	scanf("%d %d", &K, &N);

	type.clear();
	nodes = vector<pair<int, Keys> > (N);
	keys.reset();

	F(i, K) {
		scanf("%d", &x);
		keys.add( createType(x) );
	}

	F(i, N) {
		scanf("%d %d", &x, &n);
		vector<int> aux(n);
		F(j, n) scanf("%d", &aux[j]);
		nodes[i].first = x;
		nodes[i].second = Keys::createFromVector(aux);
	}
	initKindKeys();

	sol.clear();
	flag = false;
	memset(vis, 0, sizeof(vis));
	memset(memo, 0, sizeof(memo));
	dfs(N, sol, 0);

	if(sol.S) {
		printf("Case #%d:", caso);
		F(i, sol.S) {
			printf(" %d", sol[i]+1);
		}
		printf("\n");
	}
	else {
		cout<<"Case #"<<caso<<": IMPOSSIBLE"<< endl;
	}
}

int main(){
	// freopen("a.in.txt", "r", stdin);
	freopen("D-small-attempt1.in", "r", stdin);
	freopen("a.out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	F(i, T){ solveIni(i+1); }
}
