#include<cstdio>
#include<vector>

using namespace std;

typedef long long ll;

int T,cs;
ll n,ten[20];

ll solve(ll n) {
	if(n == 0) return 0;
	vector<int> v;
	ll nn = n;
	while(nn) v.push_back(nn%10), nn /= 10;
	ll ans = 0;
	int sz = v.size();
	if(sz == 1) return n;
	if(v[sz-1] == 1) {
		ans += n - ten[sz-1] * v[sz-1] + 1;
		ans += solve(ten[sz-1] - 1);
	}
	else {
		if(v[0] == 0) {
			ans += 1 + solve(n - 1);
		}
		else {
			for(int i=0;i<(sz+1)/2;++i) v[i] = 0;
			v[0] = 1;
			ll rv = 0, tt = 0;
			for(int i=sz-1;i>=0;--i) tt *= 10, tt += v[i];
			for(int i=0;i<sz;++i) rv *= 10, rv += v[i];
			ans += n - tt + 1 + solve(rv);
		}

	} return ans;
}

ll rev(ll n) {
	vector<int> v;
	while(n) v.push_back(n%10), n /= 10;
	ll r = 0;
	for(int i=0;i<v.size();++i) r *= 10, r += v[i];
	return r;
}

ll solve2(ll n) {
	vector<int> v;
	ll nn = n;
	while(nn) v.push_back(nn%10), nn /= 10;
	if(v.size() == 1) return n;
	ll ans = 0, cur = 1;
	int sz = 1;
	while(true) {
		if(sz >= v.size()) break;
		ans += ten[sz/2]-1 + ten[sz-sz/2]-1 + 1;
		sz++, cur *= 10;
	}

	ll mn = n - cur, add = 0;
	if(mn == 0) return ans;
	for(int i=0;i<sz;++i) {
		if(v[i] == 0) v[i] = 9;
		else {v[i]--; break;}
	}
	for(int i=sz/2;i<sz;++i) add *= 10, add += v[i];
	mn = min(mn, add + 1 + n - rev(cur + add));

	return ans + mn;
}

int main() {
	scanf("%d",&T);
	ten[0] = 1;
	for(int i=1;i<=18;++i) ten[i] = ten[i-1]*10;
	for(cs=1;cs<=T;++cs) {
		printf("Case #%d: ",cs);
		scanf("%lld",&n);
		printf("%lld\n",solve2(n));
	}
}
