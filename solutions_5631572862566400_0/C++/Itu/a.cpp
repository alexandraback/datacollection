#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back(x)
#define REP(i,x,y) for(int (i)=(x);(i)<(y);(i)++)
#define REPIT(it,A) for(typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0); 
//#define NDEBUG 1
#define fst first
#define snd second
#define sz(v) ((int)v.size())
typedef vector<int> vi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int tc;

int n;
vi adj[1100];

int gid;				    // Current highest global id
int id[1100000];            // Id of visited nodes, 0 for unseen
int lo[1100000];	        // Lowest vertex id reachable from node u
stack<int> s;				// Stack for tarjan's SCC
int onStack[1100000];
int nsc;				    // Number of SCC
vector<int> sc[1100000];	// Vector representation of each SCC
int scOf[1100000];			// SCC of node u

int mk[1100];

vi radj[1100];
int ans;


int dfs(int u){
	id[u] = lo[u] = gid++;
	s.push(u);
	onStack[u] = 1;

	int v;
	REP(i,0,adj[u].size()){
		v = adj[u][i];
		if (!id[v]) {
			dfs(v);
			lo[u] = min(lo[u], lo[v]);
		}
		else if (onStack[v]){
			lo[u] = min(lo[u], id[v]);
		}
	}

	if (lo[u] == id[u]){
		sc[nsc].clear();
		do{
			v = s.top(); 
			s.pop();
			onStack[v] = 0;
			sc[nsc].pb(v);
			scOf[v] = nsc;
		} while (v != u);
		nsc++;
	}
}

int go(int u, int p){
//	cerr << "Visiting (" << u << "," << p << ")" << endl;
	int hi = 1;
	REP(i,0,sz(radj[u])){
		int v = radj[u][i];
		if (v == p) continue;
		hi = max(hi, 1 + go(v,u));
	}
	return hi;
}

int main(){
	fast_io();
	cin >> tc;
	REP(q,1,tc+1){
		cin >> n;
		REP(i,0,n) {
			adj[i].clear();
			radj[i].clear();
			id[i] = 0;
			lo[i] = 0;
			mk[i] = 0;
			scOf[i] = 0;
			onStack[i] = 0;
			while (!s.empty()) s.pop();
		}
		nsc = 0;
		gid = 1;
		REP(i,0,n){
			int x;
			cin >> x;
			adj[i].pb(x-1);
			radj[x-1].pb(i);
		}	
		REP(i,0,n) if (!id[i]) dfs(i);
		int best = 0;
		REP(i,0,nsc) best = max(best, sz(sc[i]));

		ans = 0;
		REP(i,0,n) {
			if (!mk[i] && sz(sc[scOf[i]]) == 2) {
//				cerr << "Working with i:" << i << endl;
//				cerr << "scid: " << scOf[i] << " out of " << nsc << endl;
				int z = scOf[i];
				int u = sc[z][0];
				int v = sc[z][1];
//				cerr << "Marking (" << u << "," << v << ")" << endl;
				ans += go(u, v);
//				cerr << "Ans semi: " << ans << endl;
				ans += go(v, u);
//				cerr << "Ans is now: " << ans << endl;
				mk[u] = 1;
				mk[v] = 1;
			}
		}
		best = max(best, ans);

		cout << "Case #" << q << ": " << best << endl;
//		cerr << "Case #" << q << ": " << endl;
	}
	return 0;
}

