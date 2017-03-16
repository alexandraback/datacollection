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

int able[16], nable[16];

int main(){
	fast_io();
	int T, n , J;
	cin >> T;
	cin >> n >> J;
	int cnt = 0;
	cout << "Case #1:" << endl;
//	int ans = 0;
	REP(i,0,50){
//		ans = 0;
		REP(j,0,16) able[j] = nable[j] = 0;
		able[0] = able[14] = 1;
		nable[0] = nable[14] = 1;
		REP(j,0,6){
			if(i & (1 << j)){
				able[2 * j + 2] = 1;
			}		
		}
		REP(j,0,15){
			if(able[j]) {
			nable[j + 1] = 1;
			nable[j] = 1;
			}
		}
		for(int j = 15 ; j >= 0 ; --j){
			if(nable[j]) {
			cout << 1;
//			ans |= (1 << j);
			}
			else cout << 0;
		}
//		cout << " : " ;
//		cout << ans << " divisores:" ;
		REP(j,3,12) cout << " " << j;
		cout << endl;
	}
	
	return 0;

}






























