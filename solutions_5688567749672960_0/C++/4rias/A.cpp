#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T>
ll toL(T t){stringstream ss;ss<<t;ll r;ss>>r;return r;}

template <class T>
string toS(T t){stringstream ss;ss<<t;string r;ss>>r;return r;}

int main(){
	int n,nc=0;cin>>n;
	while(n--){
		ll t;cin>>t;
		ll start = 1;
		queue<pair<ll,ll> > Q;Q.push({start,1});
		set<ll> vis;vis.insert(start);
		cout<<"Case #"<<++nc<<": ";
		while(!Q.empty()){
			ll nu = Q.front().first;
			ll pa = Q.front	().second;
			
			Q.pop();
			
			if(nu==t){cout<<pa<<endl;break;}
			ll tt = nu +1;
			if(vis.count(tt))continue;
			else{Q.push({tt,pa+1});vis.insert(tt);}
			
			string ts = toS(nu);
			reverse(ts.begin(),ts.end());
			tt = toL(ts);
		
			if(vis.count(tt))continue;
			else{Q.push({	tt,pa+1});vis.insert(tt);}
			
		}
	}
}
