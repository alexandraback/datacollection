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

int n;
struct node {
	int a, b;
};

vector<node> v;
int flag[1005];

bool cmp(const node &a, const node &b) {
	if( a.b != b.b ) return a.b > b.b;
	return a.a < b.a;
}

int main() {
	int test, cases = 1;
	cin >> test;
	for( cases=1; cases<=test; cases++ ) {
		cin >> n;
		int i;
		v.clear();
		for(i=0; i<n; i++) {
			node A;
			cin >> A.a >> A.b;
			v.pb(A);
			flag[i] = 0;
		}

		sort(v.begin(), v.end(), cmp);
		int res = 0;
		int star = 0;
		while(1) {
			for(i=0;i<n;i++) { // can solve 2 directly
				if( flag[i] == 0 ) {
					if( v[i].b <= star ) {
						star += 2;
						flag[i] = 2;
						res++;
						goto done;
					}		
				}
			}
			// solve 2 after 1
			for(i=0;i<n;i++) {
				if( flag[i] == 1 ) {
					if( v[i].b <= star ) {
						star++;
						flag[i] = 2;
						res++;
						goto done;
					}
				}
			}

			for(i=0;i<n;i++) {
				if( flag[i] == 0 ) {
					if( v[i].a <= star ) {
						star++;
						flag[i] = 1;
						res++;
						goto done;
					}
				}
			}
			break;

done:;
		}

		for(i=0;i<n;i++) {
			if( flag[i] != 2 ) break;
		}

		if( i == n ) 
			pf("Case #%d: %d\n", cases, res);
		else
			pf("Case #%d: Too Bad\n", cases);

	}
	return 0;
}


