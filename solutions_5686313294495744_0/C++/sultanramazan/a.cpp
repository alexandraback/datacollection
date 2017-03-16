#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define sqr(x) (x) * (x)
#define forn(i, l, r) for(int i = l; i < r; i ++)
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define y1 salnk
#define N 200100              
#define sz(a) (int)a.size()
#define ll long long
const int inf = (int)1e9;
const double pi = acos(-1.0);
const double eps = 1e-9;

int t, n;
pair <string, string> p[N];
vector <string> v1, v2;
int res, dp[N], qq;
int main () {
    //freopen("in", "r", stdin);
    cin >> t;
    while (t--) {
     	cin >> n;
     	for (int i = 0; i < n; i++) {
     	 	cin >> p[i].f >> p[i].s;
     	}
     	for (int mask = 0; mask < (1 << n); mask++) 
     		dp[mask] = 0;
     	res = 0;
     	for (int mask = 0; mask < (1 << n); mask++) {
     		res = max(res, dp[mask]);
     		v1.clear();
     		v2.clear();
     		for (int i = 0; i < n; i++)
     			if (mask & (1<<i)) v1.pb(p[i].f), v2.pb(p[i].s);
     		sort(v1.begin(), v1.end());
     		sort(v2.begin(), v2.end());
     		for (int i = 0; i < n; i++) 
     			if (mask & (1<<i)); else {

     			//	if (mask == 3) cerr << binary_search(v1.begin(), v1.end(), p[i].f)<<" "<<p[i].f << " " << p[i].s <<" " << binary_search(v2.begin(), v2.end(), p[i].s)<< endl;
     			
     				if (binary_search(v1.begin(), v1.end(), p[i].f) && binary_search(v2.begin(), v2.end(), p[i].s)) {
     					dp[mask|(1<<i)] = max(dp[mask|(1<<i)], dp[mask] + 1);
     			 	}	
                  }
     	}
     	qq++;
     	cout << "Case #"<<qq<<": ";
     	cout << res << endl;
    }
    return 0;
}