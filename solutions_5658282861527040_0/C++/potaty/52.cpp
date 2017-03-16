#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;


typedef long long ll;
ll f[2][2][2][50];
ll a,b,k;
ll dp(ll fa,ll fb,ll fk,ll i){
	if(i<=-1) return 1; ll t;
	if((t=f[fa][fb][fk][i])!=-1)return t;
	ll res=0;
	for(ll a=0;a<=(!fa ? (::a>>i&1):1);a++)
		for(ll b=0;b<=(!fb ? (::b>>i&1):1);b++){
			ll x=a&b;
			if(!fk && (x>(::k>>i&1))) continue;
			res+=dp(fa|(a<(::a>>i&1)),fb|(b<(::b>>i&1)),fk|(x<(k>>i&1)),i-1);
		}
	f[fa][fb][fk][i]=res;
	return res;
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	ll T; cin>>T; ll tt=0;
	while(T--){
		
		cin>>a>>b>>k;  a--; b--; k--;
		memset(f,-1,sizeof f);
		cout<<"Case #"<<++tt<<": ";
		cout<<dp(0,0,0,31)<<endl;
	}
	return 0;
}