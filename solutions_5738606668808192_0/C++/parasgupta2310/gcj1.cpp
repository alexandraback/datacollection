#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

string s;

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

string to_bin(ll n,ll len){
	string res="";
	while(n){
		if(n&1)	res = "1"+res;
		else res = "0"+res;
		n>>=1;
	}
	while(res.length()<len)	res = "0"+res;
	return res;
}

ll to_ll(string s,ll base){
	ll res = 0;
	for(ll i=0;i<s.length();i++){
		res = res*base+(s[i]-'0');
	}
	return res;
}

void solve(ll n,ll j){
	j++;
	ll len = n/2 - 2;
	ll mx=__pow(2,len);
	//cout<<mx;
	mx = min(j,mx);

	for(ll i=2;i<=mx;i++){
		string bin = to_bin(i,len);
		bin = "1"+bin+"1";
		cout<<bin<<bin<<' ';
		for(ll base=2;base<=10;base++){
			cout<<to_ll(bin,base)<<' ';
		}
		cout<<'\n';
	}
}


int main(){
	ios_base::sync_with_stdio(0);	cin.tie();
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	ll t;	cin>>t;
	for(ll tt=1;tt<=t;tt++){
		ll n,j;
		cin>>n>>j;
		cout<<"case #"<<tt<<":\n";
		solve(n,j);
	}
}