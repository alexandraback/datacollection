#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 111111
using namespace std;
typedef pair<int,int> pt;

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		int n;
		cin >> n;
		vector<pair<int, int> > e;
		for (int i = 0; i < n; i++) {
			int d, ni, m;
			cin >> d >> ni >> m;
			for (int j = 0; j < ni; j++) {
				e.pb(mp(d, m));
				m++;
			}				
		}
		if (e.size() > 2) {
			puts("!");
			break;
		}			

		cout << "Case #" << tt << ": ";

		if (e.size() == 1 || e[0].S == e[1].S) {
			cout << 0 << endl;
		}
		if (e[0].S < e[1].S) swap(e[0], e[1]);
		
		long double t1 = (360 - e[0].F) / 360. * e[0].S;
		long double t2 = t1 + e[0].S;


		long double tt1 = (360 - e[1].F) / 360. * e[1].S;
		long double tt2 = tt1 + e[1].S;

		t1 = max(t1, tt1);
		t2 = min(t2, tt2);
		int ans = 0;
		if (t2 - t1 > 1e-10) ans = 0; else ans = 1;

		cout << ans << endl;
		
	}
	return 0;
}