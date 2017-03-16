//A
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <sstream>
#include <cstdio>
using namespace std;
typedef long long ll;
vector<ll> v;
ll inverte(ll n){
	string s;	
	stringstream ss;
	ss<<n;
	ss>>s;
	s = string(s.rbegin(),s.rend());
	stringstream ss1;
	ss1<<s;
	ll r;
	ss1>>r;
	return r;
}

int main(){
	int t;
	//cout<<inverte(13)<<endl;	
	//cin>>t;
	map<ll,int> m;
	vector<int> v(1000001);
	queue<ll> q;
	q.push(1);
	m[1]=1;
	v[1]=1;
	while(!q.empty()){
		ll a = q.front();q.pop();
		if(v[a+1])
			m[a+1] = min(m[a]+1,m[a+1]);
		else m[a+1]=m[a]+1;
		if(!v[a+1]&& a+1<=1000000){
			q.push(a+1);
			v[a+1]=1;
		}		
		
		ll inv = inverte(a);
		if(v[inv])
			m[inv] = min(m[inv],m[a]+1);
		else m[inv] = m[a]+1;
		if(!v[inv] && inv<=1000000){
			q.push(inv);
			v[inv]=1;
		}
		//cout<<a<<endl;
		//getchar();
		
	}
	cin>>t;
	int t1=t;
	
	while(t--){
		int n;
		cin>>n;		
		cout<<"Case #"<<t1-t<<": "<<m[n]<<endl;
	}
	return 0;
}
