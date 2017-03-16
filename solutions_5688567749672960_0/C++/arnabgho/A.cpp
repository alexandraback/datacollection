#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pl;
ll reverse(ll n){
	ll res=0;
	while(n>0){
		res=res*10+n%10;
		n/=10;
	}
	return res;
}

std::vector<ll> v(1100000,1e9);
int main() {
	ll T;
	cin>>T;
	for (int cas = 1; cas <= T ; ++cas)
	{
		fill(v.begin(),v.end(),1e9);
		ll N;
		cin>>N;
		queue<pl> Q;
		v[1]=1;
		Q.push(pl(1,1));
		while(!Q.empty()){
			pl p=Q.front();
			Q.pop();
			ll val=p.first;
			// cout<<"val "<<val<<endl;
			if(val>N) continue;
			if(v[val]<p.second) continue;
			if(val+1<=N && v[val+1]>p.second+1){ Q.push(pl(val+1,p.second+1)); v[val+1]=p.second+1; }
			if(reverse(val)<=N  && v[reverse(val)]>p.second+1 ){Q.push(pl(reverse(val),p.second+1)); v[reverse(val)]=p.second+1;}
		}
		cout<<"Case #"<<cas<<": "<<v[N]<<endl;
	}
	return 0;
}