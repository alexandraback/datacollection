#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;

#define pf printf
#define sf scanf
#define VI vector<int>
#define pb push_back
#define fo(a,b) for((a)=0;(a)<(b);a++)

#define debug 0
const int inf = 1000000000;

long long ncr[305][305] = {0}; void gen_ncr(int n) { int i, j; fo(i, n+1) ncr[i][0] = 1; for(i=1;i<=n;i++) for(j=1;j<=n;j++) ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];}
double dis(double x1, double y1, double x2, double y2) { return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); }

vector<int> v;
int n;
int sum;
int dp[2000100];

int main() {
	int test, cases = 1;
	cin >> test;
	for( cases=1; cases<=test; cases++ ) {
		v.clear();
		cin >> n;
		int i, j;
		sum = 0;
		for(i=0; i<n; i++) {
			int a; cin >> a;
			v.pb(a);
			sum += a;
		}
		for(i=0;i<=sum;i++) dp[i] = 0;
		dp[0] = 1;

		for(i=0; i<n; i++) {
			for(j=sum; j>=0; j--)
				if( dp[j] ) 
					dp[j + v[i]] += dp[j];
		}

		for(i=1; i <= sum; i++) {
			if( dp[i]>1 ) {
				break;
			}
		}
		pf("Case #%d:\n", cases);

		if( i > sum ) {
			pf("Impossible\n");
		}
		else {
			int one = i;
			for(i=0; i<(1<<n); i++) {
				int s = 0;
				for(j=0; j<n; j++) {
					if( i & (1<<j) ) 
						s += v[j];
				}
				if( s == one ) {
					for(j=0; j<n; j++) {
						if( i & (1<<j) ) {
							pf("%d ", v[j]);
							v[j] = -1;
						}
					}
					cout << endl;
					sort(v.begin(), v.end());
					for(j=0;j<v.size();j++)
						if( v[0] == -1) v.erase(v.begin());

					n = v.size();
					for(i=0; i<(1<<n); i++) {
						int s = 0;
						for(j=0;j<n;j++) {
							if( i & (1<<j) ) s += v[j];
						}
						if( s == one ) {
							for(j=0; j<n; j++) {
								if( i & (1<<j) ) {
									pf("%d ", v[j]);
								}
							}
							cout << endl;
							goto done;
						}
					}
				}
			}
done:;
		}
	}
	return 0;
}

