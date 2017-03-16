#include<bits/stdc++.h>
#define mod 1000000007
#include<bits/stdc++.h>
#define mod 1000000007
#define pp pair<ll,ll>
#define mp make_pair
#define ll long long
#define ff first
#define ss second
#define big 100000000000000000
using namespace std;

ll tc,n,hsh[3000],num;
vector<ll> ans;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);
	
	cin>>tc;
	for(ll t=1;t<=tc;t++){
		cout<<"Case #"<<t<<": ";
		cin>>n;
		ans.clear();
		memset(hsh,0,sizeof(hsh));
		for(ll i=0;i<2*n-1;i++){
			for(ll j=0;j<n;j++){
				cin>>num;
				hsh[num]++;
			}
		}
		for(ll i=1;i<=2500;i++){
			if(hsh[i] % 2)
				ans.push_back(i);
		}
		sort(ans.begin(),ans.end());
		ll sz = ans.size();
		for(ll i=0;i<sz;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
	}
	return 0;
}

