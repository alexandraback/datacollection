#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i = a ; i < b ; i++)
#define pb push_back
#define FOREACH(x,y) for(typeof(y.begin()) x = y.begin() ; x != y.end() ; x++)
#define DEB(v) cout << "#v = " << endl;

long long MOD = (long long)1000000007;

unsigned long long int C[102][102];

unsigned long long solve(vector <unsigned long long int> a1, vector <int> a2, vector <unsigned long long int> b1, vector <int> b2, int m, int n ) {
	FOR(i,1,m+1) {
		FOR(j,1,n+1) {
			if(a2[i-1] == b2[j-1]) {
				unsigned long long int count = min(a1[i-1],b1[j-1]);
				a1[i-1] = a1[i-1] - count;
				b1[j-1] = b1[j-1] - count;
				C[i][j] = max(C[i][j-1],C[i-1][j-1]);
				C[i][j] = max(C[i][j],C[i-1][j]) + count;
			} else {
				C[i][j] = max(C[i][j-1],C[i-1][j]);
			}
		}
	}
	return C[m][n];
}

int main() {
	int T;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>T;
	for(int tc = 1 ; tc <= T ; tc++) {
		int n,m;
		cin >> n >> m;
		vector <int> a2,b2;
		vector <unsigned long long int> a1,b1;
		unsigned long long int c;
		FOR(i,0,2*n) {
			cin>>c;
			if(i%2 == 0) a1.pb(c);
			else a2.pb(c);
		}
		FOR(i,0,2*m) {
			cin>>c;
			if(i%2 == 0) b1.pb(c);
			else b2.pb(c);
		}
		FOR(i,0,102) {
			FOR(j,0,102) {
				C[i][j] = 0;
			}
		}
		unsigned long long ans;
		ans = solve(a1,a2,b1,b2,n,m);
		cout << "Case #" << tc << ": " << ans << endl;
	}
	return (0);
}