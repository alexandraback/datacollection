#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	freopen("inBs.txt", "r", stdin);
	freopen("outBs.txt", "w", stdout);
	ll t;
	cin>>t;
	for(int cases = 1; cases <=t; cases++) {

		ll jj, pp, ss, kk;
		cin>>jj>>pp>>ss>>kk;
		map<pair<pair<ll, ll>, ll>, ll> mp;
		mp.clear();
		vector<pair<pair<ll, ll>, ll> > v;
		cout<<"Case #"<<cases<<": ";
		for(int i=1;i<=jj;i++) {
			for(int j=1;j<=pp;j++) {
				for(int k=1;k<=ss;k++) {
					pair<pair<ll, ll>, ll> pr1, pr2, pr3;
					pr1 = make_pair(make_pair(i, j), 0);
					if(mp[pr1] >= kk)	continue;
					pr2 = make_pair(make_pair(0, j), k);
					if(mp[pr2] >= kk)	continue;
					pr3 = make_pair(make_pair(i, 0), k);
					if(mp[pr3] >= kk)	continue;
					mp[pr1]++;
					mp[pr2]++;
					mp[pr3]++;
					v.push_back(make_pair(make_pair(i,j), k));
					//cout<<i<<" "<<j<<" "<<k<<"\n";
				}
			}
		}

		cout<<v.size()<<"\n";
		for(int i=0;i<v.size();i++) {
			cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second<<"\n";
		}
		
		
	}
	return 0;
}