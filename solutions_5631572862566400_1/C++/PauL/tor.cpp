#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define EPS 1e-9
#define REP(i,x,y) for(int (i) = (x) ; (i) < (y) ; ++(i))
#define REPIT(it,A) for(typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
#define ones(x) __builtin_popcount(x)
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x) cout << #x << ": " << x << endl;
#define fst first
#define snd second
#define itm1 fst.fst
#define itm2 fst.snd
#define itm3 snd
#define mt(a,b,c) mp(mp(a,b),c)


typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll,ll> ill;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ii, int> tri;
typedef pair<int,bool> ib;
typedef unsigned int ui;


const double PI = acos(-1);
//const double E = 2.718281828459;
const int  INF = 2e9;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 2;
const int MN = 3002;

int dir[MN];
vector<ii> parejas;
vector<int> ad[MN];
int dp[MN];
bool visit[MN], used[MN];


void dfs(int u){
	bool ok = 0;
	used[u] = 1;
	REP(i,0,ad[u].size()){
		int v = ad[u][i];
		if(v != dir[u]){
			ok = 1;
			if(!used[v]) dfs(v);
			dp[u] = max(dp[u], dp[v] + 1);
			
		}
	}

	if(!ok) dp[u] = 0;
}

int main(){
	fast_io();
	int T; cin >> T;
	int x;
	int n;
	REP(tc,1,T+1){
		cin >> n;
//		cout << "--------------" << endl;
		REP(i,0,n) visit[i] = used[i] = 0;
		REP(i,0,n) ad[i].clear();
		REP(i,0,n) dp[i] = 0,dir[i] = -1;
		parejas.clear();
		REP(i,0,n){
			cin >> x;
//			cout << x - 1 << " ";
			--x;
			dir[i] = x;
			ad[x].pb(i);
//			cout << "dir[" << i << "]: " << dir[i] << endl;
		}
//		cout << endl;
		REP(i,0,n){
			if(!used[i]) dfs(i);	
		}
		REP(i,0,n){
			if(dir[dir[i]] == i){
				parejas.pb(mp(i,dir[i]));
//				cout << i << " " <<  dir[i] << endl;
			}
		}
		#ifdef DEBUG
		cout << "Adyacencia" << endl;
		REP(i,0,n){
			cout << "Vecinos de " << i << ": " ;
			REP(j,0,ad[i].size()){
				cout << ad[i][j] << " ";
			}	
			cout << endl;
		}
		#endif
		int ans = 0;
		#ifdef DEBUG
		cout << "DPS" << endl;
		REP(i,0,n)
		cout << "dp[" << i << "]: " << dp[i] << endl;
		#endif
//		debug(parejas.size());
		REP(i,0,parejas.size()){
			int uu = parejas[i].fst, vv = parejas[i].snd;	
//			ans = max(ans, dp[uu] + dp[vv] + 2);	
			ans += dp[uu] + dp[vv] + 2;
		}
		ans /= 2;
		int cycle = 0;
		int tmp = 1;
		int timer = 1;
		REP(i,0,n){
			REP(j,0,n) visit[j] = 0;
				int w = i;
				timer = 1;
//				cout << w << endl;
				while(!visit[w]){
//					if(i == 2) cout << dir[w] << endl;
					visit[w] = 1;
					if(i == dir[w]){
						cycle = max(cycle, timer);
//						cout << "detectado en " << i << " con timer:" << timer << endl;
					}
					else{
						w = dir[w]; ++timer;
					}
				}
		}
		
//		cout << "EL mayor ciclo es de long: " << cycle << endl;
//		cout << "La mayor componente mezclada es : " << ans << endl;
		ans = max(ans, cycle);
		cout << "Case #" << tc << ": " << ans << endl;

	}
	return 0;
}




















