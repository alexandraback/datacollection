#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <map>
#include <set> 
#include <sstream>
#include <fstream>
#include <utility>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define REP(i,a) for(int i=0;i<a;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define SIZE(c) (int)c.size()
#define ALL(c) (c).begin(),(c).end() 
typedef pair<int, int> PII;
const int INF = 1000000000;
const int MAXN = 1000000;
const double EPS = 1e-06;
int T;
double C, F, X;
double dp[MAXN];
bool vis[MAXN];
double go(int n) {
	if (n == 1) {
		return dp[n] = C / 2.0;
	}
	if (vis[n]) return dp[n];
	vis[n] = true;
	return dp[n] = go(n - 1) + C / (2 + (n - 1) * F);
}
double solve() {
	double ret = X / 2.0;
	for (int i = 1; i < MAXN; i ++) {
		double secs = go(i);
		double tot = 2 + i * F;
		double next = secs + (X / tot); 
		if (ret - next > EPS) {
			ret = next;
		} else {
			continue;
		}
	}
	return ret;
}
int main() {
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
	cin>>T;
	REP(t, T){
		memset(vis, false, sizeof vis);
		cin>>C>>F>>X;
		cout<<"Case #"<<(t+1)<<": "<<fixed<<setprecision(7)<<solve()<<endl;
	}
	return 0;
}
