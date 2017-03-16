#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional> 
#include <numeric>
using namespace std;
#define foreach(i,v) for(__typeof((v).end()) i=(v).begin();i!=(v).end();++i)
#define rforeach(i,v) for(__typeof((v).rend()) i=(v).rbegin();i!=(v).rend();++i)
#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORE(i,b,e) for(int i=(b);i<=(e);++i)
#define debug(x) cerr << #x << " = " << (x) << "\n"
typedef long long LL;

int main(){
	int t;
	cin >> t;
	FORE(z,1,t){
		int n, s, p;
		cin >> n >> s >> p;
		int a[n];
		FOR(i,0,n)
			cin >> a[i];
		bool normal[n], surprise[n], sp[n];
		fill(normal,normal+n,false);
		fill(surprise,surprise+n,false);
		fill(sp,sp+n,false);
		FOR(i,0,n){
			FORE(b,0,10)
			FORE(c,b,10)
			FORE(d,c,10){
				if (d-b>2) continue;
				if (b+c+d!=a[i]) continue;
				if (d-b==2) sp[i] = true;
				if (d<p) continue;
				if (d-b==2) surprise[i] = true;
					else normal[i] = true;
			}
		}
		int dp[s+1];
		fill(dp,dp+s+1,-2147483647);
		dp[0] = 0;
		FOR(i,0,n)
			for (int r=s;r>=0;--r){
				if (normal[i]) dp[r]++;
				if (surprise[i] && r>0) dp[r]=max(dp[r],dp[r-1]+1);
				if (sp[i] && r>0) dp[r]=max(dp[r],dp[r-1]);
			}
		printf("Case #%d: %d\n",z,dp[s]);
	}
	return 0;
}
