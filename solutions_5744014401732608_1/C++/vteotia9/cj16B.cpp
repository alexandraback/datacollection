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

ll tc,b,m,sum,ans[60][60];

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
//	ios::sync_with_stdio(0);
	
	cin>>tc;
	for(ll t=1;t<=tc;t++){
		cin>>b>>m;
		
		memset(ans,0,sizeof(ans));
		if(m > pow(2,b-2)){
			cout<<"Case #"<<t<<": IMPOSSIBLE\n";
			continue;
		}
		cout<<"Case #"<<t<<": POSSIBLE\n";
		ll temp  = log2(m);
		for(ll i=1;i<=temp+1;i++){
			ans[i][b] = 1;
			for(ll j=1;j<i;j++){
				ans[j][i] = 1;
			}
		}
	//	cout<<temp<<" ";
		ll mx = temp+1;
		temp = m-pow(2,temp);
	// 	cout<<mx<<" "<<temp<<"\n";
		if(temp)
			ans[mx+1][b] = 1;
		while(temp){
			ll x = log2(temp);
			ans[x+2][mx+1] = 1;
			temp = temp-pow(2,x);
		}
		for(ll i=1;i<=b;i++){
			for(ll j=1;j<=b;j++)
				cout<<ans[i][j];
			cout<<"\n";
		}
	}
	return 0;
}

