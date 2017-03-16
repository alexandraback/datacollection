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
const int SIZE=61;
const LL INF=1LL<<60;
const LL p=7+1e+9;
void labeling(bool able[SIZE],int nums[SIZE],int D,int now){
	if(now==D){
		return;
	}
	else{
		REP(k,30){
			int i=30-k-1;
			able[i+nums[now]]|=able[i];
		}
		labeling(able,nums,D,now+1);
	}
}
int growzing(const bool able[SIZE],int now,int V){

	REP(i,V+1)
		if(able[i]&&i==V) return now;
		else if(!able[i]) break;
	bool newable[SIZE]{};
	int minium=5;
	if(now==4) return 5;
	FOR(j,1,29){
		REP(i,31){
			newable[i]=able[i];
			if(i>=j)
				newable[i]|=able[i-j];
		}
		minium=min(minium,growzing(newable,now+1,V));
	}
	return minium;
}
int solve(){
	int N,C,D,V,nums[SIZE]={};
	bool able[SIZE]{1,0};
	cin >> C >> D >> V;
	REP(i,D){
		cin >> nums[i];
	}
	labeling(able,nums,D,0);
	return min(5,growzing(able,0,V));
}
int main(){
	int T;
	cin >> T;
	FOR(i,1,T+1){
		cout <<"Case #"<<i<<": " << solve() << endl;
	}

	return 0;
}