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
const int MAXN = 105;
int N, S, P, pt[MAXN], dp[MAXN][MAXN];
int go(int idx, int s){
	if(s < 0) return -INF;
	if(idx == N){
		return s == 0 ? 0 : -INF;
	}
	int &ret = dp[idx][s];
	if(ret != -1) return ret;
	ret = 0;
	for(int i = 0; i <= 30; i ++){
		for(int j = i; j <= i + 2; j ++){	
			for(int k = j; k <= i + 2; k ++){
				if(i + j + k != pt[idx]) continue;
				bool surp = false;
				if(k - i == 2) surp = true;
				ret = max(ret, (k >= P) + go(idx + 1, s - surp));
			} 
		}
	}
	return ret;
}
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("b-large.out", "w", stdout);
	int T;
	cin>>T;
	for(int t = 1; t <= T; t ++){
		cin>>N>>S>>P;
		REP(i, N) cin>>pt[i];
		memset(dp, -1, sizeof dp);
		cout<<"Case #"<<t<<": "<<go(0, S)<<endl;
	}
	return 0;
}
