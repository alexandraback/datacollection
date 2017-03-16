#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n, j;

int seen[2001];

vector<int> adj[2001];
int match[2001];
char w1[100], w2[100];

map<string, int> le;
map<string, int> ri;

bool bpm(int v) {
	if (seen[v]) return false;
	seen[v] = 1;

	for (int x : adj[v]) {
		if (match[x]==-1 || bpm(match[x])) {
			match[x]=v;
			return true;
		} 
	}
	return false;
}

int get_idx(char* s, map<string, int> &ma) {
	if (ma.find(s) != ma.end()) return ma[s];
	return ma[s] = ma.size()-1;
}

void read() {
	scanf("%d", &n);
	REP(i,n) adj[i].clear();
	
	le.clear();
	ri.clear();

	REP(i,n) {
		scanf("%s %s", w1, w2);
		int i1 = get_idx(w1,le);
		int i2 = get_idx(w2,ri);
		adj[i1].push_back(i2);
	}
}

void solve() {
	int tot = le.size() + ri.size();

	REP(i, ri.size()) match[i] = -1;
	int bb = 0;
	REP(i, le.size()) {
		memset(seen,0,sizeof(seen));
		bb += bpm(i);
	}

	//printf("bb=%d tot = %d n = %d\n", bb,tot,n);
	int need = bb + (tot - bb*2); 
	printf("%d\n", n - need);
}


























int myMod = 0;
int howMany = 1;

int main(int argc, char** argv) {
	if (argc > 1) {
		stringstream ss; ss << argv[1]; ss >> myMod;
		ss.str(""); ss.clear();
		ss << argv[2]; ss >> howMany;
	}

	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		read();
		if (i % howMany == myMod) {
			printf("Case #%d: ", i+1);
			solve();
		}
	}
}