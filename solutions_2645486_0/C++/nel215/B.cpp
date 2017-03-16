#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

LL small(){
	LL E,R;
	int N;
	cin >> E >> R >> N;
	vector<LL> value(N);
	REP(i,N)cin >> value[i];
	vector<vector<LL> > dp(N+1,vector<LL>(E+1,-1000000000));
	dp[0][E] = 0;
	REP(i,N){
		REP(ne,E+1){
			for(LL use=0 ; use<=ne ; use++){
				int next = min(E,R+ne-use);
				int gain = value[i]*use;
				dp[i+1][next] = max(dp[i+1][next],dp[i][ne]+gain);
			}
		}
	}
	LL res = 0;
	REP(ne,E+1)res = max(res,dp[N][ne]);
	return res;
}

int main(){
	int T;
	cin >> T;
	REP(tc,T){
		LL res = small();
		cout << "Case #" << tc+1 << ": " << res << endl;

	}
	return 0;
}
