#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
#define PB push_back 
#define BE(c) c.begin(),c.end()
using namespace std;
typedef long long LL;
typedef complex<int> cld;
typedef LL ut;
typedef vector<ut> VI;
typedef pair<ut,ut> pr;
typedef vector<pr> Vpr;
typedef pair<ut,pr> ppr;
typedef vector<ppr> Vppr;
typedef pair<pr,pr> ppppr;
typedef pair<ut,ppppr> pppppr;
typedef priority_queue<ppr,Vppr> PQ;
typedef vector<ppr> Vppr;
const int SIZE=61;
const LL INF=1LL<<60;
const LL p=7+1e+9;
double maxim=0;
double nums=0;
VI v;
LL x;
int solve(){
	LL C,D,V;
	cin >> C >> D >> V;
	REP(i,D){
		cin >> x;
		v.PB(x);
	}
	sort(BE(v),greater<LL>());
	REP(i,D){
		V=max(v[i]-1,V-(v[i]*C));
	}
	int ans=log2(V+1);
	return ans;
}
int main(){
	int T;
	cin >> T;
	FOR(i,1,T+1){
		printf("Case #%d: %d\n",i,solve());

	}

	return 0;
}