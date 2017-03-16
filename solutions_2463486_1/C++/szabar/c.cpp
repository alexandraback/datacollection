#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <deque>
#include <cstdio>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <sstream>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<double> vd;
template<class T> void pr(T a, T b) { for(T i = a; i != b; ++i) cout << *i << " "; cout << endl; }

set<ll> m;
map<ll, ll> z;

string omit_zeros(string s){
	string res;
	int f = 0;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] != '0') f = 1;
		if(f == 1) res += s[i];
	}
	return res;
}

bool is_pali(ll q){
	string s;
	while(q != 0LL) {
		s += (char) ('0' + q%10LL);
		q = q / 10LL;
	}
	string t = s;
	reverse(t.begin(), t.end());
	return s == t;
}

void is_sqrt(string s){
	istringstream ss(s);
	ll n;
	ss >> n;
	ll q = sqrt(n);
	if(q * q == n && is_pali(q)) {
		m.insert(n);
//		cout << n << endl;
	}
}

void solve(string s){
	s = omit_zeros(s);
	if(s.size() == 0) return;
	string t = s;
	reverse(t.begin(), t.end());
	is_sqrt(s + t);
//	cout << s+t << endl;
	is_sqrt(s + t.substr(1, t.length() - 1));
//	cout << s + t.substr(1, t.length() - 1) << endl;
}

void f(string s, int l){
	if(s.size() == l) return solve(s);
	for(char c = '0'; c <= '9'; ++c){
		f(s+c, l);
	}
}

void dupa(){
	ll a, b;
	cin >> a >> b;
	set<ll> :: iterator ai;
	set<ll> :: iterator bi;
	ai = m.lower_bound(a);
	if(m.find(a) == m.end()) ai--;
	bi = m.lower_bound(b);
	if(m.find(b) == m.end()) bi--;
	ll res = z[*bi] - z[*ai];
	if(m.find(a) != m.end()) res++;
	cout << res << endl;
}

void gen(){
	string empty;
	f(empty, 7);
	set<ll> :: iterator it;
	ll i = 1;
	for(it = m.begin(); it != m.end(); ++it){
		z[*it] = i;
		i++;
	}
}

int main(){
	int z;
	cin >> z;
	gen();
	for(int i = 0; i < z; ++i){
		cout << "Case #" << i+1 << ": ";
		dupa();
	}
}
