#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <algorithm>

#define sz(a) int((a).size())
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define all(c) (c).begin(),(c).end()
#define INF 2000000000
#define EPS 1e-5
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define X first
#define Y second
#define DEBUG(x) printf("debugging.. %d\n", x);
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

int T, A, B;
double p[100005];

double bs[100005], dp[100005], ans;

double op1() {
	return 	bs[A]*(1.0 + B - A) + 
			(1.0 - bs[A])*(1.0 + (B - A) + B + 1.0);
}

double op2() {
	double res = 1e14, val;
	for(int i = 1; i <= A; ++i) {
		// backspace i times
		val = 	dp[A-i+1]*bs[A-i]*(1.0 + 2*i + (B - A)) + 
				dp[A-i+1]*(1.0 - bs[A-i])*(1.0 + 2*i + (B - A) + B + 1.0);
				
		res = min(res, val);
	}
	
	return res;
}

double op3() { 
	return (2.0 + B);
}

int main() {
	scanf("%d", &T);
	
	for(int tc = 0; tc < T; ++tc) {
		printf("Case #%d: ", tc + 1);
		
		scanf("%d%d", &A, &B);
		
		for(int i = 1; i <= A; ++i)
			scanf("%lf", &p[i]);
			
		bs[0] = 1;
		
		for(int i = 1; i <= A; ++i)
			bs[i] = p[i]*bs[i-1];
			
		dp[A+1] = 1.0;
		for(int i = A; i >= 1; --i) 
			dp[i] = p[i]*dp[i+1] + (1.0 - p[i])*dp[i+1];
		
		ans = min(op1(), min(op2(), op3()));
		printf("%.6lf\n", ans);
	}
	
	return 0;
}
