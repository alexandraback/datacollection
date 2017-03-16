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

ll tc;
string str,ans;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);
	
	cin>>tc;
	for(ll t=1;t<=tc;t++){
		cin>>str;
		ans = str[0];
		for(ll i=1;i<str.length();i++){
			if(str[i] < ans[0])
				ans = ans+str[i];
			else
				ans = str[i]+ans;
		}
		
		cout<<"Case #"<<t<<": "<<ans<<"\n";
	}
	return 0;
}

