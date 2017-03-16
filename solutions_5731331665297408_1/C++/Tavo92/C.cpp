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

string res;
int vist[64];
vector<int> camino;
int banca = -1;

int vl[64];
void dfsEsp(int nodo, int puedo) {
	vl[nodo] = 1;
	forn(i, ady[nodo].size()) {
		int nn = ady[nodo][i];
		if(vl[nn]) continue;
		if(vist[nn]) {
			bool especial = false;
			forn(j, puedo) if(camino[j] == nn)
				especial = true;

			if(!especial)
				continue;
		}
		dfsEsp(nn, puedo);
	}
}
bool llega(int nodo, int cc) {
	memset(vl,0,sizeof(vl));
	dfsEsp(nodo, cc);

	forn(i,n)
		if(!vist[i] && !vl[i])
			return false;

	return true;
}


void dfs(int nodo) {
	vist[nodo] = 1;
	camino.push_back(nodo);

	while(true) {
		int sig = -1;
		forn(i, ady[nodo].size()) {
			int nn = ady[nodo][i];
			if(vist[nn]) continue;
			if(sig == -1 || zip[nn] < zip[sig])
				sig = nn;
		}

		if(sig == -1) break;

		//siguiente del resto
		set<pair<string, int> > mem;

		forn(i, camino.size()-1) {
			forn(j, ady[camino[i]].size()) {
				int nn = ady[camino[i]][j];
				if(vist[nn]) continue;
				if(zip[nn] < zip[sig]){
					mem.insert(make_pair(zip[nn], i));
				}
			}
		}

		forall(it, mem) {
			if(llega(camino[it->second], it->second)) {
				camino.pop_back();
				banca = camino[it->second];
				return;
			}
		}
		res += zip[sig];
		dfs(sig);
		if(banca != -1){ 
			if(banca != nodo) 
				break;
			banca = -1;
		}
	}
	camino.pop_back();
}

int main(){
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);

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

		memset(vist,0,sizeof(vist));
		int empe = 0;
		forn(i,n) if(zip[i] < zip[empe])
			empe = i;
		//cout << endl;
		//cout << zip[empe] << endl;

		res = zip[empe];
		camino.clear();
		banca = -1;
		dfs(empe);
		cout << res << endl;
	}

	return 0;
}
