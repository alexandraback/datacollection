#include<bits/stdc++.h>
#define maxn 500009
#define INF 1000000007
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define mid(a,b) (a+b)/2
#define sz size()
#define ll long long
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define tr(i, c) for(typeof((c).begin()) i = (c).begin(); i!=(c).end(); i++)
using namespace std;
ll pw(ll x, ll y){
	if(y==0)
		return 1;
	if(y%2){
		return pw(x,y/2)*pw(x,y/2)*x;
	}	
	else
		return pw(x,y/2)*pw(x,y/2);
}
int main(){
	freopen("2.in" , "r" , stdin);
	freopen("1.out" , "w" , stdout);
	ll t;
	cin>>t;
	for(int u=0;u<t;u++){
		ll k,c,s;
		cin>>k>>c>>s;
		cout<<"Case #"<<u+1<<": ";
		if(s<(k+1)/2){
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		if(c==1){
			if(s<k)
			cout<<"IMPOSSIBLE"<<endl;
			else{
				for(int i=1;i<=s;i++){
					cout<<i<<" ";
				}
				cout<<endl;
			}
			continue;
		}
		ll r;
		ll o;
		cout<<2<<" ";
		r = 3;
		for(int i=2;i<=k;i++){
			o = pw(k,c-1)*(r-1)+r+1;
			if(o<=pw(k,c))
				cout<<o<<" ";
			else if(o-r<=pw(k,c)){
				cout<<pw(k,c-1)*(r-1)+1<<" ";
			}
			r+=2;
		}
		cout<<endl;
	}


return 0;
}
/*
3 2 3
1 2 3
1 G 1 2 2 2 3 3 3
*/
