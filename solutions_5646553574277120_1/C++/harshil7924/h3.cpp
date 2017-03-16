#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define f first
#define s second
#define mod 1000000009
#define inf 1e8

#define pi pair<int,int>
#define pii pair<ll,pi>
#define f first
#define mp make_pair
#define s second
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
	freopen("C-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	ll c,d,v;
	ll a[10001];
	int cnt=0;
	while(t--){
		cnt++;
		cin>>c>>d>>v;
		rep(i,d)
			cin>>a[i];
		ll s=0;
		ll k=0;
		ll ans=0;
		for(ll i=1;i<=v;i++){
			while(k<d and a[k]<=i)  s+=c*a[k],k++;
			if(s>=i){
				i=s;
				continue;
			}
			s+=c*i;
			i=s;
			ans++;
		}
		cout<<"Case #"<<cnt<<": "<<ans<<"\n";
	}
}
