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
typedef long long int LL;
const long long INF = 10000000000000000LL;
const int MAXN = 105;
LL arr[MAXN], dp[MAXN][MAXN];
LL A, N;
LL get(LL a, int b){
	while(b > 0){
		a += a - 1;
		if(a > INF) return INF;
		b --;
	}
	return a;
}
LL go(int k, int p){
	if(p < 0) return -INF;
	if(k == -1) return A;
	LL &ret = dp[k][p];
	if(ret != -1) return ret;
	ret = go(k - 1, p - 1);
	for(int i = 0; i <= p; i ++){
		LL mxh = go(k - 1, p - i);
		if(mxh == -INF) continue;
		LL t = get(mxh, i);
		if(t > arr[k]) {
			t += arr[k];
			ret = max(ret, t);
		}
	}
	return ret;
}
int main() {
	//freopen("a.in", "r", stdin); 
	//freopen("A-small-attempt0.in", "r", stdin); freopen("A-small-attempt0.out", "w", stdout);
	//freopen("A-small-attempt1.in", "r", stdin); freopen("A-small-attempt1.out", "w", stdout);
	//freopen("A-small-attempt2.in", "r", stdin); freopen("A-small-attempt2.out", "w", stdout);
	//freopen("A-small-attempt3.in", "r", stdin); freopen("A-small-attempt3.out", "w", stdout);
	
	freopen("A-large.in", "r", stdin); freopen("A-large.out", "w", stdout);
	
	int nT;
	cin>>nT;
	for (int t=1; t<=nT; t++) {
		cin>>A>>N;
		REP(i, N){
			cin>>arr[i];
		}
		sort(arr, arr + N);
		memset(dp, -1, sizeof dp);
		LL ret = -1;
		for(int i = 0; i <= 100; i ++){
			if(go(N - 1, i) != -INF){
				ret = i;
				break;
			}
		}
		printf("Case #%d: %lld\n", t, ret);
	}
	return 0;
}
