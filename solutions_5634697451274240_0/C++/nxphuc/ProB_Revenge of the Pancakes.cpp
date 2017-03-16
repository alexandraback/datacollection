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

int main(){
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("B-small-attempt0.out", "wt", stdout);
	ios::sync_with_stdio(false);

	string s;
	int t, l, r, n, res;

	cin >> t;
	FOR(cs,1,t){
		cin >> s;
		n = s.length();
		l = r = 0;
		res = 0;
		while (l < n && r < n){
			while (l < n && s[l] == '+') l++;
			if (l >= n) break;
			r = l;
			while (r < n && s[r] == '-') r++;
			res += 1 + (l > 0);
			l = r;
		}
		cout << "Case #" << cs << ": " << res << endl;
	}

	return 0;
}