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



int main(){
	int T; cin >> T;
	string s;
	string t = "", u = "";
	string cur = "";
	REP(tc,1,T+1){
		cin >> s;
//		t = ""; u = "";
		cur = "";
		int len = int(s.size());
		REP(i,0,len){
			t = "", u = "";
			t = cur;
			t += s[i];
			u += s[i];
//			debug(u);
			u += cur;
//			debug(t); debug(u);
//			debug(cur);
			cur = max(u,t);
		}
		cout << "Case #" << tc << ": " << cur <<endl;
	}


 	return 0;


}













