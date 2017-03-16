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

string toBin(ll n){
	string s = "";
	while (n){
		s = char('0' + (n % 2)) + s;
		n /= 2;
	}
	return s;
}

ll toBase(string s, int b){
	ll p = 1;
	ll ret = 0;
	FOD(i,s.length()-1,0){
		if (s[i] == '1')
			ret += p;
		p *= b;
	}
	return ret;
}

ll calc(ll n){
	for (ll i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return i;
	return -1;
}

int main(){
	freopen("C-small-attempt0.in", "rt", stdin);
	freopen("C-small-attempt0.out", "wt", stdout);
	ios::sync_with_stdio(false);

	int n, m, flag, cnt;
	ll a, b[12];
	string s;

	cin >> n >> n >> m;
	a = Pow(2,n-1) + 1;
	
	cnt = 0;
	cout << "Case #1:\n";
	while (cnt < m){
		s = toBin(a);
		flag = 1;
		FOR(i,2,10)
			if ((b[i] = calc(toBase(s, i))) == -1){
				flag = 0;
				break;
			}

		if (flag){
			cout << s;
			FOR(i,2,10) cout << " " << b[i];
			++cnt;
			cout << endl;
		}
		a += 2;
	}

	return 0;
}