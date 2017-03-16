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
const int MN = 1e6 + 5;

int color[3000];

int main(){
	fast_io();
	int T;
	cin >> T;
	int x;
	vector<int> ans;
	REP(tc,1,T + 1){
		int n; cin >> n;
		ans.clear();
		REP(i,0,3000) color[i] = 0;
		REP(i,0,2*n - 1)
		REP(j,0,n){
			cin >> x;
			color[x]++;			
		}
		cout << "Case #" << tc << ":";
		REP(i,0,3000){
			if(color[i] & 1)
			cout << " " << i;
		}
		cout << endl;
	}

	return 0;


}












