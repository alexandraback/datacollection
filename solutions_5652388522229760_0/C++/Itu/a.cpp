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
ll x;
ll y;

set<int> vis;

void cnt(ll u){
	while (u){
		vis.erase(u%10);
		u /= 10;
	}
}

int main(){
	fast_io();
	cin >> nc;
	REP(tc,0,nc){
		cout << "Case #" << tc+1 << ": ";
		cin >> x;
		if (x == 0) {
			cout << "INSOMNIA" << endl;
			continue;
		}
		else{
			vis.clear();
			REP(i,0,10) vis.insert(i);
			y = x;
			cnt(y);
			while(!vis.empty()){
				y += x;
				cnt(y);
			}
			cout << y << endl;
		}
	}
	return 0;
}

