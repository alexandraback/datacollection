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
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	int r,c,w;
	int cnt=0;
	while(t--){
		cnt++;
		cin>>r>>c>>w;
		int ans;
		if(c%w==0){
			ans=c/w;
			ans*=r;
			ans=ans+w-1;
		}
		else{
			ans=c/w;
			ans*=r;
			ans+=w;
		}
		cout<<"Case #"<<cnt<<": "<<ans<<"\n";
	}
}
