// -*- compile-command: "g++ -g -Wno-return-type -Wall -Wextra -DLOCAL -std=c++11 -D_GLIBCXX_DEBUG c.cpp -oc && ./c " -*-
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
#define fr(i,n) for(int i=n;i--;)
#define fv(i,v) f(i,sz(v))

struct S{ int j,p,s; };

using X=vc<S>;

bool check(X& x,int k,int msk){
	int jp[4][4]={0};
	int ps[4][4]={0};
	int js[4][4]={0};
	int jps[4][4][4]={0};
	fv(i,x){
		if(!((msk>>i)&1)) continue;
		if(++jp[x[i].j][x[i].p]>k) return false;
		if(++ps[x[i].p][x[i].s]>k) return false;
		if(++js[x[i].j][x[i].s]>k) return false;
		if(++jps[x[i].j][x[i].p][x[i].s]>1) return false;
	}
	return true;
}


X gen(int j,int p,int s){
	X r;
	for(int a=1;a<=j;a++)
		for(int b=1;b<=p;b++)
			for(int c=1;c<=s;c++)
				r.pb({a,b,c});
	return r;
}

int bc(int x){
	int r=0;
	while(x){
		r+=x&1;
		x>>=1;
	}
	return r;
}


void solve(){
	int j,p,s,k;
	cin>>j>>p>>s>>k;
	X x=gen(j,p,s);
	int mxmsk=0,mx=0;
	fr(msk,1<<x.size()){
		int b=bc(msk);
		if(b<=mx) continue;
		if(!check(x,k,msk))
			continue;
		mx=b;
		mxmsk=msk;
	}
	X r;
	fv(i,x){
		if(!((mxmsk>>i)&1)) continue;
		r.pb(x[i]);
	}
	cout<<r.size()<<'\n';
	for(auto k:r)
		cout<<k.j<<" "<<k.p<<" "<<k.s<<"\n";
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
