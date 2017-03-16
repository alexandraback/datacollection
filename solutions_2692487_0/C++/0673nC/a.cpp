#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
//#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define REP(i,j,k) for(int i=j;i<(int)(k);++i)
#define foreach(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 99999999;
const double EPS = 1e-9;

int T,A,N,ans;
vi n;

int dfs(int s,int mote, int res){
	REP(i,s,N) {
		if(n[i]>=mote){
			int mote_ = mote;
			int res_ = res;
			while(mote_<=n[i]) { mote_+=mote_-1; res_++; }
			return min(res+N-i,dfs(i+1,mote_+n[i],res_));
		}
//min(dfs(i+1,mote,res+1),dfs(i,mote+mote-1,res+1));
		else mote+=n[i];
	}

	return res;
}
int main(){
	cin >> T;
	rep(t,T){
		cin >> A >> N;
		ans = 0;
		n.clear();
		n.resize(N);
		rep(i,N) cin >> n[i];
		sort(all(n));
		if(A==1){
			printf("Case #%d: %d\n",t+1,N);
			continue;
		}
		ans = dfs(0,A,0);
		printf("Case #%d: %d\n",t+1,ans);
	}
	return 0;
}
