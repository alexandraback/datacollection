#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>
#include<set>
#include<functional>
#include<algorithm>
#include<climits>
using namespace std;

#define mod %
#define NUM 1000000007

typedef long long int ll;



ll gcd(ll a,ll b){
	if(b == 0 or a == 0)
		return a+b;
	return gcd(b,a mod b);
}

ll balance(ll ans){
	if(ans >= NUM)
		return ans mod NUM;
	while(ans<0){
		ans+=NUM;
	}
	return ans;
}



void solve(){
	int r,c,w;
	cin>>r>>c>>w;
	int x = c/w;
	int ans = x;
	ans*=r;
	ans+=w;
	if(x*w ==c)
		ans--;
	cout<<ans;
}

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int TC;
	cin>>TC;
	for(int ZZ=1;ZZ<=TC;ZZ++){
		cout<<"Case #"<<ZZ<<": ";
		solve();
		cout<<endl;
	}
	return 0;
}
