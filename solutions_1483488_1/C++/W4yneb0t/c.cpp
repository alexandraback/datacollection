#include<iostream>
#include<cstdio>
#include<string>
#include<set>
using namespace std;
typedef long long ll;
ll a,b;
int dg;
set<ll> s;
ll pw[10];
ll st(ll a,int d){
	ll ip=a%pw[d];
	a/=pw[d];
	a+=ip*pw[dg-d];
	return a;
}
int main(){
	int t;
	cin>>t;
	ll ct;
	ll tp;
	pw[0]=1;
	for(int i=1;i<10;i++){
		pw[i]=pw[i-1]*10;
	}
	for(int z=1;z<=t;z++){
		cin>>a>>b;
		tp=a;
		dg=0;
		while(tp){
			dg++;
			tp/=10;
		}
		ct=0;
		for(ll i=a;i<=b;i++){
			s.clear();
			for(int k=1;k<dg;k++){
				tp=st(i,k);
				if(s.find(tp)==s.end() && tp>i && tp<=b)
					ct++;
				s.insert(tp);
			}
		}
		cout<<"Case #"<<z<<": "<<ct;
		cout<<endl;
	}
	return 0;
}
