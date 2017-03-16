// Visual C++ 2008 Express
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define REP(i,n) FOR(i,0,n)
#define FOR(i,s,n) for(int i=(s); i<(n); ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())

bool can(int A, vector<int> a, int add, int rem) {
	sort(all(a));
	REP(i, sz(a) - rem) {
		while(a[i] >= A && add > 0) {
			--add;
			A += (A - 1);
		}
		if(a[i] < A) {
			A += a[i];
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T;
	cin >> T;
	for(int tc = 1; tc <= T; ++tc) {
		int A, N;
		cin >> A >> N;
		vector<int> a(N);
		REP(i, N) cin >> a[i];
		int ans = 1000;
		REP(add, N+1) {
			REP(rem, N+1) {				
				if(can(A, a, add, rem)) {
					ans = min(ans, add+rem);
				}
			}
		}
		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}