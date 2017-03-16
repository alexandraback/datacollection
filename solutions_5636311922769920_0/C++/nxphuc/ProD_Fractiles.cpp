/*
Author:
Prob:
Link:
Tag:
Comp:
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define iii pair<ii, int>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define cl(a) a.clear()

#define vi vector<int>
#define vii vector<ii>

#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)

const int MAX = 5e5 + 10;
const int MAXN = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

ll Pow(int b, int p){
	if (!p) return 1;
	ll ret = Pow(b, p/2);
	ret *= ret;
	if (p & 1) ret *= b;
	return ret;
}


int main(){
	// freopen("test.in", "rt", stdin);
	freopen("D-small-attempt2.in", "rt", stdin);
	freopen("D-small-attempt2.out", "wt", stdout);
	ios::sync_with_stdio(false);

	int t, k, c;
	ll s, m, n;
	vector<ll> a;

	cin >> t;
	FOR(cs,1,t){
		cin >> k >> c >> s;
		cout << "Case #" << cs << ":";

		FOR(i,1,k){
			n = i;
			REP(j,1,c)
				n = (n-1)*k + i;
			cout << " " << n;
		}
		cout << endl;


		// if (c == 1){
		// 	if (s < k)
		// 		cout << " IMPOSSIBLE" << endl;
		// 	else{
		// 		FOR(i,1,k)
		// 			cout << " " << i;
		// 		cout << endl;
		// 	}
		// 	continue;
		// }
		// a.clear();
		// n = Pow(k, c);
		// m = Pow(k, c-1);
		// for (int i = 1; i < k; i+=2)
		// 	a.pb(2LL + m*(i-1));
		// if (k & 1)
		// 	a.pb(n);
		// if (a.size() > s)
		// 	cout << " IMPOSSIBLE" << endl;
		// else{
		// 	REP(i,0,a.size())
		// 		cout << " " << a[i];
		// 	cout << endl;
		// }
	}

	return 0;
}