
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <climits>
#include <complex>
#include <numeric>
using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define RREP(i,n) for(int i=(int)n-1; i>=0; i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
#define ALL(c) (c).begin(), (c).end()

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pipii;
typedef vector<int> vi;

const int INF = 1e9;
const int MOD = 1e9+7;

int main(void){
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		int b;
		ll m;
		cin >> b >> m;
		ll k = 0, res = 0;
		for(int bb = 2; bb <= b; bb++){
			res = k + 1;
			k += res;
		}
		//cout << "under " << res << endl;
		cout << "Case #" << tt << ": ";
		if(res < m){
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		cout << "POSSIBLE" << endl;
		int n = b;
		vector<vi> ans(n, vi(n, 0));
		for(int i = 1; i < n; i++){
			for(int j = i + 1; j < n; j++){
				ans[i][j] = 1;
			}
		}
		int tail = n - 2;
		if(m == res){
			m--;
			ans[0][n-1] = 1;
		}	
		while(m){
			if(m % 2){
				ans[0][tail] = 1;
			}
			m /= 2;
			tail--;
		}
		for(int i = 0; i < n; i++){
			REP(j, n){
				cout << ans[i][j];
			}
			cout << endl;
		}
	}
	
	return 0;
}

