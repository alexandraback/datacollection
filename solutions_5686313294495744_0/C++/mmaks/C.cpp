#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
vector<pair<string, string> > v;
ll dp[1LL<<17];
ll poo(ll mask) {
	//cout<<mask<<"\n";
	if(mask == (1LL<<(n+1))-1) {
		return 0;
	}

	if(dp[mask] != -1) {
		return dp[mask];
	}
	map<string, int> ff, ss;
	ff.clear();
	ss.clear();
	for(int i=0;i<n;i++) {
		if(mask & (1 << i)) {
			ff[v[i].first] = 1;
			ss[v[i].second] = 1;
		}
	}
	ll temp = 0;
	for(int i=0;i<n;i++) {
		if(mask & (1<<i)) {
			continue;
		}
		if(ff[v[i].first] && ss[v[i].second]) {
			temp = max(temp , 1+poo(mask | (1<<i)));
		}
		else {
			temp = max(temp, poo(mask | (1<<i)));
		}
	}
	return dp[mask] = temp;
}

int main() {
	freopen("inCs.txt", "r", stdin);
	freopen("outCs.txt", "w", stdout);
	ll t;
	cin>>t;
	for(int cases = 1; cases <= t; cases ++) {
		v.clear();
		memset(dp, -1, sizeof(dp));
		cin>>n;
		for(int i=0;i<n;i++) {
			string a, b;
			cin>>a>>b;
			v.push_back(make_pair(a, b));
		}

		cout<<"Case #"<<cases<<": ";
		cout<<poo(0LL)<<"\n";
	}
}