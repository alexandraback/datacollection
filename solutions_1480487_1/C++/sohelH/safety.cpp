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

double find_res(vector<int> &v, int u, int sum) {
	double low = 0;
	double high = 1;
	int t = 100;

	while(t--) {
		double m = (low + high) / 2;
		double p = v[u] + m * sum;

		double ys = 0;
		int i;
		for(i=0; i<v.size();i++) {
			double k = (p - v[i]) / sum;
			if( k > 0 ) 
				ys += k;
		}
		if( ys < 1 ) low = m;
		else high = m;
	}
	return low * 100;
}

int main() {
	int test, cases = 1;
	cin >> test;
	for( cases=1; cases<=test; cases++ ) {
		int n, s;
		vector<int> v; v.clear();
		cin >> n;
		int i;
		int sum = 0;
		for(i=0; i<n; i++) {
			int a; cin >> a; v.pb(a);
			sum += a;
		}
		pf("Case #%d:", cases);
		for(i=0; i<n; i++) {
			double res = find_res(v, i, sum);
			pf(" %.6lf", res);
		}
		cout << endl;
	}
	return 0;
}

