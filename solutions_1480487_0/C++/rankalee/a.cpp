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

int n, s[200], sum;
double ans[200];
int main(){
	int CS;
	cin >> CS;
	rep(cs, CS){
		cin >> n;
		sum = 0;
		rep(i, n) cin >> s[i], sum += s[i];
		rep(k, n){
			double lo = 0, hi = 1, mid;
			rep(it, 100){
				mid = (lo + hi) / 2;
				double l = 0, r = 1e9, m;
				rep(it2, 100){
					m = (l + r) / 2;
					double tmp = 0;
					rep(i, n) if(i != k) tmp += max(0.0, m - s[i]);
					if(tmp > sum * (1 - mid)) r = m;
					else l = m;
				}
				bool ok = m <= s[k] + sum * mid;
				if(ok) hi = mid;
				else lo = mid;
			}
			ans[k] = mid;
		}
		cout << "Case #" << cs + 1 << ":";
		rep(i, n) printf(" %.9f", ans[i] * 100);
		cout << endl;
	}
	return 0;
}
