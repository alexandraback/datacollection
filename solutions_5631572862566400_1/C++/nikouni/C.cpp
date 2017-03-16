#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef set<int> se;
typedef pair<int,int> pii;
typedef long long int tint;

#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define rall(c) (c).rbegin(), (c).rend()
#define all(c) (c).begin(), (c).end()
#define D(a) << #a << "=" << a << " "


#define si(a) int((a).size())
#define pb push_back
#define mp make_pair

vector<vector<bool>> M;
vvi adj;
vector<pii> super;
int N;
int SUM;
vi color;
int max_cicle;

void calculate_super_bff() {
	forn(i,N) forn(j,i) 
			if (M[i][j] && M[j][i]) {
				super.pb(pii(i,j));
			}
	
	//forn(i,si(super)) cout << super[i].first << " " << super[i].second << endl;
}

int value(int u, int bff) {
	color[u] = 2;
	int res = 0;
	forn(i,si(adj[u])) {
		int v = adj[u][i];
		if (v == bff) continue;
		res = max(res,value(v,-1));
	}
	return res + 1;
}

void compute_over_super_bff() {
	forn(i,si(super)) {
		int a = super[i].first;
		int b = super[i].second;
		int valA = value(a,b);
		int valB = value(b,a);
		//cout << "a b valA valB " << a << " " << b << " " << valA << " " << valB << endl;
		SUM += valA + valB;
	}
}

void compute_cicle(int u, int L) {
	if (color[u] == 1) {
		//found cicle
		//cout << "found cicle in L= " << u << " " << L << endl;
		max_cicle = max(max_cicle,L);
		return;
	}
	
	color[u] = 1;
	forn(i,si(adj[u])) {
		int v = adj[u][i];
		//if (done[v]) continue; // es necesario esto?
		compute_cicle(v,L+1);
	}
	color[u] = 2;
}

void init() {
	M = vector<vector<bool>>(1010,vector<bool>(1010,false));	
	adj = vvi(N,vi());
	super.clear();
	SUM = 0;
	color = vi(N,0);
	max_cicle = 0;	
}

int main () {
	freopen("C-large.in","r",stdin);
	freopen("out.txt","w",stdout);
    
	ios_base::sync_with_stdio(false);
	
	int T; 
	
	cin >> T;
	
	forsn(cas,1,T+1) {
		cin >> N;
		
		init();
		
		
		
		forn(i,N) {
			int fi; cin >> fi;
			fi--;
			adj[fi].pb(i);
			M[fi][i] = true;
		}
		/*
		forn(i,N) {
			cout << i << ": ";
			forn(j,si(adj[i])) cout << adj[i][j] << " "; 
			cout << endl;
		}*/
		
		calculate_super_bff();
		
		compute_over_super_bff();
		
		forn(i,N)
			if (color[i] == 0) {
				compute_cicle(i,0);
			}
		
		//cout << "SUM " << SUM << endl;
		
		int res = max(max_cicle,SUM);
		
			
		cout << "Case #" << cas << ": " << res << endl;
	}
	

  return 0;

}


