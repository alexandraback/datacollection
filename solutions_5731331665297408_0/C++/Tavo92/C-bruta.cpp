#include <iostream>
#include <algorithm>
#include <list>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <climits>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

#define forn(a,n) for(int a = 0; a<(n); ++a)
#define forsn(a,s,n) for(int a = (s); a<(n); ++a)
#define forall(a,all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)

typedef long long tint;

int T, n, m;
string zip[64];
vector<int> ady[64];

vector<int> perm;
int dfs(int nodo, int ppos) {
	if(ppos == perm.size()) return ppos;

	forn(i, ady[nodo].size()) {
		int nn = ady[nodo][i];
		if(nn == perm[ppos]) {
			ppos = dfs(nn, ppos+1);
			return dfs(nodo, ppos);
		}
	}
	return ppos;
}

int main(){
	freopen("C-small.in", "r", stdin);
	freopen("C-small-bruta.out", "w", stdout);

	cin >> T;
	forn(t, T) {
		printf("Case #%i: ", t+1);
		cin >> n >> m;
		forn(i,n) cin >> zip[i];
		forn(i,n) ady[i].clear();
		forn(i,m) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			ady[a].push_back(b);
			ady[b].push_back(a);
		}

		perm.clear();
		forn(i,n) perm.push_back(i);
		string ret;
		forn(i,8*n) ret += '9';
		do {
			int pp = dfs(perm[0], 1);
			if(pp == perm.size()) {
				string r;
				forn(i, perm.size()) r += zip[perm[i]];
				ret = min(ret, r);
			}
		} while(next_permutation(perm.begin(), perm.end()));
		cout << ret << endl;
	}

	return 0;
}
