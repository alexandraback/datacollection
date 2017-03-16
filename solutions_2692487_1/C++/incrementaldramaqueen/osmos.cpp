#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <math.h>
#include <queue>
#include <string.h>
#include <sstream>
#define fo(i,n) for(i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define sz(x) ((int) x.size())
#define mset(a,v) memset(a, v, sizeof(a))
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;

int compute(const vector< ll > &v, ll A, int ind) {
    ll val = A;
    int ret = 0, i;
    fo(i,ind) {
	while(val <= v[i]) {
	    val += (val-1);
	    ret++;
	}
	val += v[i];
    }
    return ret;
}

int main(void) {
    int t, tt = 0, n, k, i;
    cin >> t;
    fo(tt, t) {
	ll A;
	vector < ll > v;
	cin >> A >> n;
	fo(i,n) {
	    ll x;
	    cin >> x;
	    v.pb(x);
	}
	sort(all(v));
	
	int ans = n;
	if (A > 1) {
	    fo(k,n) {
		int tans = k + compute(v, A, n-k);
		ans = min(ans, tans);
	    }
	}

	cout << "Case #" << tt+1 << ": " << ans << endl;
    }
}
