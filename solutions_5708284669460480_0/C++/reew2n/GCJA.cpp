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
int K,L,S;
string key,tar;
void searching(int now,string s){
	if(now==S){
		double ans=0;
		REP(i,S+1-tar.size())
			REP(j,tar.size())
				if(tar[j]==s[i+j] && j==tar.size()-1) ans++;
				else if(tar[j]!=s[i+j]) break;
		maxim=max(maxim,ans);
		nums+=ans;
		return;
	}
	else{
		REP(i,K)
			searching(now+1,s+key[i]);
	}
}
double solve(){
	cin >> K >> L >> S;
	cin >> key >> tar;
	searching(0,"");
	return maxim-(nums/(double)(pow(K,S)));
}
int main(){
	int T;
	cin >> T;
	FOR(i,1,T+1){
		printf("Case #%d: %lf\n",i,solve());
		maxim=0;
		nums=0;
	}

	return 0;
}