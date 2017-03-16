#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

int T, N, id;
pair < string, string > a[20];

void solve() {
	id++;
	cout << "Case #" << id << ": ";
	cin >> N;

	map < string, int > cnta, cntb;

	for (int i = 0; i < N; ++i) {
		cin >> a[i].f >> a[i].s;
	  if (cnta.find(a[i].f) == cnta.end()) 
	  	cnta[a[i].f] = 1;
	  else
			cnta[a[i].f]++;
	
		if (cntb.find(a[i].s) == cntb.end())
			cntb[a[i].s] = 1;
		else		
			cntb[a[i].s]++;
	}

	int ans = 0;

	for (int i = 0; i < N; ++i) {
		if (cnta[a[i].f] > 1 && cntb[a[i].s] > 1) {
			ans++;
			cnta[a[i].f]--;
			cntb[a[i].s]--;
		}
	}
	cout << ans << endl;
}


int main() {
	#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}
                                

