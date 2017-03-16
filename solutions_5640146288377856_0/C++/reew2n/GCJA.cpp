#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
#define F first
#define S second
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
const int SIZE=1+1e+5;
const LL INF=1LL<<60;
const LL p=7+1e+9;
int solve(){
	int R,C,W;
	cin >> R >> C >> W;
	return (C/W)*(R-1)+(C-1)/W+W;
}
int main(){
	int T;
	cin >> T;
	FOR(i,1,T+1){
		cout <<"Case #"<<i<<": " << solve() << endl;
	}

	return 0;
}