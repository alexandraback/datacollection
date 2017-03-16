#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, l;

ll n;
const int N = 1000000;
int d[N+1];

int rev(int n) {
	vector<int> v;
	while (n > 0) {
		v.push_back(n % 10);
		n /= 10;
	}
	int ret = 0;
	F0(i,SZ(v)) ret = ret * 10 + v[i];
	return ret;
}

int main() {
    //freopen("x.in", "r", stdin);

	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	//freopen("A-large.in", "r", stdin);
	//freopen("A-large.out", "w", stdout);

	int tt, tn; cin >> tn;

	d[1] = 1;
	queue<int> Q; Q.push(1);
	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();

		if (i + 1 <= N && d[i + 1] == 0) {
			d[i + 1] = d[i] + 1;
			Q.push(i + 1);
		}

		if (i % 10 != 0) {
			int j = rev(i);
			if (d[j] == 0) {
				d[j] = d[i] + 1;
				Q.push(j);
			}
		}
	}
	

	F1(tt,tn) {
		cerr << tt << endl;

		cin >> n;
		int ans = d[n];

  		printf("Case #%d: ", tt);
		cout << ans << endl;
	}
	return 0;
}
