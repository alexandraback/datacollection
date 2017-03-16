// -*- compile-command: "g++ -g -Wno-return-type -Wall -Wextra -DLOCAL -std=c++11 -D_GLIBCXX_DEBUG b.cpp -ob && ./b " -*-
#include <bits/stdc++.h>
using namespace std;
using LL=long long;
#define int LL
#define vc vector
#define pb push_back
#define pr pair
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define f(i,n) for(int i=0;i<(n);i++)
#define fv(i,v) f(i,sz(v))

int check(vc<vc<bool> >& r){
	vc<int> k(r.size());
	k[1]=1;
	for(int i=1;i<sz(r);i++){
		for(int j=1;j<i;j++){
			if(r[j][i]) k[i]+=k[j];
		}
	}
	return k[k.size()-1];
}


void solve(){
	int b,m;
	cin>>b>>m;
	vc<int> fb(b+2);
	fb[1]=1;
	for(int i=2;i<=b;i++){
		for(int j=1;j<i;j++)
			fb[i]+=fb[j];
	}
	vc<vc<bool> > r(b+1,vc<bool>(b+1,0));
	for(int i=1;i<b;i++){
		for(int j=1;j<b;j++)
			r[i][j]=i<j;
	}
	int mm=m;
	for(int i=b-1;i>=1;i--){
		assert(fb[i]>0);
		if(fb[i]<=mm){
			mm-=fb[i];
			r[i][b]=1;
		}
	}
	if(mm){ cout<<"IMPOSSIBLE\n"; return; }
	cout<<"POSSIBLE\n";
	for(int i=1;i<=b;i++){
		for(int j=1;j<=b;j++)
			cout<<r[i][j];
		cout<<'\n';
	}
	//assert(check(r)==m);
}

main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		cout<<"Case #"<<t<<": ";
		solve();
	}
}
