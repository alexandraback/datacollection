#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef long long LL;

#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define ST first
#define ND second
int zip[100];
const int stala=10;
int pozycja=0;
template<class V, class E> struct Graph {
	struct Ed : E {
		int v; 
		Ed(E p, int w) : E(p), v(w) {}
	};
	struct Ve : V,vector<Ed> {};
	vector<Ve> g;
	Graph(int n=0) : g(n) {}
	void EdgeU(int b, int e, E d = E()) {
	    Ed eg(d,e); eg.rev=SIZE(g[e])+(b==e); g[b].PB(eg);
	    eg.rev=SIZE(g[eg.v=b])-1; g[e].PB(eg);
	}
	int t;
	void DfsV(int v){
		if(v==pozycja) g[v].s=0;
		//cout << "v: "<<v;
		if(!(g[v].d>=0))	g[v].d=++t;
		//cout << " "<<t<<endl;
		REP(nr_powtorzenia,stala){
			int wsp1;
			int min=1000000000;
		FOREACH(it,g[v]) if(g[it->v].s==-1){
			if(zip[it->v]<min) wsp1=it->v,min=zip[it->v];
		//	g[it->v].s=v;
		//	DfsV(it->v);
		}
			if(min!=1000000000){
				g[wsp1].s=v;
				//cout << "wchodze do: "<<wsp1<<" min: "<<min<<endl;
				DfsV(wsp1);
			}
			else break;
		}
		//g[v].f=++t;
	}
	void DfsR(int e=-1){
		
		t=-1;
		int b=0;
		e==-1?e=SIZE(g)-1:b=e;
		REP(x,SIZE(g))g[x].d=g[x].f=g[x].s=-1;
		//g[e].s=0;
		//DfsR(e);
		FOR(x,b,e) if(g[x].s==-1) DfsV(x);
	}
};
struct Ve {
	int rev;
};
struct Vs {
	int d, f, s;
};
int main() { 
	int t;
	if(!freopen("in4.txt", "r", stdin)) cout<<"Blad odczytu in.txt"<<endl;
	if(!freopen("out.txt", "w", stdout)) cout<<"Blad pliku wyjsciowego"<<endl;
	ios_base::sync_with_stdio(0);
	cin>>t;
	FOR(numer_testu,1,t){
	int n, m, s, b, e;
	cin >> n >> m;
		REP(x,n) cin>>zip[x];
		
	Graph<Vs, Ve> g(n);
	REP(x,m) {
		cin >> b >> e;
		g.EdgeU(--b, --e);
	}
		int min=1000000000;
		pozycja=0;
		REP(x,n) if(zip[x]<min) min=zip[x],pozycja=x;
		//cout << "pozycja "<<pozycja<<endl;
	g.DfsR(pozycja);
		VI odp(n);
		REP(x, SIZE(g.g)) {/*cout << "Wierzcholek " << x << ": czas wejscia = " <<
	g.g[x].d << ", czas wyjscia = " << g.g[x].f << 
			", ojciec w lesie DFS = " << g.g[x].s << endl;*/
			odp[g.g[x].d]=zip[x];
		}
		cout << "Case #"<<numer_testu<<": ";
		REP(x,n) cout<<odp[x];
		cout<<endl;
	}
	return 0;
}
