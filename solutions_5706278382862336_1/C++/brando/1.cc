#include<iostream>
#include <assert.h>
#include <stdio.h>
using namespace std;
typedef long long int ll;
ll l(ll a,ll b){
	while(a>0&&b>0){
		if(a>b) {a=a%b;}
		else {b=b%a;}
	}
	return a==0?b:a;
}
void lcd(ll& a,ll& b){
	ll c=l(a,b);
	a/=c;b/=c;
	// cout<<a<<":"<<b<<endl;
	while(a%2==0&&b%2==0) {a/=2,b/=2;}
}
int dp(ll a,ll b){
	if(a>b||a<=0) return -1;
	else if(a==b) return 1;

	lcd(a,b);

	//test b
	ll test=1;
	for(int i=1;i<64;i++){
		test=(test<<1);
		// cout<<test<<" ";
		if(test>b) return -1;
		if(test==b) {break;}
	}
	
	int t=0;
	ll x=b;
	while(x!=a){
		// cout<<x<<":"<<a<<endl;
		assert(x>=a);
		int c=2*a-x;
		if(c<0) c=0;
		x=(x+c)/2;
		t++;
	}
	return t;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int ci=1;ci<=n;ci++){
		ll a,b;
		// cin>>a>>b;
		scanf("%lld/%lld",&a,&b);
		// cout<<a<<":"<<b<<endl;
		int num=-1;
		if(a>b||b<=0||a<=0);
		else{
			num=dp(a,b);
		}
		if(num>0)
			printf("Case #%d: %d\n",ci,num);
		else printf("Case #%d: impossible\n",ci);
	}
	return 0;
}
