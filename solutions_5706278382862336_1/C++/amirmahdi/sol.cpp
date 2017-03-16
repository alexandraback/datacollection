#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>

#define rep(i,n) for(int i=0;i<n;i++)
#define VI vector<int>
#define pb(x) push_back(x)
#define ll long long
#define For(i,a,b) for(int i=a;i<b;i++)
#define sz(s) int(s.size())
using namespace std;

ll tot = 1ll << 40;

int main() {
	int t;
	cin >> t;
	rep(g,t){
		cout << "Case #" << g+1 << ": " ;
		ll p, q;
		char ch;
		cin >> p >> ch >> q;
		ll pq = __gcd(p, q);
		q/=pq;
		if(tot%q != 0)
			cout << "impossible" << endl;
		else{
			ll x = (tot/q) * (p/pq);
			int ans = 40;
			while(x >= 2){
				x/=2;
				ans--;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
