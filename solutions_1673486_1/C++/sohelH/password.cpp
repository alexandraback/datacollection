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

int a, b;
vector<double> vd;
int main() {
	int test, cases = 1;
	cin >> test;
	for( cases=1; cases<=test; cases++ ) {
		cin >> a >> b;
		vd.clear();
		int i;
		for(i=0;i<a;i++) {
			double d;
			cin >> d;
			vd.pb(d);
		}

		double res = b + 2; // hit enter right away
	
		double prob = 1;
		for(i=0; i<vd.size(); i++)
			prob *= vd[i];

		for(i=0; i<= vd.size(); i++) { // delete i characters from right
			double k = prob * (i + i + 1 + b - a) + (1.0 - prob) * (i + i + b - a + 1 + b + 1);
		        res <?= k;
			if( i < vd.size() )
				prob /= vd[ vd.size() - i - 1];	
		}
		pf("Case #%d: %.8lf\n", cases, res);
	}
	return 0;
}

