#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<complex>
#include<sstream>
#include<iomanip>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb(x) push_back(x)
#define ll long long
#define VI vector<int>

typedef pair<ll,ll> pi;

ll amin[20], amax[20];
ll bmin[20], bmax[20];
string a, b;
int n;

inline bool f(const pi &x, const pi &y){
	if(abs(x.first-x.second) != abs(y.first-y.second))
		return abs(x.first-x.second) < abs(y.first-y.second);
	if(x.first != y.first)
		return x.first < y.first;
	return x.second < y.second;
}

pi best(pi x, pi y, pi z){
	pi r[] = {x, y, z};
	return *min_element(r, r+3, f);
}


pi f(ll x, ll y, int k){
	if(k == n)
		return pi(x,y);

	if(isdigit(a[k]) && isdigit(b[k])){
		if(a[k] > b[k])
			return pi(pow(10,n-k)*x+amin[k], pow(10,n-k)*y+bmax[k]);
		else if(a[k] < b[k])
			return pi(pow(10,n-k)*x+amax[k], pow(10,n-k)*y+bmin[k]);
		else
			return f(x*10+a[k]-'0', y*10+b[k]-'0', k+1);
	}else if(isdigit(a[k])){
		pi p1 = f(x*10+a[k]-'0', y*10+a[k]-'0', k+1);
		pi p2 = (a[k] == '0')?p1:pi(pow(10,n-k-1) *(x*10+a[k]-'0') + amin[k+1], pow(10,n-k-1) * (y*10+a[k]-'1') + bmax[k+1]);
		pi p3 = (a[k] == '9')?p1:pi(pow(10,n-k-1) *(x*10+a[k]-'0') + amax[k+1], pow(10,n-k-1) *(y*10+1+a[k]-'0')+bmin[k+1]);
		return best(p1, p2, p3);
	}else if(isdigit(b[k])){
		pi p1 = f(x*10+b[k]-'0', y*10+b[k]-'0', k+1);
		pi p2 = (b[k] == '0')?p1:pi(pow(10,n-k-1) *(x*10+b[k]-'1') + amax[k+1], pow(10,n-k-1) * (y*10+b[k]-'0') + bmin[k+1]);
		pi p3 = (b[k] == '9')?p1:pi(pow(10,n-k-1) *(x*10+1+b[k]-'0') + amin[k+1],pow(10,n-k-1) * (y*10+b[k]-'0') + bmax[k+1]);
		return best(p1, p2, p3);
	}else{
		pi p1 = f(x*10, y*10, k+1);
		pi p2 = pi(pow(10,n-k-1) * (x*10+1) +amin[k+1], pow(10, n-k-1)*(y*10)+bmax[k+1]);
		pi p3 = pi(pow(10,n-k-1) * (x*10) +amax[k+1], pow(10,n-k-1) * (y*10+1) + bmin[k+1]);
		return best(p1, p2, p3);
	}
}


void solve(){
	cin >> a >> b;
//	cout << a << " " << b << endl;
	n = a.length();
	ll p = 1;
	amin[n] = amax[n] = bmin[n] = bmax[n] = 0;
	for(int i=n-1;i>=0;i--,p*=10){
		amin[i] = amin[i+1] + p*((a[i] == '?')?0:(a[i]-'0'));
		amax[i] = amax[i+1] + p*((a[i] == '?')?9:(a[i]-'0'));
		bmin[i] = bmin[i+1] + p*((b[i] == '?')?0:(b[i]-'0'));
		bmax[i] = bmax[i+1] + p*((b[i] == '?')?9:(b[i]-'0'));
//		cout << amin[i] << " " << amax[i] << endl;
//		cout << bmin[i] << " " << bmax[i] << endl;
	}
	pi ans = f(0, 0, 0);
	cout << setfill('0') << setw(n) << ans.first << " " << setfill('0') << setw(n) << ans.second << endl;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	rep(g,t){
		cout << "Case #" << g+1 << ": ";
		solve();
	}
	return 0;
}
