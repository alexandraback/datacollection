#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define fr(i, c) for(__typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define mp make_pair
#define dbg(x) cerr << #x << " = " << (x) << endl

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll; 

template<class T>ostream& operator<<(ostream &os, vector<T> &v){
	os << "["; rep(i, v.size()) os << v[i] << ", "; os << "]"; return os;
}
template<class T, class U>ostream &operator<<(ostream &os, pair<T, U> &p){
	os << "(" << p.first << ", " << p.second << ")"; return os;
}

int n, a[20];
vector<pair<int, pi> > v;
void out(int r, int s, int p, int q){
	p ^= q; r ^= s;
	vi x, y;
	rep(i, n/2){
		if(p & 1<<i) x.pb(a[i]);
		if(r & 1<<i) x.pb(a[i]);
	}
	rep(i, n-n/2){
		if(q & 1<<i) y.pb(a[i]);
		if(s & 1<<i) y.pb(a[i + n/2]);
	}
	rep(i, x.size()) cout << x[i] << (i == x.size()-1 ? "\n" : " ");
	rep(i, y.size()) cout << y[i] << (i == y.size()-1 ? "\n" : " ");
}
void pv(int n){
	rep(i, 10) cerr<<(n>>i&1);
	cerr<<endl;
}

int main(){
	int CS;
	cin >> CS;
	rep(cs, CS){
		cout << "Case #" << cs + 1 << ":" << endl;
		v.clear();
		cin >> n;
		rep(i, n) cin >> a[i];
		rep(i, 1<<n/2) for(int j = i; j; j = j - 1 & i){
			int sum = 0;
			rep(k, n/2) if(i & 1<<k){
				if(j & 1<<k) sum += a[k];
				else sum -= a[k];
			}
			v.pb(mp(sum, mp(i, j)));
			if(sum == 0 && j + (i ^ j) != 0){
				out(0, 0, i, j);
				goto END;
			}
		}
		v.pb(mp(0, mp(0, 0)));
		sort(all(v));
		rep(i, 1<<n-n/2) for(int j = i; ; j = j - 1 & i){
			int sum = 0;
			rep(k, n-n/2) if(i & 1<<k){
				if(j & 1<<k) sum -= a[k + n/2];
				else sum += a[k + n/2];
			}
			vector<pair<int, pi> >::iterator it;
			it = lower_bound(all(v), mp(sum, mp(0, 0)));
			if(it->first == sum){
				if((i ^ j) + (it->second.second ^ it->second.first) != 0)
				if(j + it->second.second != 0){
					out(i, j, it->second.first, it->second.second);
					goto END;
				}
			}
			if(j == 0) break;
		}
		cout << "impossible" << endl;
		END:;
	}
	return 0;
}
