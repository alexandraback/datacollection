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
#define itm1 fst.fst
#define itm2 fst.snd
#define itm3 snd
#define mt(a,b,c) mp(mp(a,b),c)
#define sz(v) ((int)v.size())
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ii, int> tri;
typedef unsigned int ui;

int nc;
ll k, c, s;

ll pw[110][110];

int main(){
	fast_io();
	cin >> nc;
	for(ll i = 0; i < 110; i++){
		pw[i][0] = 1;
		REP(j,1,110) pw[i][j] = i * pw[i][j-1];
	}
	REP(tc,1,nc+1){
		cout << "Case #" << tc << ":";
		cin >> k >> c >> s;
		if (s*c < k) {
			cout << " IMPOSSIBLE" << endl;
			continue;
		}
		ll curr = 0;
		while(curr < k){
			ll num = 0;
			REP(j,0,c) {
				num += curr * pw[k][j];
				curr++;
				if (curr == k) break;
			}
			cout << " " << num + 1;
		}
		cout << endl;
	}

	return 0;
}

