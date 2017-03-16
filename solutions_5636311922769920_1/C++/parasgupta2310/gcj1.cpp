#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

ll k;

ll __pow(ll n,ll a){
	ll res =1;
	while(a){
		if(a&1){
			res*=n;
		}	
		n*=n;
		a>>=1;
	}
	return res;
}


ll get_idx(ll mn,ll mx,ll c){
	ll c1 = c-1;
	ll res = 1;
	for(ll i=0;i<c;i++){
		ll n = min(i+mn,mx)-1;
		res+=__pow(k,c1-i)*n;
	}
	return res;
}

void solve(ll c,ll s){
	ll req = k/c + (k%c>0?1:0);
	if(s<req)	{	cout<<"IMPOSSIBLE\n";	return;	}
	for(ll i=1;i<=k;i+=c){
		cout<<get_idx(i,min(i+c-1,k),c)<<' ';
	}
	cout<<'\n';
}


int main(){
	ios_base::sync_with_stdio(0);	cin.tie();
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	ll t;	cin>>t;
	for(ll tt=1;tt<=t;tt++){
		ll c,s;
		cin>>k>>c>>s;
		cout<<"case #"<<tt<<": ";
		solve(c,s);
	}
}