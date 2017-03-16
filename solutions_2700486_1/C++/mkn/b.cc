#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<cstdlib>
#include<cassert>

using namespace std;

typedef long long ll;
typedef pair<int,int> pint;

#define mp make_pair
#define pb push_back

#define repp(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define rep(i,n) repp(i,0,(n)-1)

int n, x, y;

void output(int cas, char *s){
	printf("Case #%d: %s\n", cas+1, s);
}

double solve(){
	x = abs(x);
	int kido = (x + y) / 2;
	if((kido+1)*(2*kido+1) <= n) return 1.0;
	if((kido)*(2*kido-1) >= n) return 0.0;
	
	int t = n - kido*(2*kido-1);
	
	if(t >= 2*kido + y + 1) return 1.0;
	if(x == 0) return 0.0; 
/*
cout << "k: " << kido << endl;
cout << "t: " << t << endl;
cout << "y: " << y << endl;
*/

	vector<double> dp(4*kido, 0.0);
	dp[0] = 1.0;
	repp(i,1,t){
		vector<double> dp2 = dp;
		repp(i, 1, dp.size()-1) dp[i] = (dp2[i] + dp2[i-1]) / 2;
	}
	return dp[y+1];
}

int main(){
	int casenum; cin >> casenum;
	rep(cas, casenum){
		cin >> n >> x >> y;
		printf("Case #%d: %.7f\n", cas+1, solve());
	}
	return 0;
}

