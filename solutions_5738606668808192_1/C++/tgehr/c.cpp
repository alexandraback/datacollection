#include <bits/stdc++.h>
using namespace std;
#define vc vector
#define pb push_back
#define int __int128

string gen(int n){
	string s="1";
	for(int i=0;i<n-2;i++)
		s+='0'+rand()%2;
	s+='1';
	return s;
}

bool check(string& s,vc<int>& c){
	for(int b=2;b<=10;b++){
		int r=0;
		for(char c:s)
			r=b*r+(c-'0');
		bool ok=false;
		for(int i=2;i*i<=r&&i<=100000;i++){
			if(!(r%i)){
				ok=true;
				c.pb(i);
				break;
			}
		}
		if(!ok) return false;
	}
	return true;
}

void solve(int n,int j){
	map<string,vc<int>> m;
	while(m.size()<j){
		auto s=gen(n);
		if(m.count(s)) continue;
		vc<int> c;
		if(!check(s,c)) continue;
		m[s]=c;
		cerr<<m.size()<<endl;
	}
	for(auto& k:m){
		cout<<k.first;
		for(auto p:k.second)
			cout<<" "<<(long long)p;
		cout<<'\n';
	}
}

main(){
	long long T,n,j;
	cin>>T;
	assert(T==1);
	cin>>n>>j;
	cout<<"Case #"<<1<<":\n";
	solve(n,j);
}
