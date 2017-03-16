// Enjoy your stay.

#include <bits/stdc++.h>

#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(auto it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define mt make_tuple
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)(x).size())

using namespace std;

typedef istringstream iss;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef stringstream sst;
typedef vector<ll> vi;

int A,B,C;
ll dp[33][2][2][2];

ll f(int cur,int fA,int fB,int fC){
	if(cur == -1){
		return fA && fB && fC;
	}
	ll& res = dp[cur][fA][fB][fC];
	if(res != -1)return res;
	res = 0;

	// 0,0
	{
		int nA = fA || (A>>cur&1);
		int nB = fB || (B>>cur&1);
		int nC = fC || (C>>cur&1);
		res += f(cur-1,nA,nB,nC);
	}
	// 0,1
	if(fB || (B>>cur&1)){
		int nA = fA || (A>>cur&1);
		int nB = fB;
		int nC = fC || (C>>cur&1);
		res += f(cur-1,nA,nB,nC);
	}
	// 1,0
	if(fA || (A>>cur&1)){
		int nA = fA;
		int nB = fB || (B>>cur&1);
		int nC = fC || (C>>cur&1);
		res += f(cur-1,nA,nB,nC);
	}
	// 1,1
	if((fA || (A>>cur&1)) && (fB || (B>>cur&1)) && (fC || (C>>cur&1))) {
		int nA = fA;
		int nB = fB;
		int nC = fC;
		res += f(cur-1,nA,nB,nC);
	}
	return res;
}

void main2(){
	cin>>A>>B>>C;
	memset(dp,-1,sizeof(dp));
	cout<<f(29,0,0,0)<<endl;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	
	
	int T;
	cin>>T;
	time_t start=clock(),pre=start;
	rep(tc,T){
		cout<<"Case #"<<tc+1<<": ";
		main2();
		time_t now=clock();
		cerr<<tc+1<<"/"<<T<<": "<<(double)(now-pre)/CLOCKS_PER_SEC<<endl;
		if(tc==T-1){
			cerr<<"Total: "<<(double)(now-start)/CLOCKS_PER_SEC<<endl;
			cerr<<"  Ave: "<<(double)(now-start)/CLOCKS_PER_SEC/T<<endl;
		}
		pre=now;
	}
}
