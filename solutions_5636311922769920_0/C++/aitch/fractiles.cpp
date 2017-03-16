#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef long double ld;

int main(){
	cin.sync_with_stdio(false);
	int T;
	cin >> T;
	rep(t,1,T+1){
		cout << "Case #" << t << ":";
		int k,c,s;
		cin >> k >> c >> s;
		if(c*s < k){
			cout << "IMPOSSIBLE\n";
		} else {
			vl v(1+(k-1)/c,1);
			vl ks(c);
			ks[0] = 1;
			rep(i,1,c) ks[i] = k*ks[i-1];
			rep(i,0,k)
				v[i/c] += i*ks[i%c];
			for(ll x : v)
				cout << " " << x;
			cout << endl;
		}
	}
}